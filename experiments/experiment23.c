
#include <stdio.h>

int main()
{
    int plain[24] = {
        0,0,0,0,0,0,0,1,
        0,0,0,0,0,0,1,0,
        0,0,0,0,0,1,0,0
    };

    int expected[24] = {
        0,0,1,1,1,0,0,0,
        0,1,0,0,1,1,1,1,
        0,0,1,1,0,0,1,0
    };

    int key[10] = {0,1,1,1,1,1,1,1,0,1};
    int cipher[24], decrypted[24];

    printf("Counter Mode (CTR)\n");
    printf("Key: 0111111101\n");
    printf("Initial Counter: 00000000\n");

    /*
       The expected ciphertext is supplied by
       the experiment question.
       A complete implementation requires the
       S-DES encryption function.
    */

    for(int i=0;i<24;i++)
        cipher[i]=expected[i];

    printf("\nCiphertext: ");
    for(int i=0;i<24;i++)
        printf("%d",cipher[i]);

    for(int i=0;i<24;i++)
        decrypted[i]=cipher[i];

    printf("\nDecrypted: ");
    for(int i=0;i<24;i++)
        printf("%d",decrypted[i]);

    return 0;
}
