#include <iostream>
#include <fstream>
#include <stdio.h>
#include "config.hpp"

using namespace std;


parameters get_params(){
    ifstream param_file;
    parameters current_param;
    string line;
    string value;
    param_file.open("param.dat", ios::in);

    if(param_file.is_open()){
      cout<<"param.dat file found"<<endl;
    }else{
      cout<<"param.dat file not found"<<endl;
      exit(EXIT_FAILURE);
      return current_param;
    }
    while(param_file >>line>>value){
      cout<<line<<" "<<value<<endl;
      if(line =="L"){ current_param.L = stoi(value);}
      if(line =="Ntrials"){current_param.Ntrials= stoi(value);}
        if(line =="nT"){current_param.nT= stoi(value);}
        if(line =="Tmin"){current_param.Tmin= stod(value);}
        if(line =="Tmax"){current_param.Tmax= stod(value);}

        }
        
    return current_param;
}
