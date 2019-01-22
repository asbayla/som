#include "geojsonreader.h"

#include <QJsonObject>

GeoJsonReader::GeoJsonReader()
{
}

QJsonDocument GeoJsonReader::loadAndConvertToDocument(QString filePath)
{
    QFile fileObj(filePath);
    if (!fileObj.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open: " << filePath;
        exit(1);
    }

    QTextStream fileText(&fileObj);
    QString jsonStr;
    jsonStr = fileObj.readAll();
    fileObj.close();
    QByteArray jsonBytes = jsonStr.toLocal8Bit();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonBytes);

    if(jsonDoc.isNull()){
        qDebug()<<"Failed to create JSON doc.";
        exit(2);
    }
    if(!jsonDoc.isObject()){
        qDebug()<<"JSON is not an object.";
        exit(3);
    }

    return jsonDoc;
}

bool GeoJsonReader::convertToVariantMap(QJsonDocument& doc, QVariantMap& result)
{
    if (doc.isNull())
    {
       return false;
    }

    QJsonObject jsonObj = doc.object();

   if (jsonObj.isEmpty())
   {
       return false;
   }

   result = jsonObj.toVariantMap();
   return true;
}
