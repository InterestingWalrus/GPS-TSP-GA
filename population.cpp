#include "population.h"
#include "utils.h"


Population::Population(std::vector<QGeoCoordinate> &wp, int num_drones):
    best_gene(wp, num_drones),
    population(MAX_POP, DNA(wp, num_drones)),
    matingPool(1000, DNA(wp, num_drones))
{
    waypoints =wp;
    number_of_drones = num_drones;

    mut_rate = 0.02;
    generations = 0;

    best_fitness = 0;

    GeneratePopulation();
    solve(100);
}

void Population::GeneratePopulation()
{
    for(std::size_t i = 0; i < MAX_POP; i++)
    {
        population.at(i) = DNA(waypoints, number_of_drones);
    }
}

void Population::solve(int iter)
{
    for (std::size_t i = 0; i < iter; i++)
    {
        computeFitness();
        normalize_fitness();
        evolve();
    }
}

void Population::evolve()
{
    std::vector<DNA> new_pop;

    for(std::size_t i = 0; i < population.size(); i++)
    {
        new_pop.push_back(DNA(waypoints, number_of_drones));
    }

    for(std::size_t i= 0; i < population.size(); i++)
    {
        DNA parentA = pickRandomParent(population);
        DNA parentB = pickRandomParent(population);
        DNA child = parentA.crossover(parentB);
        child.mutate(mut_rate);
        new_pop.at(i) = child;
    }
    population = new_pop;
    generations++;
}

DNA Population::pickRandomParent(std::vector<DNA> &pop)
{
    int index = 0;
    double r = getRandomDouble<double>(0, 1);
    while(r>0)
    {
        r = r - pop.at(index).getFitness();
        index++;
    }
    index--;
    return population.at(index);

}
void Population::normalize_fitness()
{
    float sum = 0;

    for(std::size_t i = 0; i < population.size(); i++)
    {
        sum+=population.at(i).getFitness();
    }

    for(std::size_t i = 0; i < population.size(); i++)
    {
        double fitness = population.at(i).getFitness();
        double norm_fit = fitness / sum;
        population.at(i).setFitness(norm_fit);
    }
}


void Population::computeFitness()
{
    for(std::size_t i = 0; i < population.size(); i++)
    {
        population.at(i).computeFitness();
        double fit = population.at(i).getFitness();
        if(fit > best_fitness)
        {
            best_fitness = fit;
            best_gene = population.at(i);
        }
    }
}

double Population::map(double sourcevalue, double startA, double stopA, double startB, double stopB)
{
    double output;
    output = startB + ((stopB - startB) / (stopA - startA)) * (sourcevalue - startA);
    return output;
}

