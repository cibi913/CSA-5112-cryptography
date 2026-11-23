
#include <stdio.h>
#include <string.h>

#define SIZE 8

void pad(char text[], int *len)
{
    int i;
    text[(*len)++] = 0x80;

    while(*len % SIZE != 0)
        text[(*len)++] = 0x00;
}

int main()
{
    unsigned char text[100] = "HELLO WORLD";
    int len = strlen((char *)text);

    pad((char *)text, &len);

    printf("Padded plaintext:\n");

    for(int i = 0; i < len; i++)
        printf("%02X ", text[i]);

    printf("\n\nECB, CBC and CFB modes require complete blocks.\n");

    printf("Padding adds a full block even when needed.\n");
    printf("It helps identify the true message ending and prevents\n");
    printf("ambiguity about whether the final block was padded.\n");

    return 0;
}
