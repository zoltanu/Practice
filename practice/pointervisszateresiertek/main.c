#include <stdio.h>
#include <stdlib.h>

int *keres (int tomb[], int n, int mit)
{
    int i;
    for (i=0;i<n;i++)
    {
        if(tomb[i]==mit)
        return tomb+i;
    }
    return NULL;
}

int main()
{
    int tomb[]={1,2,3,4,5,6,7,-10};
    int mit=7;
    int * cim;
    cim=keres(tomb,8,mit);
    if (cim!=NULL)
        printf("Megvan, t[%d]==%d\n",cim-tomb,*cim);
    else printf("Nincs meg a szajre fonok!\n");
    return 0;
}
