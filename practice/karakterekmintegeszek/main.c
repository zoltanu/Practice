#include <stdio.h>
#include <stdlib.h>

int haromszog(int a, int b, int c)
{
    if (a>=(b+c)) return 0;
    if (b>=(a+c)) return 0;
    if (c>=(a+b)) return 0;
    return 1;
}

int betue (char c)
{

        if(c>='A' && c<='Z')return 1;
        if(c>='a' && c<='z')return 1;
   return 0;
}

int main()
{
    int a=2, b=3, c=4;

    if (haromszog(a,b,c)) printf("Ez lehet haromszog!\n");
    else printf("Ez nem lehet haromszog!");


    int i,n;
    char s[]="Borbol lettel, s borra leszel!";
    for (i=0,n=0;s[i]!='\0';i++)
    {
        if (betue(s[i]))n++;
    }
    printf("\n\nA\"Borbol lettel, s borra leszel!\" szovegben %i betu van", n);
    return 0;
}
