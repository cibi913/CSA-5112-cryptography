
#include <stdio.h>

int gcd(int a, int b)
{
    while(b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int n, e, c, factor;

    printf("Enter RSA modulus n: ");
    scanf("%d",&n);

    printf("Enter public exponent e: ");
    scanf("%d",&e);

    printf("Enter ciphertext c: ");
    scanf("%d",&c);

    factor = gcd(c,n);

    if(factor > 1 && factor < n)
    {
        printf("Common factor found = %d\n",factor);
        printf("RSA modulus can be factored!\n");
        printf("Other factor = %d\n",n/factor);
    }
    else
    {
        printf("No non-trivial common factor found.\n");
    }

    return 0;
}
