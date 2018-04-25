#include <stdio.h>
#include <stdlib.h>

int betue(char valami)
{
    if ((valami>='A' && valami<='Z')||(valami>='a' && valami<='z'))
        return 1;
    return 0;
}

int main()
{
    char karakter;
    printf("Irj le egy betut: ");
    scanf("%c",&karakter);
    switch (betue(karakter))
    {
        case 0: printf("\n%c nem betu", karakter);
                break;
        case 1: printf("\n""%c"" egy betu", karakter);
    }


    return 0;
}
