//#include "drone.h"

//Drone::Drone(int size):
//    fitness(4),
//    order(4)
//{
//    fitness.resize(size);
//    order.resize(size);

//    // generate random genes
//    for(int i = 0; i < order.size(); i++)
//    {

//    }


//}

//void Drone::computeFitness()
//{

//}

//std::vector<int> Drone::crossover(std::vector<int> &parentA, std::vector<int> &parentB)
//{
//    // pick a random number from 1 and omit the last element
//    // in the array
//    int start = rand () % (parentA.size()-2) + 1 ;
//    // pick a random number from "start" and omit the last
//    // element in the array
//    int end = start + 1 + rand() % ((parentA.size()-2) - start +1);

//    //create a new vector based from the parent with index (start, end)
//    std::vector<int>::const_iterator first = parentA.begin() + start;
//    std::vector<int>::const_iterator second = parentA.begin() + end;
//    std::vector<int> newOrder(first, second);

//    // Add remaining chromosomes from parentB. Check to see if they
//    // are missing from ParentA first
//    for(std::size_t i = 1; i <= parentB.size()-2; i++)
//    {
//        int city = parentB.at(i);
//        if(std::find(newOrder.begin(), newOrder.end(), city) == newOrder.end())
//        {
//            //std::cout<< "Move on" <<std::endl;
//            newOrder.push_back(city);
//        }
//    }
//    return newOrder;

//}


//void Drone::mutate(float mutationRate)
//{

//    for(std::size_t i = 0; i < order.size(); i++)
//    {
//       double r = ((double) rand() / (RAND_MAX));
//       if(r < mutationRate)
//       {
//           // omit the first and last indexes to preserve the
//           // circular requirement of home and finishing
//           // positions
//           int indexA = rand() % (order.size()-2) + 1;
//           order.at(i) = indexA;
//       }
//    }

//}
