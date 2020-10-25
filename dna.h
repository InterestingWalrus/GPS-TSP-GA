#ifndef DNA_H
#define DNA_H

#include <vector>
#include <QGeoCoordinate>
#include <cmath>
#include <iostream>
#include <random>
#include <algorithm>
#include "gpsclass.h"

class DNA
{
public:
    DNA(std::vector<QGeoCoordinate>& waypoints, int num_of_drones);
    DNA();
    DNA(std::vector<std::size_t> &order, std::vector<QGeoCoordinate>& waypoints, int num_of_drones);
    DNA crossover(DNA &parentB);
    void mutate(float mutationRate);
    void computeFitness();
    void splitWaypoints(size_t n);
    std::vector<std::size_t> const &getOrder() const;
    std::vector<std::vector<std::size_t>>& getSolution();
    double getFitness();
    void setFitness(double fitness_);
    void setWaypoints(std::vector<QGeoCoordinate>& waypoints);
    void setNumDrones(int number_of_drones);
    void swap(std::vector<std::size_t>&route, int i, int j);


private:
    GpsClass routeModel;
    std::vector<std::size_t> order; // list of vertices
    std::vector<std::vector<QGeoCoordinate>> route;
    std::vector<QGeoCoordinate> waypoints;
    std::vector<std::vector<std::size_t>> solution;
    double fitness;
    size_t number_of_drones;
    double record_distance;
    std::vector<std::vector<std::size_t>>bestOrder;
    std::size_t number_of_cities;


};


#endif // DNA

