#include<iostream>
#include <cmath>
#include "pendulum.h"

/* ********************************************************** */
/* ************ Runge-Kutta Method Calculations ************* */
/* ********************************************************** */
void rungeKuttaCalc()
{
    double v[2*MAX];
    
    int j;
    for(j = 0; j < 2; j++)
    {
        int i, n = 0;
        double kx1, kx2, kx3, kx4, kv1, kv2, kv3, kv4;
        x[j * MAX] = xo + j * offSet; 
        v[j * MAX] = vo; 
        for(i = j * MAX; i < MAX * (1 + j); i++)
        {
            kx1 = v[i];
            kv1 = Fd * sin(freq * n * dt) - q * v[i] - omega*omega* sin(x[i]);
            kx2 = v[i] - (q * v[i] + omega*omega * sin(x[i] + 0.5 * kx1 * dt) - Fd * sin(freq * (n + 0.5) * dt)) * 0.5 * dt;
            kv2 = Fd * sin(freq * (n + 0.5) * dt) - q * kx2 - omega*omega * sin(x[i] + 0.5 * kx1 * dt);
            kx3 = v[i] -(q * v[i] + omega*omega * sin(x[i] + 0.5 * kx2 * dt) - Fd * sin(freq * (n + 0.5) * dt)) * 0.5 * dt;
            kv3 = Fd * sin(freq * (n + 0.5) * dt) - q * kx3 - omega*omega * sin(x[i] + 0.5 * kx2 * dt);
            kx4 = v[i] - (q * v[i] + omega*omega * sin(x[i] + kx3 * dt) - Fd * sin(freq * (n + 1) * dt)) * dt;
            kv4 = Fd * sin(freq * (n + 1) * dt) - q * kx4 - omega*omega * sin(x[i] + kx3 * dt);

            if(i != MAX * (1 + j) -1)
            {
                x[i + 1] = x[i] + (1./6.) * (kx1 + 2*kx2 + 2*kx3 + kx4) * dt;
                v[i + 1] = v[i] + (1./6.) * (kv1 + 2*kv2 + 2*kv3 + kv4) * dt;
                if(x[i + 1] > M_PI)
                {
                    x[i + 1] = x[i + 1] - 2*M_PI;

                }
                if(x[i + 1] < -1*M_PI)
                {
                    x[i + 1] = x[i + 1] + 2*M_PI;
                }
            }
            n++;
        }
    }
}
