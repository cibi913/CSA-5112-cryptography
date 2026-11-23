
#include <stdio.h>

int power(int a, int b, int q)
{
    int result = 1;

    for(int i = 0; i < b; i++)
        result = (result * a) % q;

    return result;
}

int main()
{
    int q, a, x, y;
    int A, B, key1, key2;

    printf("Enter prime number q: ");
    scanf("%d",&q);

    printf("Enter public number a: ");
    scanf("%d",&a);

    printf("Enter Alice secret number: ");
    scanf("%d",&x);

    printf("Enter Bob secret number: ");
    scanf("%d",&y);

    A = power(a,x,q);
    B = power(a,y,q);

    key1 = power(B,x,q);
    key2 = power(A,y,q);

    printf("\nAlice sends: %d\n",A);
    printf("Bob sends: %d\n",B);

    printf("Alice shared key: %d\n",key1);
    printf("Bob shared key: %d\n",key2);

    if(key1 == key2)
        printf("Shared key established successfully.\n");

    printf("\nSecurity depends on the difficulty of the discrete logarithm problem.\n");

    return 0;
}
