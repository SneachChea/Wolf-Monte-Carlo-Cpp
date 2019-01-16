//
//  main.cpp
//  Transport
//
//  Created by Shaheen Acheche on 29/09/2017.
//  Copyright © 2017 Shaheen Acheche. All rights reserved.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <complex>
#include <vector>
#include <random>
#include <algorithm>
#include "model.hpp"
#include "tools.hpp"


int main(int argc, const char * argv[]) {
    model mod(4, 100);
    d_vector test = linspace(0, 1, 2, true);
    d_vector T_num = linspace(0.1, 10, 10, true);
    
    for(size_t i = 0; i<T_num.size();i++)
    {
        std::cout<<"Temperature ="<<T_num[i]<<std::endl;
        


    }


    std::cout<<"Done !"<<std::endl;

    return 0;
} 
