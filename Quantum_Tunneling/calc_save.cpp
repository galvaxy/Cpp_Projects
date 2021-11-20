#include <iostream>
#include <fstream>
#include <cmath>
#include "quantum_tunneling.h"

/******************************/
/* CALCULATE AND SAVE RESULTS */
/******************************/
void calc_save(long double dt, long double dx, long double m, long double v[], long double re[][2], long double im[][2])
{
    double prob, norm;

    std::ofstream file("tunneling.txt"); 

    for(int i = 0; i < MAXi; i++) //save initial gaussian probability profile
    {
        prob = re[i][0]*re[i][0] + im[i][0]*im[i][0];
        file<<i*dx<<"\t"<<re[i][0]<<"\t"<<im[i][0]<<"\t"<<prob<<"\n";
    }
    file<<"\n\n";
    
    /*for(int i = 1; i < MAXi - 1; i++) // Shift imaginary part of wavefunction half a step forward
    {
        im[i][0] = ( (dt/2)*hbar/(2*m*dx*dx) ) * (re[i + 1][0] - 2*re[i][0] + re[i - 1][0]);
    }*/

    for(int j = 1; j < MAXj; j++)
    {
        for(int i = 1; i < MAXi - 1; i++) // calculate profile at next time step
        {
            re[i][1] = re[i][0] - ( dt*hbar/(2*m*dx*dx) ) * (im[i + 1][0] - 2*im[i][0] + im[i - 1][0]) + (dt/hbar)*v[i]*im[i][0]; 
        }
        for(int i = 1; i < MAXi - 1; i++)
        {
            im[i][1] = im[i][0] + ( dt*hbar/(2*m*dx*dx) ) * (re[i + 1][1] - 2*re[i][1] + re[i - 1][1]) - (dt/hbar)*v[i]*re[i][1];
        }
                    
        if( fabs(normalize(re, im, dx) - 1) > 0.01) // check normalization of wavefunction
        {
            std::cout<<"Normalization not preserved for time step "<<j<<"!\n"; 
        }

        for(int i = 0; i < MAXi; i++) // print normalized wavefunction
        {
            prob = (re[i][1]*re[i][1] + im[i][1]*im[i][1]);

            file<<i*dx<<"\t"<<re[i][1]<<"\t"<<im[i][1]<<"\t"<<prob<<"\n";
        }
        file<<"\n\n";

        for(int i = 0; i < MAXi; i++) //Re-initialize profile to save memory
        {
            im[i][0] = im[i][1];
            re[i][0] = re[i][1]; 
        }
    }
}