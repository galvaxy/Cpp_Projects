#include <iostream>
#include <cmath>
#include "quantum_tunneling.h"

int main()
{
    long double m = 1, k0 = 500; // Initial particle parameters: mass, wave-vector 
    long double v0 = 1.2 * ( (hbar*hbar*k0*k0)/(2*m) ), width = 0.01; // Initial potential paramters: Square well potential height and width
    long double sigma = sqrt(0.001), x0 = 0.1; // Initial gaussian paramters: width and central position 
    long double dx = 0.0005, dt = ( 2*m*(dx*dx)/hbar ) / 3; // Spacial and Temporal resolution 
    long double re[MAXi][2], im[MAXi][2]; // Arrays to hold real and imaginary parts of wavefunction 
    long double v[MAXi]; // Array to store spacial distribution of potential 

    initialize(sigma, x0, k0, v0, width, v, re, im, dx, dt);      
    calc_save(dt, dx, m, v, re, im); 

    return 0;
}