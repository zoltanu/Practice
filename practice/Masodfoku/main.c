#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double a,b,c,diszkr,x1,x2;
    printf("Udv a masodfoku egyenlet megoldo programban\n\nKerlek add meg a harom parametert!\na= ");
    scanf("%lg",&a);
    printf("b= ");
    scanf("%lg",&b);
    printf("c= ");
    scanf("%lg",&c);

    diszkr=b*b-4*a*c;
    if (diszkr>=0.0)
    {
        x1=(-b+sqrt(diszkr))/(2*a);
        x2=(-b-sqrt(diszkr))/(2*a);
        printf("A ket gyok nem mas mint:\nx1= %g\nx2= %g\n",x1,x2);
    }
    else
        printf("A diszkriminans negativ ocsem.");

    return 0;
}
