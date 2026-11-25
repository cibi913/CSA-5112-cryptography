#include <stdio.h>
#include <string.h>

int main()
{
    char text[500];
    char alphabet[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0};
    int i, j, temp;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            count[text[i] - 'A']++;
        else if(text[i] >= 'a' && text[i] <= 'z')
            count[text[i] - 'a']++;
    }

    for(i = 0; i < 26; i++)
    {
        for(j = i + 1; j < 26; j++)
        {
            if(count[i] < count[j])
            {
                temp = count[i];
                count[i] = count[j];
                count[j] = temp;

                temp = alphabet[i];
                alphabet[i] = alphabet[j];
                alphabet[j] = temp;
            }
        }
    }

    printf("\nFrequency order of letters:\n");
    for(i = 0; i < 26; i++)
        printf("%c ", alphabet[i]);

    printf("\n");

    return 0;
}
