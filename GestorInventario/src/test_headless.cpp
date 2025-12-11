#include <QCoreApplication>
#include <QDebug>
#include <cassert>
#include <QFile>
#include "DatabaseManager.h"
#include "ReportGenerator.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    // Clean up old test db
    QFile::remove("test_inventory.db");

    DatabaseManager db;
    // Use a test database
    if (db.openDatabase("test_inventory.db")) {
        qDebug() << "Database opened successfully";
    } else {
        qCritical() << "Failed to open database";
        return 1;
    }

    if (db.initSchema()) {
        qDebug() << "Schema initialized";
    } else {
        qCritical() << "Failed to init schema";
        return 1;
    }

    // Insert component with price
    Component c1(-1, "Resistor 10k", "Passive", 100, "Drawer 1", "2023-10-01", 0.10);
    if (db.insertComponent(c1)) {
        qDebug() << "Inserted component 1";
    } else {
        qCritical() << "Failed to insert component";
        return 1;
    }

    Component c2(-1, "LED Red", "Diode", 50, "Drawer 2", "2023-10-02", 0.05);
    if (db.insertComponent(c2)) {
        qDebug() << "Inserted component 2";
    }

    // --- Test Sales Logic ---
    // 1. Sell 10 Resistors (ID likely 1)
    // Need to find ID first to be robust
    QList<Component> initialList;
    db.fetchAll(initialList);
    int id1 = initialList[0].id();

    if (db.registerSale(id1, 10)) {
        qDebug() << "Sale registered successfully";
    } else {
        qCritical() << "Failed to register sale";
        return 1;
    }

    // 2. Verify stock reduction
    QList<Component> afterSaleList;
    db.fetchAll(afterSaleList);
    if (afterSaleList[0].quantity() != 90) { // 100 - 10
        qCritical() << "Stock did not update correctly. Expected 90, got" << afterSaleList[0].quantity();
        return 1;
    }

    // 3. Verify insufficient stock error
    if (db.registerSale(id1, 1000)) {
        qCritical() << "Should have failed due to insufficient stock";
        return 1;
    } else {
        qDebug() << "Insufficient stock handled correctly";
    }

    // Export CSV
    if (ReportGenerator::exportCsv("test_inventory.csv", afterSaleList)) {
        qDebug() << "Exported CSV";
    } else {
        qCritical() << "Failed to export CSV";
        return 1;
    }

    qDebug() << "All tests passed";
    return 0;
}
