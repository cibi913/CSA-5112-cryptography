#include <stdio.h>
#include <string.h>

int main()
{
    char text[500];
    char freq[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26] = {0};
    int i, j, top;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter number of possible plaintexts: ");
    scanf("%d", &top);

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            count[text[i] - 'A']++;
        else if(text[i] >= 'a' && text[i] <= 'z')
            count[text[i] - 'a']++;
    }

    printf("\nPossible plaintexts:\n");

    for(j = 0; j < top && j < 26; j++)
    {
        printf("\nPossibility %d: ", j + 1);

        for(i = 0; text[i] != '\0'; i++)
        {
            if(text[i] >= 'A' && text[i] <= 'Z')
                printf("%c", freq[j]);
            else if(text[i] >= 'a' && text[i] <= 'z')
                printf("%c", freq[j] + 32);
            else
                printf("%c", text[i]);
        }
    }

    return 0;
}
