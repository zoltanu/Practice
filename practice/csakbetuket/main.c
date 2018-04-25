#include <stdio.h>
#include <stdlib.h>

int betue(char karakter)
{
    if ((karakter>='A' && karakter<='Z') || (karakter>='a' && karakter<='z'))
        return 1;
    return 0;
}

void szuro()
{
    char kovi;
    do
    {
        scanf("%c",&kovi);
        if (betue(kovi))printf("%c",kovi);
    }while (kovi!='\n');
    return;
}

int main()
{
    szuro();
    return 0;
}
