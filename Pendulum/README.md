PENDULUM -> RUNGE-KUTTA 4TH ORDER:

This program calculates, numerically, the solution to the driven damped harmonic
oscillator using Runge-Kutta 4th order method for two pendulums with slightly different
values for initial angles. The program then finds the difference in angular position
through time. 

The initial conditions including the initial angular off set can be set in the pendulum.h header file. The solutions are calculated in rungeKuttaCalc.cpp and written to file in save.cpp. The names of the output .txt files can also be changed in the pendulum.h header file.

The example solutions in this directory are for two values of the driving force Fd. For Fd=1.2 the solutions are saved in pendulum_1.2.txt. For fitting purposes, the peaks of the calculated angular difference between the two pendulums are stored in peaksFit_1.2.txt. Similarly, the solutions and angular difference peaks for Fd=0.5 are stored in pendulum_0.5.txt and peaksFit_0.5.txt. 

The plots.gp file is a GnuPlot script for creating plots. The script can be run using GnuPlot from terminal. It can be seen that the system is chaotic for a driving force of Fd=1.2 as the two pendulum trajectories are misaligned and are irregular. However, for Fd=0.5 the pendulum trajectories converge and are very regular. The results of the fits to the angular seperation peaks are created in GnuPlot and stored in fit.log.