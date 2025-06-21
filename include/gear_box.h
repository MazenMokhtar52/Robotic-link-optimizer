#ifndef GEAR_BOX_H
#define GEAR_BOX_H
#include<string>
#include<vector>

class gear_box
{

public:

    gear_box (double gear_ratio, double efficiency,double gear_mass,double gear_diameter);
    std::string gearbox_model=" ";
    double gear_ratio=0.00;
    double efficiency=0.00;
    double gear_mass=0.00;
    double gear_diameter=0.00;

//    void display_data();

     gear_box(){}; //default constructor
};
//global function for storing the input data as a vector

void gear_input(std::vector<gear_box>&v_gears);
#endif // GEAR_BOX_H
