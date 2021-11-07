#include <iostream>
#include <math.h>
#include "prism_conductor.h"

double v[MAX + 1][MAX + 1], c[MAX + 1][MAX + 1];

/* ********************************************************** */
/* ********************** Initialize ************************ */
/* ********************************************************** */
void initialize()
{
    int i, j;

    //Initialize values for outer plate
    for(i = 0; i <= MAX; i++)
    {
        v[i][0] = 0;   //Initialize left plate
    }
    for(i = 0; i <= MAX; i++)
    {
        v[i][MAX - 1] = 0;   //Initialize right plate
    }
    for(j = 0; j <= MAX; j++)
    {
        v[0][j] = 0;   //Initialize top plate
    }
    for(j = 0; j <= MAX; j++)
    {
        v[MAX - 1][j] = 0;   //Initialize bottom plate
    }
    //Initialize solid inner conductor
    for(i = (MAX/3); i <= ((2*MAX)/3); i++)
    {
        for(j = MAX/3; j <= ((2*MAX)/3); j++)
        {
            v[i][j] = 1;
        }
    }
     //Initialize second "comparison" array
    for(i = 0; i <= MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            c[i][j] = v[i][j];
        }
    }

}