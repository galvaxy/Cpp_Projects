#include <iostream>
#include <fstream>
#include <math.h>
#include "free_end_wave.h"

/* ********************************************************** */
/* *********************** Calculate ************************ */
/* ********************************************************** */
void calculate()
{
    std::ofstream stream("freeEndWave.txt");
    
    int i, j;

    for(j = 0; j < 2; j++) //print the initial wave profile because that information (stored in an array) will be replaced in the net loop
    {
        for(i = 0; i <= MAXi; i++)
        {
            stream<<i*dx<<"\t"<<y[i][j]<<"\n";
        }
        stream<<"\n\n";
    }
    for(j = 0; j < MAXj; j++) // calculate the wave profile at the next time step
    {
        for(i = 1; i < MAXi; i++)
        {
            y[i][2] = 2 * (1 - r*r) * y[i][1] + r*r * (y[i + 1][1] + y[i - 1][1]) - y[i][0];
        }
        y[0][2] = y[1][2]; //re-initialize the boundary conditions
        y[MAXi-1][2] = y[MAXi - 2][2]; //the ends of the strings have the same displacement as the displacement of their neighboring points
        for(i = 0; i < MAXi; i++) //print newly calculated profile
        {
            stream<<i*dx<<"\t"<<y[i][2]<<"\n";
        }
        stream<<"\n\n";
        for(i = 0; i < MAXi; i++) //re-initialize arrays so to save memory usage. Only 3 time steps are ever stored at a time.
        {
            y[i][0] = y[i][1];
            y[i][1] = y[i][2];
        }
    }
}