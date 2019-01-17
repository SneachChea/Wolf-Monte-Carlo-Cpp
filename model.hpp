
#ifndef model_hpp
#define model_hpp



#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <tuple>
#include <map>
#include <assert.h>


class model{
    public:
    model(int _L, int _Ntrials){
        this->L = _L;
        this-> N = _L*_L;
        this-> N_trials = _Ntrials;
        x_y_dic.reserve(N);
        nbr.reserve(N);
        init();
    }
    void init();
    void print_nbr(int i){std::cout<<std::get<0>(nbr[i])<<"    "<<std::get<1>(nbr[i])<<"    "<<std::get<2>(nbr[i])<<"    "<<std::get<3>(nbr[i])<<std::endl;}
    int get_L(){return L;}
    int get_N(){return N;}
    int get_Ntrials(){return N_trials;}
    int get_nbr(const int i, const int number);
    private:
        int L;
        int N;
        int N_trials;
        std::map<std::tuple<int, int>, int> site_dic;
        std::vector<std::tuple<int, int>> x_y_dic;
        std::vector<std::tuple<int,int,int,int>> nbr;
};


#endif

