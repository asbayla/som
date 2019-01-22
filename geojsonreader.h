#ifndef GEOJSONREADER_H
#define GEOJSONREADER_H

#include <QByteArray>
#include <QIODevice>
#include <QFile>
#include <QJsonDocument>

#include <QtDebug>

class GeoJsonReader
{
public:
    GeoJsonReader();

    QJsonDocument loadAndConvertToDocument(QString filePath);
    bool convertToVariantMap(QJsonDocument& doc, QVariantMap& result);
};

#endif // GEOJSONREADER_H
