#ifndef GEOJSONDBADAPTER_H
#define GEOJSONDBADAPTER_H

#include <QString>
#include <QSqlError>

class GeoJsonDbAdapter
{
public:
    GeoJsonDbAdapter();

    QSqlError connect(const QString &driver, const QString &dbName, const QString &host,
                      const QString &user, const QString &passwd, int port);
    bool selectAllObservations();
};

#endif // GEOJSONDBADAPTER_H
