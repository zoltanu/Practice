#include <stdio.h>
#include <stdlib.h>

//Itt pointer átadása volt a lényeg

int keres (int tomb[], int n, int mit, int **cim)
{
    int i;
    for (i=0;i<n;i++)
    {
        if (tomb[i]==mit)
        {
            *cim=tomb+i;
            return 1;
        }

    }
    *cim=NULL;
    return 0;
}

int main()
{
    int tomb[]={1,2,3,4,5,6,7,-10};
    int mit= 8;
    int * cim;
    if (keres(tomb,8,mit,&cim)) printf("Benne van!\n");
    else printf("Nincs benne!\n");
    return 0;
}
