#include <iostream>
#include <math.h>
#include "prism_conductor.h"

/* ********************************************************** */
/* ********************** calculate ************************* */
/* ********************************************************** */
double calculate()
{
    int i, j, n;
    double dv = 0;

        //Update the values of all the points in the array EXCEPT the boundary condition points.
        for(i = 1; i < (MAX/3); i++)
        {
            for(j = 1; j < MAX; j++)
            {
                v[i][j] = (1./4.) * (v[i + 1][j] + v[i - 1][j] + v[i][j + 1] + v[i][j - 1]);
            }
        }
        for(i = (MAX/3); i <= ((2*MAX)/3); i++)
        {
            for(j = 1; j < (MAX/3); j++)
            {
                v[i][j] = (1./4.) * (v[i + 1][j] + v[i - 1][j] + v[i][j + 1] + v[i][j - 1]);
            }
        }
        for(i = (MAX/3); i <= ((2*MAX)/3); i++)
        {
            for(j = (2*MAX)/3 + 1; j < MAX; j++)
            {
                v[i][j] = (1./4.) * (v[i + 1][j] + v[i - 1][j] + v[i][j + 1] + v[i][j - 1]);
            }
        }
        for(i = (2*MAX)/3 + 1; i < MAX; i++)
        {
            for(j = 1; j < MAX; j++)
            {
                v[i][j] = (1./4.) * (v[i + 1][j] + v[i - 1][j] + v[i][j + 1] + v[i][j - 1]);
            }
        }

        //Compare the cumulative change in values of the updated array
        for(i = 0; i <= MAX; i++)
        {
            for(j = 0; j <= MAX; j++)
            {
                dv = dv + fabs(v[i][j] - c[i][j]);
            }
        }

        //Re-initialize the second array to hold the values of the updated array for comparison on the next calculation.
        for(i = 0; i <= MAX; i++)
        {
            for(j = 0; j <= MAX; j++)
            {
                c[i][j] = v[i][j];
            }
        }
   return dv;
}