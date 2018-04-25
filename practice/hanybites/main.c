#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=3,b=6;

    printf("%d\t%d\t%d\t%d\n",a&b,a|b,a^b,~a);

    int szam,szamlalo;
    szamlalo=0;
    szam=1;
    while(szam!=0)
    {
        szam<<=1;
        szamlalo++;
    }
    printf("%d\n",szamlalo);
    int szam2,szamlalo2;
    szam2=1;
    szamlalo2=0;
    while(szam2!=0)
    {
        szam2*=2;
        szamlalo2++;
    }
    printf("%d\n",szamlalo2);
    return 0;
}
