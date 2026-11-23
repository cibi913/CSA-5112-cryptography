
#include <stdio.h>

int main()
{
    int message = 25;
    int privateKey = 7;
    int k1 = 3, k2 = 5;
    int signature1, signature2;

    signature1 = (message + privateKey * k1) % 101;
    signature2 = (message + privateKey * k2) % 101;

    printf("Message = %d\n", message);

    printf("\nDSA-style randomized signatures:\n");
    printf("First signature = %d\n", signature1);
    printf("Second signature = %d\n", signature2);

    printf("\nRSA deterministic signature concept:\n");
    printf("Same message and key produce the same signature\n");
    printf("when deterministic RSA signing is used.\n");

    return 0;
}
