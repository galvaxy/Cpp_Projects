#ifndef PENDULUM_H
#define PENDULUM_H

#define MAX 5000 // Maximum number of steps 
#define dt 0.04 // Step size
#define Fd 0.5 //Fd -> magnitude of the driving force
#define omega 1 // omega^2=g/l -> angular velocity
#define xo 0.2
#define vo 0 // xo and vo are boundry conditions
#define q 0.5 // q -> damping force,
#define freq .2/.3  // freq -> driving force frequency 
#define offSet 0.001 // Initial angular off set between the two pendulums

#define output1 "pendulum_0.5.txt"
#define output2 "peaksFit_0.5.txt" //name of files to store solution data

extern double x[2*MAX], dx[MAX]; // Arrays to hold angles x[] and the difference of the two angles dx[x]


/* ********************************************************** */
/* ************ Runge-Kutta Method Calculations ************* */
/* ********************************************************** */
void rungeKuttaCalc(); 

/* ********************************************************** */
/* ************************** Save ************************** */
/* ********************************************************** */
void save();

#endif