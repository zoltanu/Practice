#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Pointer t�mb:
    char *s[]={"Hetfo","Kedd","Szerda"},ch;
    printf("%s\n",s[2]);
    s[2]="Vasarnap"; //Itt pointer m�sol�s t�rt�nik, ez�rt m�k�dhet
    printf("%s\n",s[2]);
    ch=s[0][2];
    //s[0][3]='X' ->Hib�s mivel a H�tf� string constans
    //strcpy(s[1],"Szombat"); ->Hib�s mivel a Kedd is string constans

    //K�t dimenzi�s karakter t�mb:
    char t[][20]={"Hetfo","Kedd","Szerda"},ch2;
    printf("%s\n",t[2]);
    //s[2]="Vasarnap"; TILOS mivel s[2] konstans pointer
    ch2=t[0][2];
    printf("%c\n",ch2);
    t[0][3]='X'; //Ez itt m�k�dik
    printf("%s\n",t[0]);
    strcpy(t[1],"Szombat"); //Itt is m�k�dik
    printf("%s\n",t[1]);

    return 0;
}
