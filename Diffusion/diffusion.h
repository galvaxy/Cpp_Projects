#ifndef DIFFUSION_H
#define DIFFUSION_H

#define MAXj 200 // This defines the number of time steps
#define MAXi 200 // This defines spatial resolution
#define dx 0.1 // spacial step size
#define dt 0.01 // time step size

extern double y[MAXi][2], a[MAXi]; //This array holds the profile at t and at the next time step t+1 of numerical solution, y, and analytic solution, a.

/* ********************************************************** */
/* ********************** Initialize ************************ */
/* ********************************************************** */
void initialize();

/* ********************************************************** */
/* *********************** Calculate ************************ */
/* ********************************************************** */
void calculate();  

#endif