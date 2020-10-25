#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <random>

std::default_random_engine& randomEngine();


template <typename T>
T getRandomInt(T first, T second)
{
    std::uniform_int_distribution<T> uniform_dist(first, second);
    return uniform_dist(randomEngine());
}


template <typename T>
T getRandomDouble(T first, T second)
{
    std::uniform_real_distribution<T> uniform_dist(first, second);
    return uniform_dist(randomEngine());
}


template <typename T>
std::vector<T> flatten(const std::vector<std::vector<T>>& v)
{
    std::size_t total_size =0;
    for(const auto &sub :v)
    {
        total_size+=sub.size();
    }
    std::vector<T> result;
    result.reserve(total_size);
    for(const auto& sub: v)
    {
        result.insert(result.end(), sub.begin(), sub.end());
    }
    return result;
}
// generate a random Index

#endif // UTILS_H
