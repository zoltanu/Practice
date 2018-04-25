#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Pointer tömb:
    char *s[]={"Hetfo","Kedd","Szerda"},ch;
    printf("%s\n",s[2]);
    s[2]="Vasarnap"; //Itt pointer másolás történik, ezért mûködhet
    printf("%s\n",s[2]);
    ch=s[0][2];
    //s[0][3]='X' ->Hibás mivel a Hétfõ string constans
    //strcpy(s[1],"Szombat"); ->Hibás mivel a Kedd is string constans

    //Két dimenziós karakter tömb:
    char t[][20]={"Hetfo","Kedd","Szerda"},ch2;
    printf("%s\n",t[2]);
    //s[2]="Vasarnap"; TILOS mivel s[2] konstans pointer
    ch2=t[0][2];
    printf("%c\n",ch2);
    t[0][3]='X'; //Ez itt mûködik
    printf("%s\n",t[0]);
    strcpy(t[1],"Szombat"); //Itt is mûködik
    printf("%s\n",t[1]);

    return 0;
}
