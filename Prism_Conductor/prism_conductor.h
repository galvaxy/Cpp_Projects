#ifndef PRISM_CONDUCTOR_H
#define PRISM_CONDUCTOR_H

#define MAX 81 // MAX must be divisible by three because of the geometry of the problem.

extern double v[MAX + 1][MAX + 1], c[MAX + 1][MAX + 1]; //There are 2 2-D arrays being stored (to test for convergence), one for the updated calculation v[] and one for the previous calculation c[].


/* ********************************************************** */
/* ********************** Initialize ************************ */
/* ********************************************************** */
void initialize();

/* ********************************************************** */
/* ********************** calculate ************************* */
/* ********************************************************** */
double calculate();
  
/* ********************************************************** */
/* ********************** Check_Save ************************ */
/* ********************************************************** */
void check_save();

#endif