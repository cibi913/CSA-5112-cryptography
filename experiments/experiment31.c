
#include <stdio.h>
#include <stdint.h>

int main()
{
    uint64_t L, K1, K2;
    uint64_t Rb64 = 0x1B;

    printf("Enter 64-bit hexadecimal block: ");
    scanf("%llx", (unsigned long long *)&L);

    K1 = L << 1;
    if(L >> 63)
        K1 ^= Rb64;

    K2 = K1 << 1;
    if(K1 >> 63)
        K2 ^= Rb64;

    printf("\n64-bit CMAC Subkeys:\n");
    printf("K1 = %016llX\n", (unsigned long long)K1);
    printf("K2 = %016llX\n", (unsigned long long)K2);

    printf("\nConstants:\n");
    printf("64-bit block: 0x1B\n");
    printf("128-bit block: 0x87\n");

    printf("\nLeft shift multiplies the value by 2.\n");
    printf("XOR with the constant performs reduction modulo the\n");
    printf("CMAC block-size polynomial.\n");

    return 0;
}
