#include <stdio.h>

int main()
{
    char text[500];
    int i, key;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    printf("\nPossible plaintexts:\n");

    for(key = 0; key < 26; key++)
    {
        printf("\nKey %d: ", key);

        for(i = 0; text[i] != '\0'; i++)
        {
            if(text[i] >= 'A' && text[i] <= 'Z')
                printf("%c", (text[i] - 'A' - key + 26) % 26 + 'A');
            else if(text[i] >= 'a' && text[i] <= 'z')
                printf("%c", (text[i] - 'a' - key + 26) % 26 + 'a');
            else
                printf("%c", text[i]);
        }
    }

    return 0;
}
