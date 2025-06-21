#include "Combined_pairs2.h"
#include "link.h"
#include "Motors.h"
#include "gear_box.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

double input_omegareq ()
{
    double O_req;
    cout<<"Enter the omega required (rpm): ";
    cin>>O_req;
    return O_req;
}


void calcProperties(vector <Motors> &v_m , vector<gear_box>&v_gears ,
                     vector <Combined_pairs2> &my_pairs, double bending_m ,double O_req )
{
    double O_out;
    double T_out;

    for(int i=0; i<v_m.size(); i++)
    {
        for (int j=0; j<v_gears.size(); j++)
        {
                       T_out = v_m[i].M_torque * v_gears[j].gear_ratio * v_gears[j].efficiency;
                       O_out= v_m[i].M_omega / v_gears[j].gear_ratio;

                       if (T_out >= bending_m && O_out >= O_req)
                            {
                                Combined_pairs2 C; //(v_m[i].M_torque,v_m[i].M_omega, v_gears[j].gear_ratio,v_gears[j].efficiency , bending_m, O_req);
                                C.T_out = T_out;
                                C.O_out = O_out;
                                C.C_mass= v_m[i].M_mass + v_gears[j].gear_mass;
                                C.C_diameter= v_m[i].M_diameter + v_gears[j].gear_diameter;
                                C.C_name= "Motor:"+ v_m [i].M_model + " & "+ "Gearbox:" + v_gears[j].gearbox_model;
                                my_pairs.push_back(C);
                            }

        }

    }
}


void cost_calc (vector<Combined_pairs2> &v_c)
{
  //cost optimization priority
  char pri;
    cout<<endl<<"To find the most suitable motor-gearbox combination, please choose cost optimization priority \n (m for mass/d for diameter):"<<endl;

    while(true)
    {
        cin >> pri;
        if(pri == 'd' || pri == 'm')
        {
            break;
        }
        else if (cin.fail() || (pri!='m'&&pri!='d'))
        {
            cout << "Invalid Input! Please re-enter optimization priority";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    if (pri=='m')  //cost=total mass of combination
    {
       for (int i=0; i<v_c.size(); i++)
       {
         v_c[i].C_cost=v_c[i].C_mass;
       }

    }
    if (pri=='d')
    {
        for(int j=0; j<v_c.size(); j++)
        {
          v_c[j].C_cost=(v_c[j].C_diameter)/100.0;
        }
    }
}

Combined_pairs2 :: Combined_pairs2(){}
