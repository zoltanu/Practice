#include <stdio.h>
#include <stdlib.h>

void csere (int *a,int *b)
{
    int c = *a;
    *a=*b;
    *b=c;
}

int main()
{
    int a=2;
    int b=5;
    printf("A szamok eredetileg: a=%i, b=%i\n\n",a,b);
    csere(&a,&b);

    printf("A csere utan pedig: a=%i, b=%i\n", a, b);
    return 0;
}
