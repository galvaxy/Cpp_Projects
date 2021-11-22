SHARP GAUSSIAN EXAMPLE:

 This program is working in units of hbar = 1 and m = 1. This example is has all the same initial values as the benchmark case except the std dev sigma of the particle profile is made smaller.

 psi(x) = c * exp(- (x - x0)^2 / sigma^2 ) * exp(i k0 x)

 c^2 = 1 / sqrt(pi sigma^2 / 2) 

 The initial wavefunction is a normalized gaussian multiplied by a plane wave momentum eigenstate given by the above equation. The initial parameters of the wavefunction are sigma^2 = 0.001 / 9, x0 = 0.1 and k0 = 500. The potential is a square potential wall with magnitude V0 = 1.2 ( (hbar^2 k0^2) / (2 m) ) and has a width of 0.01. The spacial resolution is dx = 0.005 and the temporal resolution is dt = ( (2 m dx^2) / (hbar) ) / 3. 

 The solution data to the program is saved in the tunneling.txt file. This data is used to create a vizualisation gif. It can be seen that most of the initial gaussian wave is reflected from the potential barrier. However, some of the wavefunction tunnels to the other side of the barrier and there is a non-zero probability of finding the particle where it is classically forbidden. Since the potential is larger in magnitude then the kinetic energy of the particle, classically the particle cannot be found on the other side of the barrier. This is the basis of quantum tunneling.

 The plots.gp file is a GnuPlot script that can be run using GnuPlot in terminal to create the plots for the vizualization of the problem. A gif file is produced and saved as tunneling.gif to demonstrate the vizualization of the solution of the problem. 