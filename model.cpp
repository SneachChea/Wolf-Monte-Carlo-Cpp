#include "model.hpp"

void model::init(){
    int row;
    int column;
    int up, right, left, dn;
    for(unsigned int i =0;i<N;i++){
        row = int(i/L);
        column = i-row*L;
        site_dic[std::make_tuple(row, column)]= i;
        x_y_dic[i] = std::make_tuple(row, column);
    }
    for(unsigned int i = 0; i<N;i++){
        row = std::get<0>(x_y_dic[i]);
        column = std::get<1>(x_y_dic[i]);
        up = site_dic[std::make_tuple((row-1+L)%L, column)];
        right = site_dic[std::make_tuple(row, (column+1)%L)];
        dn = site_dic[std::make_tuple((row+1)%L, column)];
        left = site_dic[std::make_tuple(row, (column-1+L)%L)];
        nbr[i] = std::make_tuple(right, up, left,dn);
    }
}

int model::get_nbr(const int i, const int number)
{
    switch(number)
    {
        case 0:
            return std::get<0>(nbr[i]);
        case 1:
            return std::get<1>(nbr[i]);
        case 2:
            return std::get<2>(nbr[i]);
        case 3:
            return std::get<3>(nbr[i]);
    }
}
