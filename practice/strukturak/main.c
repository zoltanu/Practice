#include <stdio.h>
#include <stdlib.h>
#include <math.h>

    struct par {double x1,x2;};

    struct par gyok (double a,double b,double c)
    {
        double d = b*b-4*a*c;
        struct par x;

        if (d<0)
        {
            fprintf(stderr,"Hiba! A diszkriminans kisebb mint 0!\n");
            exit (1);
        }

        d=sqrt(d);
        x.x1=(-b+d)/(2*a);

        x.x2=(-b-d)/(2*a);
        return x;
    }

int main()
{
struct par x;
x=gyok(1.0,7.0,10.0);

printf("a=1, b=7, c=10\nA masodfoku egyenlet gyokei pedig:\nx1=%g\tx2=%g",x.x1,x.x2);
    return 0;
}
