#ifndef QUANTUM_TUNNELING_H
#define QUANTUM_TUNNELING_H

#define hbar 1 /* working in units were the reduced planck constant is unity */
#define MAXi 601 /* Spacial grid */
#define MAXj 5000 /* Temporal grid */

/**********************/
/* INITIALIZE PROBLEM */
/**********************/
void initialize(long double sigma, long double x0, long double k0, long double v0, long double width, long double v[], long double re[][2], long double im[][2], long double dx, long double dt);

/******************************/
/* CALCULATE AND SAVE RESULTS */
/******************************/
void calc_save(long double dt, long double dx, long double m, long double v[], long double re[][2], long double im[][2]);

/*************/
/* NORMALIZE */
/*************/
double normalize(long double re[][2], long double im[][2], long double dx);

#endif
