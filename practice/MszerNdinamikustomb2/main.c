#include <stdio.h>
#include <stdlib.h>

void hibaellenor(double*p)
{
    if (p==NULL)
    {
        fprintf(stderr,"Sikertelen allokacio!");
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
    scanf("%d", &N);

    tomb=(double**)calloc(M,sizeof(double*));
    hibaellenor(tomb);

    tomb[0]=(double*)calloc(M*N,sizeof(double));
    hibaellenor(tomb[0]);
    for(i=0;i<M;i++)
        tomb[i]=tomb[0]+N*i;

    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
        tomb[i][j]=0.1*i*j;

    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
        printf("Tomb[%d][%d]=%5g\n",i,j,tomb[i][j]);

    free(tomb[i]);
    free(tomb);



    return 0;
}
