#include <iostream>
#include <cmath>
#include "quantum_tunneling.h"

/**********************/
/* INITIALIZE PROBLEM */
/**********************/
void initialize(long double sigma, long double x0, long double k0, long double v0, long double width, long double v[], long double re[][2], long double im[][2], long double dx, long double dt)
{   
    re[0][0] = 0;  // Boundary Conditions
    re[0][1] = 0;
    re[MAXi - 1][0] = 0; 
    re[MAXi - 1][1] = 0;
    im[0][0] = 0;
    im[0][1] = 0;
    im[MAXi - 1][0] = 0;
    im[MAXi - 1][1] = 0;

    double c = sqrt( 1 / sqrt(M_PI * sigma*sigma / 2) ); // gaussain normalization

    for(int i = 1; i < MAXi - 1; i++) //initialize wavefunctin profile
    {
        re[i][0] = c * exp( -(i*dx - x0)*(i*dx - x0) / (sigma*sigma) ) * cos(k0*i*dx); 
        im[i][0] = c * exp( -(i*dx - x0)*(i*dx - x0) / (sigma*sigma) ) * sin(k0*i*dx);
    }
    for(int i = 0; i < MAXi; i++) //initialize potential distribution
    {
        if(i*dx >= 0.2 && i*dx <= 0.2 + width )
        {
            v[i] = v0;
        }
        else 
        {
            v[i] = 0; 
        }
    }
}

