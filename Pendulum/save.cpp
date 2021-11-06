#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <string.h>
#include "pendulum.h"

/* ********************************************************** */
/* ************************** Save ************************** */
/* ********************************************************** */
void save()
{
    std::vector<double> peaks;

    std::ofstream file1(output1), file2(output2); //creates file object

    int i, m = 0;
    for(i = 0; i < MAX; i++)
    {
        dx[i] = fabs( x[MAX + i] - x[i] );
        file1<<i*dt<<"\t"<<x[i]<<"\t"<<x[i + MAX]<<"\t"<<dx[i]<<"\n";
    }
    for (i = 0; i < MAX; i++)
    {
        if(i ==  0)
        {
            if( dx[i] > dx[i + 1] && fabs(dx[i] / dx[i + 1]) < 10 && fabs(dx[i] / dx[i + 1]) > 0.1)
            {
                peaks.push_back(dx[i]);
                file2<<i*dt<<"\t"<<peaks[m]<<"\n";
                m++;
            }     
        }
        else if(0 < i && i < MAX - 1)
        {
            if( dx[i] > dx[i - 1] && dx[i] > dx[i + 1] && fabs(dx[i] / dx[i + 1]) < 10 && fabs(dx[i] / dx[i + 1]) > 0.1 && fabs(dx[i] / dx[i - 1]) > 0.1 && fabs(dx[i] / dx[i - 1]) < 10)
            {
                peaks.push_back(dx[i]);
                file2<<i*dt<<"\t"<<peaks[m]<<"\n";
                m++;
            }
        }
        else if(i == MAX - 1)
        {
            if( dx[i] > dx[i - 1] && fabs(dx[i] / dx[i - 1]) < 10 && fabs(dx[i] / dx[i - 1]) > 0.1 )
            {
                peaks.push_back(dx[i]);
                file2<<i*dt<<"\t"<<peaks[m]<<"\n";
                m++;
            }     
        }
    }
    file1.close();
    file2.close();
}