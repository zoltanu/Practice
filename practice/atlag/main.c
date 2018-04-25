#include <stdio.h>
#include <stdlib.h>

int main()
{
    double szam=0.0, osszeg=0.0;
    int darab=0;
    printf("Kezdj el beirni szamokat!\nUss nullat ha mar beirtad az osszes szamot amit akartal.\n");
    scanf("%lg",&szam);

    while (szam!=0)
    {
        darab++;
        osszeg+=szam;
        scanf("%lf",&szam);
    }

    if (darab>0)
        printf("A beirt szamok atlaga: %g",(osszeg/darab));
    else
        printf("Hiba! Nem adtal meg egy szamot se kishaver!");

    return 0;
}
