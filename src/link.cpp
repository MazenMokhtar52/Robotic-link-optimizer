#include <iostream>
#include <cmath>
#include <limits>
#include "link.h"

using namespace std;

float g = 9.81;


void link::input_data() //input the cross section type, dimensions, length, payload, and ang acc
{
    cout << "Input the cross section type (c) for circular (r) for rectangular: (case sensitive)";
    while(true)
    {
        cin >> cross_section;
        if(cross_section == 'c' || cross_section == 'r')
        {
            break;
        }
        else
        {
            cout << " Wrong input, (c) for circular (r) for rectangular: ";
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    if(cross_section == 'c')
    {
        cout << "Enter the radius (mm): ";
        while (true)
        {
            cin >> r;
            if (cin.fail() || r <= 0)
            {
                cout << " Wrong input, radius must be a number greater than zero: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else {break;}
        }

    }
    else if(cross_section == 'r')
    {
        cout << "Enter the base and height (mm): ";
        while (true)
        {
            cin >> b;
            if (cin.fail() || b <= 0)
            {
                cout << " Wrong input, base length must be a number greater than zero: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else {break;}
        }
        while (true)
        {
            cin >> h;
            if (cin.fail() || h <= 0)
            {
                cout << " Wrong input, height must be a number greater than zero: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else {break;}
        }
    }
    cout << "Enter the length of the link (mm): ";
    while (true)
        {
            cin >> link_length;
            if (cin.fail() || link_length <= 0)
            {
                cout << " Wrong input, length must be a number greater than zero: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else {break;}
        }
    cout << "Enter the mass of the payload (kg): ";
    while (true)
        {
            cin >> mass_p;
            if (cin.fail() || mass_p < 0)
            {
                cout << " Wrong input, mass must be a non negative number : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else {break;}
        }
    cout << "Enter the maximum angular acceleration of the link (rad/s^2): ";
    while (true)
        {
            cin >> ang_acc;
            if (cin.fail())
            {
                cout << " Wrong input, please try again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
            }
            else {break;}
        }

}

double link::calc() // calculates the stress on the link
{
    if(cross_section=='c')
    {
        mass_l= density* pow(10,-6) * M_PI * pow(r,2) * link_length;
        moment_I= (M_PI*pow(r,4))/4;
    }
    else if(cross_section=='r')
    {
        mass_l= density* pow(10,-6) * b * h * link_length;
        moment_I= (b*pow(h,3))/12;
    }
    else
        cout<<"Please choose c or r!"<<endl;
    weight_l= mass_l * g * link_length/2; // [N mm]

    weight_m= mass_p * g * link_length; //[N mm]

    inertia= (mass_l*pow(link_length/2,2)*ang_acc)+(mass_p*pow(link_length,2)*ang_acc);

    bending_m= weight_l + weight_m + inertia;

    if(cross_section=='c')
        stress= (bending_m*r)/moment_I;
    else if(cross_section=='r')
        stress= (bending_m*h)/(2*moment_I);
    return stress;
}

void link::red_dim() //reduces dimensions and recalculates stress
{
    if (cross_section == 'c')
    {
        r = r *0.99;
        stress=calc();

    }
    else if (cross_section == 'r')
    {
        b = b *0.99;
        h = h *0.99;
        stress=calc();
    }

}
void link::inc_dim() // increases dimensions and recalculates stress
{
    if (cross_section == 'c')
    {
        r = r *1.01;
        stress=calc();
    }
    else if (cross_section == 'r')
    {
        b = b *1.01;
        h = h *1.01;
        stress=calc();
    }

}

double link::comparison() // increases or decreases dimensions based on the yield stress
{
    if (stress > y_stress)
    {
        while(stress > y_stress)
        {
            inc_dim();
        }
    }
    else if (stress < 0.95*y_stress)
    {
        while(stress < 0.95*y_stress)
        {
            red_dim();
        }
    }
    return 0;
}

void link::output_dim() //outputs the final dimensions
{
    if (cross_section=='c')
    {
        cout << "the final radius is " << r << "mm\n";

    }
    else if (cross_section=='r')
    {
        cout << "the final b is " << b << "mm\n";
        cout << "the final h is " << h << "mm\n";
    }
    cout << "the final stress is " << stress << "MPa\n";
    cout << "torque required is "  <<bending_m<< "N.mm\n";
}

link::link() {}

