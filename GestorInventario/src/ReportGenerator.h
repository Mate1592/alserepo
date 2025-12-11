#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <QString>
#include <QList>
#include "Component.h"

/**
 * @brief Clase simple para generar reportes (CSV por ahora).
 */
class ReportGenerator {
public:
    static bool exportCsv(const QString &filePath, const QList<Component> &list);
};

#endif // REPORTGENERATOR_H
