#include <iostream>
#include <fstream>
#include <cmath>
#include "diffusion.h"

/* ********************************************************** */
/* *********************** Calculate ************************ */
/* ********************************************************** */
void calculate()
{
    std::ofstream stream("diffusion.txt");      

    int i, j;
    double sigma, D;

    D = (dx*dx) / (6*dt);

    //print the initial density profile.
    for(i = 0; i < MAXi; i++)
    {
        stream<<(i - (MAXi/2)) * dx<<"\t"<<y[i][0]<<"\t"<<a[i]<<"\n";
    }
    stream<<"\n\n";
    for(j = 1; j <= MAXj; j++) // calculate the density profile at the next time step
    {
        for(i = 0; i < MAXi; i++) //Calculate the analytic solution
        {
            sigma = sqrt(2 * D * j * dt);
            a[i] = exp(-(i - 0.5 * MAXi) * (i - 0.5 * MAXi) * dx*dx / (2 * sigma*sigma)) / sigma;
        }
        for(i = 1; i < MAXi - 1; i++)
        {
            y[i][1] = y[i][0] + ((D * dt) / (dx*dx) )* ( y[i + 1][0] + y[i - 1][0] - 2 * y[i][0] );
        }
        for(i = 0; i < MAXi; i++) //print newly calculated profile
        {
            stream<<(i - 0.5 * MAXi) * dx<<"\t"<<y[i][1]<<"\t"<<a[i]<<"\n";
        }
        stream<<"\n\n";
        for(i = 0; i < MAXi; i++) //re-initialize arrays so to save memory usage.
        {
            y[i][0] = y[i][1];
        }
    }
}