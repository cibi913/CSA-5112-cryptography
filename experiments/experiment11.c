#include <stdio.h>
#include <math.h>

int main()
{
    long double keys = 1;
    int i;

    for (i = 1; i <= 25; i++)
    {
        keys = keys * i;
    }

    printf("Total possible Playfair keys = %.0Lf\n", keys);
    printf("Approximate power of 2 = 2^%.2Lf\n",
           log2l(keys));

    return 0;
}
