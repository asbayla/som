#ifndef PSQLQUERYBUILDER_H
#define PSQLQUERYBUILDER_H

#include <QString>

class PsqlQueryBuilder
{
public:
    PsqlQueryBuilder();

    QString buildGeoson();
};

#endif // PSQLQUERYBUILDER_H
