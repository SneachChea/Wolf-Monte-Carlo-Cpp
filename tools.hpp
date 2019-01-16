
#ifndef tools_hpp
#define tools_hpp



#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <complex>
#include <vector>
#include <assert.h>
#include <random>

using d_vector = std::vector<double>;


d_vector linspace(double min, double max, int nbr, bool endpoint=false);

template <typename T>
T randomChoice(std::vector<T> const vec){
    assert(vec.size() != 0);
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(0, vec.size()-1);
    return vec[dis(gen)];
}

#endif

