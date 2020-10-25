#ifndef GPSCLASS_H
#define GPSCLASS_H

#include <QGeoCoordinate>
#include <vector>
#include <cmath>
#include <iostream>

#define PI (double) 3.141592653589793
#define C_EARTH (double)6378137.0


class GpsClass
{
public:
    GpsClass();
    double GetPathLength(QGeoCoordinate start_coord, QGeoCoordinate end_coord);
    double DegToRad(double degree);
    double RadToDeg(double rad);
    QGeoCoordinate GetDestinationCoordinate(QGeoCoordinate start_coord, double azimuth, double distance);
    double ComputeBearing(QGeoCoordinate start_point, QGeoCoordinate end_point);
    std::vector<QGeoCoordinate> returnInterpolatedPoints(int  distance, double bearing, QGeoCoordinate start, QGeoCoordinate end);
    std::vector<QGeoCoordinate> returnPositionsBasedOnLocations(int locations, double bearing, QGeoCoordinate start, QGeoCoordinate end);
    double GetRouteDistance(std::vector<QGeoCoordinate>&gps_list, std::vector<std::size_t>&order);
    double GetRouteDistance(std::vector<QGeoCoordinate>&gps_list);

private:
    std::vector<QGeoCoordinate> route;


};

#endif // GPSCLASS_H
