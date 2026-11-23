
#include <stdio.h>

int power(int a, int b, int n)
{
    int result = 1;

    while(b > 0)
    {
        result = (result * a) % n;
        b--;
    }

    return result;
}

int main()
{
    int e, n, i, c;

    printf("Enter public exponent: ");
    scanf("%d",&e);

    printf("Enter modulus: ");
    scanf("%d",&n);

    printf("\nCharacter\tEncrypted Value\n");

    for(i = 0; i < 26; i++)
    {
        c = power(i,e,n);
        printf("%c\t\t%d\n",'A'+i,c);
    }

    printf("\nAttack: Each character has only 26 possible values.\n");
    printf("An attacker can create a lookup table and identify plaintext.\n");

    return 0;
}
