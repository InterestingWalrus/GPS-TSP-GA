#ifndef GPSCLASS_H
#define GPSCLASS_H

#include <QGeoCoordinate>
#include <vector>
#include <cmath>
#include <iostream>
#include <random>
#define PI (double) 3.141592653589793
#define C_EARTH (double)6378137.0


/// Class to handle Waypoint Optimisation and Route generation for GPS Waypoints.
///
/// Class contains helper functions for GPS coordinate manipulation and code required to
/// implement a genetic algorithm to solve the Travelling Salesman Problem. This is based on
/// the solution presented by Daniel Shiffman in the Nature of Code Series on TSP as seen on
/// https://thecodingtrain.com/CodingChallenges/035.1-tsp.html
class GpsClass
{
public:
    GpsClass() = default;
    double GetPathLength(QGeoCoordinate start_coord, QGeoCoordinate end_coord);
    double DegToRad(double degree);
    double RadToDeg(double rad);
    QGeoCoordinate GetDestinationCoordinate(QGeoCoordinate start_coord, double azimuth, double distance);
    double ComputeBearing(QGeoCoordinate start_point, QGeoCoordinate end_point);
    std::vector<QGeoCoordinate> returnInterpolatedPoints(int  distance, double bearing, QGeoCoordinate start, QGeoCoordinate end);
    std::vector<QGeoCoordinate> returnPositionsBasedOnLocations(int locations, double bearing, QGeoCoordinate start, QGeoCoordinate end);
    void swap(std::vector<QGeoCoordinate>&gps_list, int i, int j);
    void swap(std::vector<int>&route, int i, int j);
    void shuffle(std::vector<int>&route);
    double GetRouteDistance(std::vector<QGeoCoordinate>&gps_list);
    double GetRouteDistance(std::vector<QGeoCoordinate>&gps_list, std::vector<int>&order);
    void normalizeFitness();
    void computeFitness();
    void nextGeneration();
    void initialiseGA(std::vector<QGeoCoordinate>& waypoints, int MAX_POP);
    std::vector<int> pickRandomParent(std::vector<std::vector<int>>& population, std::vector<float>& fitness);
    void mutate(std::vector<int> &order, float mutationRate);
    std::vector<int> crossover(std::vector<int> &parentA, std::vector<int> &parentB);

private:
    std::vector<QGeoCoordinate> route;
    std::vector<QGeoCoordinate> waypoints;
    std::vector<float> fitness;
    double recordDistance;
    std::vector<int>bestOrder;
    std::vector<int>currentBestOrder;
    std::vector<int> order;
    std::vector<std::vector<int>> population;
};

#endif // GPSCLASS_H
