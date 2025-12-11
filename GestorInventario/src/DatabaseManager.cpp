#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent) {}

DatabaseManager::~DatabaseManager() {
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DatabaseManager::openDatabase(const QString &filePath) {
    if (QSqlDatabase::contains("gestor_connection"))
        m_db = QSqlDatabase::database("gestor_connection");
    else
        m_db = QSqlDatabase::addDatabase("QSQLITE", "gestor_connection");

    m_db.setDatabaseName(filePath);
    if (!m_db.open()) {
        emit errorOccurred(m_db.lastError().text());
        return false;
    }
    return true;
}

bool DatabaseManager::initSchema() {
    QSqlQuery q(m_db);
    // Create table with price column
    const QString create = R"(
     CREATE TABLE IF NOT EXISTS components (
     id INTEGER PRIMARY KEY AUTOINCREMENT,
     name TEXT NOT NULL,
     type TEXT,
     quantity INTEGER DEFAULT 0,
     location TEXT,
     purchase_date TEXT,
     price REAL DEFAULT 0.0
     )
    )";
    if (!q.exec(create)) {
        emit errorOccurred(q.lastError().text());
        return false;
    }

    // Migration attempt: check if 'price' column exists, if not, add it.
    // This handles the case where the user re-uses an old DB.
    // PRAGMA table_info returns rows where 'name' is the column name.
    if (q.exec("PRAGMA table_info(components)")) {
        bool hasPrice = false;
        while (q.next()) {
            if (q.value("name").toString() == "price") {
                hasPrice = true;
                break;
            }
        }

        if (!hasPrice) {
            QSqlQuery alterQ(m_db);
            if (!alterQ.exec("ALTER TABLE components ADD COLUMN price REAL DEFAULT 0.0")) {
                 // Not critical error, but worth logging or emitting
                 qDebug() << "Migration failed:" << alterQ.lastError().text();
            }
        }
    }

    return true;
}

bool DatabaseManager::insertComponent(const Component &c) {
    QSqlQuery q(m_db);
    q.prepare("INSERT INTO components (name, type, quantity, location, purchase_date, price) VALUES (:name, :type, :quantity, :location, :pd, :price)");
    q.bindValue(":name", c.name());
    q.bindValue(":type", c.type());
    q.bindValue(":quantity", c.quantity());
    q.bindValue(":location", c.location());
    q.bindValue(":pd", c.purchaseDate());
    q.bindValue(":price", c.price());
    if (!q.exec()) {
        emit errorOccurred(q.lastError().text());
        return false;
    }
    return true;
}

bool DatabaseManager::updateComponent(const Component &c) {
    QSqlQuery q(m_db);
    q.prepare("UPDATE components SET name=:name, type=:type, quantity=:quantity, location=:location, purchase_date=:pd, price=:price WHERE id=:id");
    q.bindValue(":name", c.name());
    q.bindValue(":type", c.type());
    q.bindValue(":quantity", c.quantity());
    q.bindValue(":location", c.location());
    q.bindValue(":pd", c.purchaseDate());
    q.bindValue(":price", c.price());
    q.bindValue(":id", c.id());
    if (!q.exec()) {
        emit errorOccurred(q.lastError().text());
        return false;
    }
    return true;
}

bool DatabaseManager::deleteComponent(int id) {
    QSqlQuery q(m_db);
    q.prepare("DELETE FROM components WHERE id=:id");
    q.bindValue(":id", id);
    if (!q.exec()) {
        emit errorOccurred(q.lastError().text());
        return false;
    }
    return true;
}

bool DatabaseManager::fetchAll(QList<Component> &outList) {
    QSqlQuery q(m_db);
    if (!q.exec("SELECT id, name, type, quantity, location, purchase_date, price FROM components ORDER BY id ASC")) {
        emit errorOccurred(q.lastError().text());
        return false;
    }
    outList.clear();
    while (q.next()) {
        Component c;
        c.setId(q.value(0).toInt());
        c.setName(q.value(1).toString());
        c.setType(q.value(2).toString());
        c.setQuantity(q.value(3).toInt());
        c.setLocation(q.value(4).toString());
        c.setPurchaseDate(q.value(5).toString());
        c.setPrice(q.value(6).toDouble());
        outList.append(c);
    }
    return true;
}
