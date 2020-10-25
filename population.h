#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <memory>
#include "dna.h"

#define MAX_POP 100

class Population
{
private:
    std::vector<DNA> population;
    std::vector<QGeoCoordinate> waypoints;
    std::vector<DNA> matingPool;
    std::size_t number_of_drones;
    int generations;
    DNA best_gene;
    double best_fitness;
    int pop_size;
    float mut_rate;
public:
    Population(std::vector<QGeoCoordinate> &wp, int num_drones);
    DNA pickRandomParent(std::vector<DNA> &population);
    void solve(int num_iter);
    void evolve();
    void GeneratePopulation();
    void selection();
    void computeFitness();
    void normalize_fitness();
   // void returnResult();

    double map(double sourcevalue, double startA, double stopA, double startB, double stopB );
    double getMaxFitness();

};

#endif // POPULATION_H
