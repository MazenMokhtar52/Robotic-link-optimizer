#include <iostream>
#include <vector>
#include "Materials.h"

using namespace std;

void Materials::displayTable() //displays the materials table, then saves the selected material properties
{
    vector<string> materials =
    {
        "Cast iron", "Copper nickel", "Brass", "Aluminum",
        "Steel", "Acrylic", "Copper", "Stainless steel", "Tungsten"
    };

    vector<double> y_stress =
    {
        130, 130, 200, 241, 247, 70, 70, 275, 541
    };

    vector<double> density =
    {
        7.2, 8.94, 8.73, 2.7, 7.8, 1.18, 8.92, 7.86, 19.25
    };

    cout << "#\tMaterial\t\tYield Strength (MPa)\tDensity (g/cm^3)\n";
    cout << "-------------------------------------------------------------------\n";

    for (int i = 0; i < materials.size(); i++)
    {
        cout << i + 1 << ".\t" << materials[i];

        if (materials[i].length() < 8)
            cout << "\t\t\t";
        else if (materials[i].length() < 16)
            cout << "\t\t";
        else
            cout << "\t";

        cout << y_stress[i] << "\t\t\t" << density[i] << endl;
    }

    cout << "10.\tCustom material" << endl;

    int choice;
    while (true)
    {
        cout << "\nEnter a number to select a material: ";
        cin >> choice;

        if (choice >= 1 && choice <= 9)
        {
            int index = choice - 1;
            cout << "\nYou selected: " << materials[index] << endl;
            cout << "Yield strength: " << y_stress[index] << " MPa" << endl;
            cout << "Density: " << density[index] << " g/cm^3\n"<< endl;
            selected_y_stress=y_stress[index];
            selected_density=density[index];
            break;
        }
        else if (choice == 10)
        {
            string name;
            double custom_y_stress, custom_density;

            cin.ignore();
            cout << "Enter material name: ";
            getline(cin, name);

            while (true)
            {
                cout << "Enter yield strength (MPa): ";
                cin >> custom_y_stress;
                if (custom_y_stress > 0) break;
                else
                    cout << "Value must be positive." << endl;
            }
            selected_y_stress=custom_y_stress;

            while (true)
            {
                cout << "Enter density (g/cm^3): ";
                cin >> custom_density;
                if (custom_density > 0) break;
                else
                    cout << "Value must be positive." << endl;
            }
            selected_density=custom_density;

            cout << "\nYou entered:\n";
            cout << "Material: " << name << endl;
            cout << "Yield strength: " << custom_y_stress << " MPa" << endl;
            cout << "Density: " << custom_density << " g/cm^3\n" << endl;
            break;
        }
        else
        {
            cout << "Invalid input. Try again." << endl;
        }
    }
}
