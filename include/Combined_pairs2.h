#ifndef COMBINED_PAIRS2_H
#define COMBINED_PAIRS2_H
#include "Motors.h"
#include "link.h"
#include "gear_box.h"
#include <string>

using namespace std;

class Combined_pairs2
{
    public:
        Combined_pairs2();
        string C_name;
       double   T_out=0.0,
                O_out=0.0,
                C_diameter, //total diameters of motor and gearbox
                C_mass,     //total mass of motor and gearbox
                C_cost;     //Cost



};

       void calcProperties(vector <Motors> &v_m , vector<gear_box>&v_gears ,
                            vector <Combined_pairs2> &my_pairs, double bending_m, double O_req );
       double input_omegareq ();

       void cost_calc (vector<Combined_pairs2> &v_c);

        /*
        void cost_optimization()
        {
            double Cost = (gear_mass + M_mass) + (gear_diameter + M_diameter)/100 + (gear_width + M_width)/100;
            //minimization logic
        }

        */

#endif
