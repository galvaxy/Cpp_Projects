#include <iostream>
#include <math.h>
#include <fstream>
#include "prism_conductor.h"

/* ********************************************************** */
/* ********************** Check_Save ************************ */
/* ********************************************************** */
void check_save()
{
    std::ofstream stream("prismConductor.txt"); 
    double dv = calculate();
    int i, j;

    //Check for convergence. If convergence is not met call on calculation() to do another iteration.
    while(dv > 0.007)
    {
        dv = calculate();
    }
    //When convergence is met save data to a file
    for(i = 0; i <= MAX; i++)
    {
        for(j = 0; j <= MAX; j++)
        {
            stream<<i<<"\t"<<j<<"\t"<<v[i][j]<<"\n";
        }
    }
}