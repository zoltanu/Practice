#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {double k[3];}koordinata;

koordinata normal (koordinata be)
{
    double hossz =0.0;
    int i;
    for (i=0;i<3;i++)
    {
        hossz+=be.k[i]*be.k[i];
    }
    hossz=sqrt(hossz);
    for (i=0;i<3;i++)
    {
        be.k[i]=be.k[i]/hossz;
    }
    return be;
}

int main()
{
    koordinata x={1.0,1.2,1.4},y;
    int i;
    y=normal(x);
    for(i=0;i<3;i++)
    printf("x[%d]=%10g and y[%d]=%10g\n",i,x.k[i],i,y.k[i]);
    return 0;
}
