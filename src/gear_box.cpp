#include "gear_box.h"
#include<vector>
#include<string>
#include<limits>
#include<iostream>
using namespace std;
//void gear_box::display_data()
//{

 void gear_input(std::vector<gear_box>&v_gears)
{
    gear_box G;
    vector<string> default_model= {"838272","110315", "110316","110481","143762","143763", "143766","143767","166952","454744"};
    vector <double> default_ratio= {169/9.0,185193/2744.0, 10556001/38416.0,121915/6153.0,29791/729.0,387283/5103.0,28629151/59049.0,372178963/413343.0,359424/875.0,
                                    49/4.0
                                   };
    vector<double>default_eff= {81,75,69, 66,73,66,59,53,60,87};
    vector<double>default_mass= { 0.36, 0.017, 0.02, 0.028, 0.01,0.01, 0.011, 0.011, 0.226, 0.57 };
    vector<double>default_diameter= {42,13,13,24,16,16,16,16,32,42};
    cout<< "#\tgear box model\t\tgear box ratio\t\tgear box efficiency\tgear box mass\tgear box diameter\n";
    cout << "................................................................................................\n";

    for (double i = 0; i <default_model.size(); i++)
    {
        cout << i + 1 << "\t" <<default_model [i];

        if (default_model[i].length() < 9)
            cout << "\t\t\t";
        else if (default_model[i].length() < 10)
            cout << "\t\t";
        else
            cout << "\t";

        cout <<default_ratio[i] << "\t\t\t" << default_eff[i] <<"\t\t\t"<<default_mass[i]<<"\t\t\t"<<default_diameter[i]<< endl;
    }

    bool first = true;
    char another, def, def_only;

    cout << "Do you want to use the default gear library? y/n \n";
    cin >> def;

    if (def == 'Y' || def == 'y')
    {
       for (int i = 0; i < v_gears.size(); i++)
    {
        if (v_gears[i].gearbox_model == "838272")
        {
            cout << "Default gearbox list already in use \n";
            goto default_skipped;
        }
    }
        for ( int i=0;i<10;i++)

                {
                G.gearbox_model =default_model[i];
                G.gear_ratio=default_ratio[i];
                G.efficiency=default_eff[i]/100.0;
                G.gear_mass=default_mass[i];
                G.gear_diameter=default_diameter[i];
                v_gears.push_back(G);
                }

        }
default_skipped:
        cout << "Do you want to add your gear boxes options ? y/n \n";
        cin >> def_only;
        if (def_only == 'n' || def_only == 'N')
        {
            return;
        }

    do
    {
        if (first == false)
        {
            cout << "Do you want to enter another gear box ? y/n \n";
            cin >> another;
            if (another == 'n' || another == 'N')
            {
                break;
            }
        }

        std::cout << "Gearbox model: ";
        std::cin >> G.gearbox_model;

       //input ratio

        int ratio_index1;
        char colon;
        int ratio_index2;

        while(true){
        std::cout << "Gearbox ratio ( in the format of (x:y)):  ";

         if ( cin>>ratio_index1>>colon>>ratio_index2 && colon==':')
      {
          if (ratio_index2!=0)
          {

          break;
          }
          else
           {
            cout<<"invalid input, y should not equal zero!, enter the number again " ;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            }
       else{
        cout << "invalid format ,try again with (x:y) format";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout<<"\n";
        }
        G.gear_ratio=ratio_index1/ratio_index2 ;

    //input efficiency
        int eff;
        while (true){
             std::cout << "Gearbox efficiency(%): ";
              std::cin >> eff;
       if (cin.fail() || eff>100){
            std::cout<<"efficiency must be less than 100 ,  please enter the efficiency again "<<"\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        else
            break;

        G.efficiency = eff/100.0;
        }


        std::cout << "Gearbox mass(Kg): ";
        std::cin >> G.gear_mass;

        std::cout << "Gearbox diameter(mm): ";
        std::cin >> G.gear_diameter;


        v_gears.push_back(G);
        first=false;
    }
    while(true);
}
