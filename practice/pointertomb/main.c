#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    int *t[4]={&a,&b,&c,&d};
    *t[1]=5;
    **t=2;
    *t[2]=3;
    **(t+3)=8;


    int i;
    for (i=0;i<4;i++)
    printf("t[%d]=%d\n",i,*t[i]);
    return 0;
}
