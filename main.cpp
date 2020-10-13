#include <QCoreApplication>
#include "gpsclass.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include <ctime>


#define NUM_GEN 100


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));


    GpsClass routeModel;
    int num_generations = 0;

    QGeoCoordinate start_point;
    start_point.setLatitude(52.755928);
    start_point.setLongitude( -1.245679);

    QGeoCoordinate point2;
    point2.setLatitude(52.766760);
    point2.setLongitude(-1.227367);

    QGeoCoordinate point3;
    point3.setLatitude(52.767208);
    point3.setLongitude(-1.229661);

    QGeoCoordinate point4;
    point4.setLatitude(52.768143);
    point4.setLongitude(-1.227322);

    QGeoCoordinate point5;
    point5.setLatitude(52.767550);
    point5.setLongitude(-1.232394);

    QGeoCoordinate point6;
    point6.setLatitude(52.768803);
    point6.setLongitude(-1.236213);

    QGeoCoordinate point7;
    point7.setLatitude(52.770926);
    point7.setLongitude(-1.235215);

    QGeoCoordinate point8;
    point8.setLatitude(52.772906);
    point8.setLongitude(-1.237865);

    QGeoCoordinate point9;
    point9.setLatitude(52.772315);
    point9.setLongitude(-1.243358);

    QGeoCoordinate point10;
    point10.setLatitude(52.772315);
    point10.setLongitude(-1.227367);

    QGeoCoordinate point11;
    point11.setLatitude(52.752315);
    point11.setLongitude(-1.257367);

    std::vector<QGeoCoordinate> waypoints;

    waypoints.push_back(start_point);
    waypoints.push_back(point2);
    waypoints.push_back(point3);
    waypoints.push_back(point4);
    waypoints.push_back(point5);
    waypoints.push_back(point6);
    waypoints.push_back(point7);
    waypoints.push_back(point8);
    waypoints.push_back(point9);
    waypoints.push_back(point10);
    waypoints.push_back(point11);
    waypoints.push_back(start_point);


    routeModel.initialiseGA(waypoints, 100);

    while(num_generations < NUM_GEN)
    {
        routeModel.computeFitness();

        routeModel.normalizeFitness();

        routeModel.nextGeneration();

        num_generations++;

    }


     return a.exec();
}
