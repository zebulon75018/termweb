#include "templateEngineQt.h"

#include <inja/inja.hpp>
#include <nlohmann/json.hpp>
#include <QStringList>
#include <QVariant>
#include <QVariantMap>
#include <QDebug>
#include <QFile>

using json = nlohmann::json;

static json QVariantToJson(const QVariant& var) {
    switch (var.type()) {
    case QMetaType::QString:
        return var.toString().toStdString();
    case QMetaType::Int:
    case QMetaType::UInt:
        return var.toInt();
    case QMetaType::Double:
        return var.toDouble();
    case QMetaType::Bool:
        return var.toBool();
    case QMetaType::QStringList: {
        json arr = json::array();
        for (const QString& str : var.toStringList()) {
            arr.push_back(str.toStdString());
        }
        return arr;
    }
    case QMetaType::QVariantList: {
        json arr = json::array();
        for (const QVariant& item : var.toList()) {
            arr.push_back(QVariantToJson(item));
        }
        return arr;
    }
    case QMetaType::QVariantMap: {
        json obj;
        for (auto it = var.toMap().cbegin(); it != var.toMap().cend(); ++it) {
            obj[it.key().toStdString()] = QVariantToJson(it.value());
        }
        return obj;
    }
    default:
        return var.toString().toStdString(); // fallback
    }
}

QString TemplateEngineQt::render(const QString& templateText, const QVariantMap& data)
{
    inja::Environment env;
    json jdata;

    for (auto it = data.cbegin(); it != data.cend(); ++it) {
        jdata[it.key().toStdString()] = QVariantToJson(it.value());
    }

    std::string output = env.render(templateText.toStdString(), jdata);
    return QString::fromStdString(output);
}


QString TemplateEngineQt::renderFile(const QString& filename, const QVariantMap& data)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "TemplateEngineQt: Could not open file" << filename;
        return QStringLiteral("[Template error: file not found]");
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    return render(content, data);
}

