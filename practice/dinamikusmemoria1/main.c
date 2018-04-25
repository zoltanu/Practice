#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,meret;
    double * t;
    printf("Mekkora tombot szeretne? ");
    scanf("%d",&meret);

    //Memória foglalás rész:
    t=(double*)malloc(meret*sizeof(double));
    if (t==NULL)
    {
        puts("Sikertelen memoria allokalas");
        exit(1);
    }

    for (i=0;i<meret;i++)
        t[i]=(double)i;

    printf("A csudalatos dinamikus tomb elemei pedig csokkeno szamsorrendben:\n");
    for (i=meret-1;i>-1;i--)
        printf("%g\n",t[i]);

    free(t);
    return 0;
}
