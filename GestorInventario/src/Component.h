#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>
#include <QJsonObject>

/**
 * @brief Clase que representa un componente del inventario.
 */
class Component {
public:
    Component() = default;
    Component(int id, const QString &name, const QString &type, int quantity,
              const QString &location, const QString &purchaseDate);

    // Getters
    int id() const;
    QString name() const;
    QString type() const;
    int quantity() const;
    QString location() const;
    QString purchaseDate() const;

    // Setters
    void setId(int id);
    void setName(const QString &name);
    void setType(const QString &type);
    void setQuantity(int q);
    void setLocation(const QString &loc);
    void setPurchaseDate(const QString &date);

    // Serialización simple para export
    QJsonObject toJson() const;

private:
    int m_id = -1;
    QString m_name;
    QString m_type;
    int m_quantity = 0;
    QString m_location;
    QString m_purchaseDate;
};

#endif // COMPONENT_H
