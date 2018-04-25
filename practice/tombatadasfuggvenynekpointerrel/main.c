#include <stdio.h>
#include <stdlib.h>

double osszegzo (double t[], unsigned n)
{
    unsigned i;
    double osszeg=0.0;
    for (i=0;i<n;i++)
    {
        osszeg+=t[i];
    }
    return osszeg;
}

int main()
{
    double tomb[]={1.0,1.2,1.4,1.6,1.8};
    double kimenet;
    kimenet=osszegzo(tomb,5);

    printf("A tomb elemei: {%g, %g, %g, %g, %g}\nA tomb elemeinek osszege: %g",tomb[0],tomb[1],tomb[2],tomb[3],tomb[4],kimenet);
    return 0;
}
