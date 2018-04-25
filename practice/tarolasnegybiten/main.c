#include <stdio.h>
#include <stdlib.h>

unsigned char beolvas(int mit, int hova, unsigned char mibe)
{
    mit&=0x0f;
    switch (hova)
    {
        case 0: return (mibe & 0xf0)| mit;
        case 1: return (mibe & 0x0f)|(mit <<4);
    }

    return 0;
}

int kiolvas (int honnan, unsigned char mibol)
{
    switch (honnan)
        {
        case 0: return mibol & 0x0f;
        case 1: return (mibol & 0xf0)>>4;
        }
    return 0;
}

int main()
{
    printf("Maszkoljunk!\n\n");

    int be1=11,be2=6;
unsigned char tarolo;
tarolo=beolvas(be1,0,0);
tarolo=beolvas(be2,1,tarolo);
printf("Tarolo=%hhu\n",tarolo);
printf("ki1=%d\n",kiolvas(0,tarolo));
printf("ki2=%d\n",kiolvas(1,tarolo));

    return 0;
}
