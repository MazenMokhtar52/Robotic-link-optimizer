#ifndef MOTORS_H
#define MOTORS_H
#include <vector>
#include <string>

using namespace std;
class Motors //creating a new data type - Motors
{
  public:
    //defining motor attributes

    string  M_model;
    double  M_torque,
            M_omega,
            M_mass,
            M_diameter;


    Motors(){}; //default constructor
    Motors(double M_torque, double M_omega);
    Motors(string n, double t, double o, double m , double dia);
};
//global function using vector of motors

void input_mlist (vector <Motors> &v_m); //motor list input function
void use_def_m(vector <Motors> &v_m); //inserting default in motor vector
void def_display(); // print default motor list
#endif
