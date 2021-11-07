#include <iostream>
#include <math.h>
#include "free_end_wave.h"

double y[MAXi][3];
double dx = 0.01, c = 300, r = 1, dt;

/* ********************************************************** */
/* ********************** Initialize ************************ */
/* ********************************************************** */
void initialize()
{
    int i;
    double k = 1000; //The value of k is a measure of the width of the Gaussian pluck

    dt = (double)dx/c; // If r is to equal 1 than this relationship must hold

    for(i = 0; i < MAXi; i++) //Initialize the shape of the pluck of the string
    {
        y[i][0] = exp(-k * (i*dx - 0.25) * (i*dx - 0.25));
        y[i][1] = exp(-k * (i*dx - 0.25) * (i*dx - 0.25));
    }
}