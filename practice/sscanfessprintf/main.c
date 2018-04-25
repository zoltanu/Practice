#include <stdio.h>
#include <stdlib.h>

void kiir(int a, int b, char *t, char *s)
{
    printf("t=%s\na=%d\nb=%d\ns=%s\n\n",t,a,b,s);
}

int main()
{
    char t[]={"65 ember osszjovedelme 877323 Ft."};
    char s[40];
    int a,b,i;

    sscanf(t,"%d%s%*s%d",&a,s,&b);
    kiir(a,b,t,s);

    sscanf(t+25,"%d%s",&b,s);
    kiir(a,b,t,s);

    sprintf(t+4,"%s+%d szia!",s, a+b+3);
    printf("A t tomb tartalma:\n ");
    for (i=0;i<sizeof(t);i++)
        printf("t[%2d]= %3d = \'%c\'\n",i,t[i],t[i]);


    //printf("Hello world!\n");
    return 0;
}
