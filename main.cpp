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
#include <tuple>
#include <random>

#include "model.hpp"
#include "tools.hpp"
#include "config.hpp"


using i_vector = std::vector<int>;


int main(int argc, const char * argv[]) {
    const parameters params = get_params();
    model mod(params.L, params.Ntrials);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, mod.get_N()-1);
    std::uniform_real_distribution<> dis_real(0, 1);

    d_vector magnetization(mod.get_Ntrials());
    d_vector tNum = linspace(params.Tmin, params.Tmax, params.nT, true);
    d_vector meanMag(tNum.size());
    i_vector pocket, cluster;
    i_vector S(mod.get_N());
    double beta;
    double p;
    int k, s;
    std::ofstream txt;
    txt.open("magnetization.dat");

    for(size_t i = 0; i<tNum.size();i++)
    {
        std::cout<<"Temperature ="<<tNum[i]<<std::endl;
        beta = 1./tNum[i];
        p = 1.- std::exp(-2*beta);
        initLattice(S);
        for(size_t j = 0; j<mod.get_Ntrials();j++)
        {
            k = dis(gen);
            pocket.push_back(k);
            cluster.push_back(k);
            while(pocket.size()!=0)
            {
                s = randomChoice(pocket);
                for(int k =0; k<4;k++)
                {
                    if(S[mod.get_nbr(s, k)]==S[s])
                    {
                        if(!isInVector(cluster,mod.get_nbr(s, k)))
                        {
                            if(dis_real(gen)<p)
                            {
                                pocket.push_back(mod.get_nbr(s, k));
                                cluster.push_back(mod.get_nbr(s, k));
                            }
                        }
                    }
                }
                pocket.erase(std::remove(pocket.begin(), pocket.end(), s), pocket.end());
            }
            for(size_t l=0; l<cluster.size();l++)
            {
                S[cluster[l]] = -S[cluster[l]];
            }
            cluster.resize(0);
            magnetization[j] = std::abs(std::accumulate(S.begin(), S.end(), 0.0));
        } 
        meanMag[i] = std::accumulate(magnetization.begin(), magnetization.end(), 0)/(1.*mod.get_Ntrials()*mod.get_N());
    }
     // */
    for(size_t i =0; i<tNum.size();i++)
    {
        txt<<tNum[i]<<"\t"<<meanMag[i]<<std::endl;
    }
    txt.close();
    std::cout<<"Done !"<<std::endl;

    return 0;
} 
