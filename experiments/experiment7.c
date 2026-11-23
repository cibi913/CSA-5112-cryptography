#include <stdio.h>

int main()
{
    char text[500];
    char key[27];
    int i;

    printf("Enter ciphertext:\n");
    fgets(text, sizeof(text), stdin);

    printf("Enter decryption key (26 letters): ");
    scanf("%26s", key);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = key[text[i] - 'A'];
    }

    printf("Decrypted text:\n%s", text);

    return 0;
}
