#include <iostream>
#include "pendulum.h"

double x[2*MAX], dx[MAX];

int main()
{
    rungeKuttaCalc();
    save();

    return 0;
}