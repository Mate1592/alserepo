#include "ReportGenerator.h"
#include <QFile>
#include <QTextStream>

bool ReportGenerator::exportCsv(const QString &filePath, const QList<Component> &list) {
    QFile f(filePath);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) return false;

    QTextStream out(&f);
    // Header
    out << "id,name,type,quantity,price,location,purchase_date\n";
    for (const Component &c : list) {
        // Sanitize commas if needed
        QString name = c.name(); // In real app, escape commas
        QString type = c.type();
        QString loc = c.location();
        out << QString::number(c.id()) << "," << name << "," << type << ","
            << QString::number(c.quantity()) << "," << QString::number(c.price(), 'f', 2) << ","
            << loc << "," << c.purchaseDate() << "\n";
    }
    f.close();
    return true;
}
