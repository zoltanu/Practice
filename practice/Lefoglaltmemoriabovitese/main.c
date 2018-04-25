#include <stdio.h>
#include <stdlib.h>

double* ujrafoglal(double *t,int M, int N)
{
    double *v;
    unsigned i, min=M<N?M:N;

    v=(double*)calloc(N,sizeof(double));
    if (v==NULL)return NULL;
    for (i=0;i<min;i++)
        v[i]=t[i];
    free(t);
    return v;
}

void hiba (char* s)
{
    fprintf(stderr,"%s\n",s);
    exit(1);
}

int main()
{
    double * t;
    t=(double*)malloc(100*sizeof(double));
    if(t==NULL)hiba("Memoriafoglalas");

    t=ujrafoglal(t,100,200);
    if(t==NULL)hiba("Memoriafoglalas");

    t=ujrafoglal(t,200,50);
    if(t==NULL)hiba("Memoriafoglalas");

    free(t);

    return 0;
}
