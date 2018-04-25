#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A=1, B=0;
    printf("Most pedig kiirjuk az osszes olyan\nharomejgyu szamot amelyek oda-vissza\nugyanugy neznek ki.");
    while (A<10)
    {
        while(B<10)
        {
           printf("%d%d%d\n",A,B,A);
           B++;
        }
        A++;
        B=0;
    }



    return 0;
}
