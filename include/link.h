#ifndef LINK_H
#define LINK_H

using namespace std;
class link
{
public:

    link();

    char cross_section;
    double r, b, h, link_length, mass_l, mass_p, ang_acc, moment, inertia, area, y_stress,
    density, weight_l, weight_m , bending_m, moment_I, stress;

    void input_data();
    double calc ();
    double comparison();
    void red_dim();
    void inc_dim();
    void output_dim();
};

#endif
