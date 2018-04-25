#include <stdio.h>
#include <stdlib.h>

void hibaellenor (void *p)
{
    if (p==NULL)
    {
        fprintf(stderr,"Nem sikerult az allokacio!");
        exit(1);
    }
}
int main()
{
    int M,N,i,j;
    double **tomb;

    printf("M= ");
    scanf("%d",&M);
    printf("\nN= ");
    scanf("%d",&N);

    tomb=(double**)calloc(M,sizeof(double*));
    hibaellenor(tomb);

    for(i=0;i<M;i++)
    {
        tomb[i]=(double*)calloc(N,sizeof(double));
        hibaellenor(tomb[i]);
    }

    for(i=0;i<M;i++)
    {
        for (j=0;j<N;j++)
        {
            tomb[i][j]=0.1*i*j;
        }
    }

    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
        printf("t[%d][%d]=%10g\n",i,j,tomb[i][j]);

    for (i=0;i<M;i++) free(tomb[i]);

    free(tomb);

    return 0;
}
