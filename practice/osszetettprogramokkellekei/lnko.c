#include "lnko.h"

unsigned lnko(unsigned a, unsigned b)
{
    unsigned i=a<b?a:b;
    for(;i>1;i--)
    {
        if (a%i==0 && b%i==0) return i;
    }
    return 1;
}
