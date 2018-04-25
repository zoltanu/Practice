#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    char c;
    for (i=0;i<255;i++)
    {
     printf("%c=%d\n",i,i);
    }

    /*printf("\n\nIrj be egyetlen karaktert: ");
    scanf("%c",&c);
    if(scanf("%c",&c)!=1)
    {
        fprintf(stderr,"Hibas beolvasas!\n");
        exit(1);
    }
    printf("\nA karakter: %c",c);*/

   /* printf("\n\nIrj be meg egy karaktert: ");
    char c2;
    int i2;
    i2=getchar();

    if (i2==EOF)
    {
        fprintf(stderr,"\nHibas beolvasas!\n");
        exit(1);
    }
    else c2=i2;
    printf("\n\nA karakter: ");
    putchar(c2);*/

    char s[100];
    printf("\n\nDobj ide egy stringet kicsihuszar: ");
    gets(s);
    printf("%s\n",s);
    puts(s);

    return 0;
}
