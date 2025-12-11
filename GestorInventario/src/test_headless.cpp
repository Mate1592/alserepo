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

    // Fetch all
    QList<Component> list;
    if (db.fetchAll(list)) {
        qDebug() << "Fetched" << list.size() << "components";
        if (list.size() != 2) return 1;
        if (list[0].name() != "Resistor 10k") return 1;
        if (list[0].price() != 0.10) {
            qCritical() << "Price mismatch:" << list[0].price();
            return 1;
        }
    } else {
        qCritical() << "Failed to fetch components";
        return 1;
    }

    // Export CSV
    if (ReportGenerator::exportCsv("test_inventory.csv", list)) {
        qDebug() << "Exported CSV";
    } else {
        qCritical() << "Failed to export CSV";
        return 1;
    }

    qDebug() << "All tests passed";
    return 0;
}
