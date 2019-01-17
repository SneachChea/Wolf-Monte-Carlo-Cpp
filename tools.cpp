
#include "tools.hpp"



d_vector linspace(double min, double max, int nbr, bool endpoint)
{
    d_vector d;
    if(nbr==1){
        d.push_back(min);
        return d;
    }
    if(min==max){
        d.push_back(max);
        return d;
    }
    d.reserve(nbr);
    if(endpoint==false){
    for(int i=0; i<nbr; i++){
        d.push_back(min +i*(max-min)/double(nbr));
    }
    }else{
    for(int i=0; i<nbr; i++){
        d.push_back(min +i*(max-min)/double(nbr-1));
    }   
    }
    return d;
}


void initLattice(std::vector<int> &S)
{   
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dis(0, 1);
    for(auto & i : S)
    {
        i = dis(gen)*2-1;
    }
}