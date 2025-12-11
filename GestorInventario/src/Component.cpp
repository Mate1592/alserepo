#include "Component.h"

Component::Component(int id, const QString &name, const QString &type, int quantity,
                     const QString &location, const QString &purchaseDate, double price)
    : m_id(id), m_name(name), m_type(type), m_quantity(quantity),
      m_location(location), m_purchaseDate(purchaseDate), m_price(price)
{
}

int Component::id() const { return m_id; }
QString Component::name() const { return m_name; }
QString Component::type() const { return m_type; }
int Component::quantity() const { return m_quantity; }
QString Component::location() const { return m_location; }
QString Component::purchaseDate() const { return m_purchaseDate; }
double Component::price() const { return m_price; }

void Component::setId(int id) { m_id = id; }
void Component::setName(const QString &name) { m_name = name; }
void Component::setType(const QString &type) { m_type = type; }
void Component::setQuantity(int q) { m_quantity = q; }
void Component::setLocation(const QString &loc) { m_location = loc; }
void Component::setPurchaseDate(const QString &date) { m_purchaseDate = date; }
void Component::setPrice(double p) { m_price = p; }

QJsonObject Component::toJson() const {
    QJsonObject obj;
    obj["id"] = m_id;
    obj["name"] = m_name;
    obj["type"] = m_type;
    obj["quantity"] = m_quantity;
    obj["location"] = m_location;
    obj["purchase_date"] = m_purchaseDate;
    obj["price"] = m_price;
    return obj;
}
