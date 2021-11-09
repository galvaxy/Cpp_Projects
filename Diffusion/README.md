DIFFUSION:

 This program simulates the diffusion of a density profile peaked around x=0 at t=0 as it evolves through time. The initial density profile is a sharp gaussian which is initialized in initialize.cpp. The time step iterations are calculated and saved to file in calculate.cpp. The analytical solution to the time evolution of the initial profile is also calculated and all results are saved to diffusion.txt. 

 The plots.gp file is a GnuPlot script that can be run using GnuPlot from terminal to create plots. An animation is created and and saved as diffusion.gif. It can be seen that the profile initially diffuses extremely quickly and slows down significantly as the peak density drops. 