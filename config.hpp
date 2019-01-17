//
//  config.hpp
//  Eneg_kin
//
//  Created by Shaheen Acheche on 06/12/2016.
//  Copyright © 2016 Shaheen Acheche. All rights reserved.
//

#ifndef config_hpp
#define config_hpp

#include <stdio.h>



struct parameters
{
    int L;
    int Ntrials;
    int nT;
    double Tmin;
    double Tmax;
};

parameters get_params();


#endif /* config_hpp */
