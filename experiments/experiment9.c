#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], key[100];
    int i;

    printf("Enter ciphertext: ");
    scanf("%99s", text);

    printf("Enter 25-letter decryption key: ");
    scanf("%99s", key);

    printf("Ciphertext: %s\n", text);
    printf("Key: %s\n", key);

    printf("Use Playfair decryption rules:\n");
    printf("1. Same row: Move one position left.\n");
    printf("2. Same column: Move one position up.\n");
    printf("3. Rectangle: Exchange column positions.\n");

    return 0;
}
