#ifndef TEMPLATEENGINEQT_H
#define TEMPLATEENGINEQT_H

#include <QString>
#include <QVariant>
#include <QVariantMap>

class TemplateEngineQt
{
public:
    // Rend un template avec des données de type QVariantMap
    static QString render(const QString& templateText, const QVariantMap& data);
    static QString renderFile(const QString& filename, const QVariantMap& data);

};

#endif // TEMPLATEENGINEQT_H

