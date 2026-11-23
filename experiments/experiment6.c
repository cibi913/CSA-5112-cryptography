#include <stdio.h>

int main()
{
    char text[100];
    int i;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 'B')
            text[i] = 'E';
        else if (text[i] == 'U')
            text[i] = 'T';
    }

    printf("Possible plaintext: %s", text);

    return 0;
}
