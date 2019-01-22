#include "psqlquerybuilder.h"

PsqlQueryBuilder::PsqlQueryBuilder()
{
}

QString buildGeoJson()
{
   return QString("SELECT jsonb_build_object(      \
                  'type',     'FeatureCollection', \
                  'features', jsonb_agg(feature)   \
              )  \
              FROM ( \
                SELECT jsonb_build_object( \
                  'type',       'Feature', \
                  'id',         gid, \
                  'geometry',   ST_AsGeoJSON(geom)::jsonb, \
                  'properties', to_jsonb(row) - 'gid' - 'geom' \
                ) AS feature \
                FROM (SELECT * FROM input_table) row) features;");
}

/*
SELECT jsonb_build_object(
  'type',     'FeatureCollection',
  'features', jsonb_agg(feature)
)
FROM (
  SELECT jsonb_build_object(
    'type',       'Feature',
    'id',         gid,
    'geometry',   ST_AsGeoJSON(geom)::jsonb,
    'properties', to_jsonb(inputs) - 'gid' - 'geom'
  ) AS feature
  FROM (
    SELECT * FROM input_table
  ) inputs
) features;
*/
