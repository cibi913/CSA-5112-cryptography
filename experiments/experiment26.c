
#include <stdio.h>

int main()
{
    int n, old_d, new_e, new_d;

    printf("Enter RSA modulus: ");
    scanf("%d",&n);

    printf("Enter leaked private key: ");
    scanf("%d",&old_d);

    printf("Enter new public exponent: ");
    scanf("%d",&new_e);

    printf("\nRSA Security Analysis\n");

    printf("Original modulus = %d\n",n);
    printf("Leaked private key = %d\n",old_d);
    printf("New public exponent = %d\n",new_e);

    printf("\nGenerating a new key pair with the same modulus is unsafe.\n");
    printf("The attacker may recover the factors of n using the leaked key.\n");
    printf("A completely new modulus must be generated.\n");

    return 0;
}
