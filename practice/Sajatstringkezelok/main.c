#include <stdio.h>
#include <stdlib.h>

int x_strlen (const char* ch)
{
    int len;
    for (len=0;ch[len]!=0;len++);
    return len;
}

char * x_strcat_1(char * beki,const char * be2)
{
    int i,j;
    for(i=0; beki[i]!=0; i++);
    for(j=0; (beki[i]=be2[j])!=0; i++,j++);
    return beki;
}

char * osszefuz ( const char * b1, const char * b2, char* ki)
{
    int i,j,k;
    j=0;
    k=0;
    for (i=0;b1[i]!=0 && b2[i]!=0;i++)
    {
        ki[2*i]=b1[i];
        ki[2*i+1]=b2[i];
        j=2*i+1;
        k=i;
    }

        if (b1[k+1]==0)

        {
            for (i=j;b2[k]!=0;i++,k++)
        {
            ki[i]=b2[k];
            j=i;
        }
            ki[j+1]='\0';
            return ki;
        }

        if (b2[k+1]==0)

        {
            for (i=j;b1[k]!=0;i++,k++)
        {
            ki[i]=b1[k];
            j=i;
        }
            ki[j+1]='\0';
            return ki;
        }


}

int main()
{
    int hossz;
    char teszt[]="Gyaszhuszar"; //Stringet igy adunk meg. Csak semmi char*-ozgatas
    char teszt2[]=" aki mondja!";
    char teszt3[100];
    char betuk[]="abcdefghijklmnopqrstuvwxyz";
    char szamok[]="0123456789";

    hossz=x_strlen(teszt);
    printf("\"%s\" hossza: %d\n",teszt,hossz);

    x_strcat_1(teszt,teszt2);
    printf("%s\n",teszt);

    osszefuz(szamok,szamok,teszt3);
    printf("%s\n",teszt3);

    return 0;
}
