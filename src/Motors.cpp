#include "Motors.h"
#include <iostream>
#include <vector>

using namespace std;

Motors::Motors(string n, double t, double o, double m, double dia)
{
    M_model = n;
    M_torque = t;
    M_omega = o;
    M_mass = m;
    M_diameter = dia;
}

void use_def_m(vector <Motors> &v_m)
{
    for (int i = 0; i < v_m.size(); i++)
    {
        if (v_m[i].M_model == "734439")
        {
            cout << "Default motor list already in use \n";
            return;
        }
    }
    v_m.emplace_back(Motors("734439", 322, 6650, 0.225, 50));
    v_m.emplace_back(Motors("740953", 1710, 3410, 0.741, 85));
    v_m.emplace_back(Motors("758031", 430, 4330, 0.270, 50));
    v_m.emplace_back(Motors("783327", 688, 4570, 0.377, 65));
    v_m.emplace_back(Motors("783332", 1130, 2590, 0.524, 65));
    v_m.emplace_back(Motors("800948", 186, 6290, 0.170, 38));
    v_m.emplace_back(Motors("814370", 96.8, 12400, 0.125, 38));
    v_m.emplace_back(Motors("110081", 1.35, 8040, 0.33, 19));
    v_m.emplace_back(Motors("167131", 843, 3100, 2.450, 60));
    v_m.emplace_back(Motors("148867", 177, 7580, 0.480, 40));
    v_m.emplace_back(Motors("136210", 311, 8670, 1.150, 45));

}

void def_display()
{
  vector<string> default_model= {"734439","740953","758031","783327","783332","800948","814370","110081","167131","148867","136210"};
    vector <double> default_torque= {332,1710,430,688,1130,186,96.8,1.35,843,177,311};
    vector<double>default_omega = {6650,3410,4330,4570,2590,6290,12400,8040,3100,7580,8670};
    vector<double>default_mass= {0.225,0.741,0.270,0.377,0.524,0.170,0.125,0.33,2.450,0.480,1.150};
    vector<double>default_diameter= {50,85,50,65,65,38,38,19,60,40,45};
cout<< "#\tMotor Model\t\tMotor Torque\t\tMotor Omega\tMotor Mass\tMotor Diameter\n";
cout<<"...........................................................................\n";

    for (double i = 0; i <default_model.size(); i++)
    {
        cout << i + 1 << "\t" <<default_model [i];

        if (default_model[i].length() < 9)
            cout << "\t\t\t";
        else if (default_model[i].length() < 10)
            cout << "\t\t";
        else
            cout << "\t";

        cout <<default_torque[i] << "\t\t\t" << default_omega[i] <<"\t\t\t"<<default_mass[i]<<"\t\t\t"<<default_diameter[i]<< endl;
    }
}

void input_mlist (vector <Motors> &v_m) //motor list input function
{
    bool first = true;
    char another, def, def_only;
    def_display();
    cout << "Do you want to use the default motor library? y/n \n";
    cin >> def;

    if (def == 'Y' || def == 'y')
    {
        use_def_m(v_m);  //use default library
        cout << "Do you want to add custom motors? y/n \n";
        cin >> def_only;
        if (def_only == 'n' || def_only == 'N')
        {
           return;
        }
    }

    do
    {
        if (first == false)
        {
            cout << "Do you want to enter another motor? y/n \n";
            cin >> another;
            if (another == 'n' || another == 'N')
            {
                break;
            }
        }
        Motors M1;
        cout<<endl<< "Enter motor model: ";
        cin>>M1.M_model;

        cout<< "Enter motor torque (N.m): ";
        cin>>M1.M_torque;

        cout<< "Enter motor speed (rpm): ";
        cin>>M1.M_omega;

        cout<< "Enter motor mass (kg): ";
        cin>>M1.M_mass;

        cout<< "Enter motor diameter (mm): ";
        cin>>M1.M_diameter;

        v_m.push_back(M1);
        first = false;

    }while(true);

}

Motors::Motors(double M_torque, double M_omega)
{
    this->M_torque = M_torque;
    this->M_omega = M_omega;
}

