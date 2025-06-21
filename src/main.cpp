#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include "link.h"
#include "Materials.h"
#include "Motors.h"
#include "gear_box.h"
#include "Combined_pairs2.h"

using namespace std;

int main()
{
    //Part 1

    link link1;
    link1.input_data();
    Materials m;
    m.displayTable();

    link1.density=m.selected_density; //passes the material prop. to link class
    link1.y_stress=m.selected_y_stress;

    double stress=link1.calc();
    cout<<"The stress: "<<stress<<" MPa\n"<<endl;

    link1.comparison();
    link1.output_dim();


    // Part 2
    cout<<endl<<"Motor-Gearbox Selection"<<endl;
    double O_req = input_omegareq();
    vector <Motors>v_Motors;
    vector<gear_box>v_gears;
    vector<Combined_pairs2> my_pairs;

    do{
    input_mlist (v_Motors);
    gear_input(v_gears);
    calcProperties(v_Motors ,v_gears ,my_pairs ,(link1.bending_m)/1000.0 ,O_req );
    if (my_pairs.empty())
        cout<<"No suitable Combinations, Try again"<<endl;
    }while (my_pairs.empty());
    cost_calc(my_pairs);
    /*for (int j=0; j<my_pairs.size() ;j++) //for testing the sort function
    {
     cout<<"Valid Motor-Gearbox combination is: "<< my_pairs[j].C_name<<"  Cost="<< my_pairs[j].C_cost<<endl;
    }*/
    sort(my_pairs.begin(), my_pairs.end(), [](const Combined_pairs2& a, const Combined_pairs2& b)
            {
        return a.C_cost < b.C_cost;
            });


     cout<<"Optimal Motor-Gearbox combination is: "<< my_pairs[0].C_name<<"  Cost="<< my_pairs[0].C_cost<<endl;


    return 0;
}
