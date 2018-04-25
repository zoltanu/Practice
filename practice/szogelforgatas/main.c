#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double koordx=0.0, koordy=0.0, ujkoordx=0.0, ujkoordy=0.0;
    int szog=0;
    printf("Add meg a vektor ket eredeti koordinatajat: \n");
    scanf("%lg%lg",&koordx,&koordy);
    printf("Add meg a forgatas szoget: \n");
    scanf("%d",&szog);
    szog=(szog*M_PI)/180.0;

    ujkoordx=koordx*cos(szog)-koordy*sin(szog);
    ujkoordy=koordx*sin(szog)+koordy*cos(szog);

    printf("Az uj koordinatak:\nx=%5g\ny=%5g\n",ujkoordx,ujkoordy);
    return 0;
}
