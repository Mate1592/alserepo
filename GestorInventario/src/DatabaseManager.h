#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QVariantList>
#include "Component.h"

/**
 * @brief Clase que encapsula la interacción con la base de datos SQLite.
 *
 * Utiliza QSqlDatabase (Qt SQL) y provee métodos para iniciar la BD,
 * insertar, actualizar, eliminar y leer componentes.
 */
class DatabaseManager : public QObject {
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

    bool openDatabase(const QString &filePath);
    bool initSchema();
    bool insertComponent(const Component &c);
    bool updateComponent(const Component &c);
    bool deleteComponent(int id);

    // Devuelve true si la operación fue exitosa y llena outList con los componentes
    bool fetchAll(QList<Component> &outList);

    QSqlDatabase database() const { return m_db; }

signals:
    void errorOccurred(const QString &msg);

private:
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
