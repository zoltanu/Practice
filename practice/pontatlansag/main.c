#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("Pontatlansag\n\n");
    float a,b,c,x1=1.0,x2=1.0,d,y1,y2;
    int i;
    for (i=0;i<20;i++,x2*=10.0F)
    {
        a=1.0F;
        b=-(x1+x2);
        c=(float)(x1*x2);
        d=(float)(b*b)-(float)(4*a*c);
        y1=(-b+(float)sqrt(d))/(2*a);
        y2=(-b-(float)sqrt(d))/(2*a);
        printf("n= %d x1= %g\nx2= %g\ny1= %g\ny2= %.10f\n\n",i,x1,x2,y1,y2);
    }
///Nekem Nem az jön ki mint ami a könyvben. Helyette n=8-nál 4 az y2 majd 0
    return 0;
}
