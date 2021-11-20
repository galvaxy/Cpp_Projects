#include "quantum_tunneling.h"

/*************/
/* NORMALIZE */
/*************/
double normalize(long double re[][2], long double im[][2], long double dx)
{
    double norm = 0;
    for(int i = 0; i < MAXi; i++)
    {
        norm += (re[i][1]*re[i][1] + im[i][1]*im[i][1])*dx;
    }

    return norm;
}