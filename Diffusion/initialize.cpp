#include <cmath>
#include "diffusion.h"

double y[MAXi][2], a[MAXi];

/* ********************************************************** */
/* ********************** Initialize ************************ */
/* ********************************************************** */
void initialize()
{
    int i;
    double sigma,D;

    D = (dx*dx) / (6 * dt);
    sigma = sqrt(2 * D * dt);

    for(i = 0; i < MAXi; i++) //Initialize the density profile
    {
        y[i][0] = exp(-(i - 0.5 * MAXi) * (i - 0.5 * MAXi) * dx*dx / (2 * sigma*sigma)) / sigma;
        a[i] = exp(-(i - 0.5 * MAXi) * (i - 0.5 * MAXi) * dx*dx / (2 * sigma*sigma)) / sigma;
    }
}