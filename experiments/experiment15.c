
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cipher[500];
    int freq[26] = {0};
    int i, j, k, max;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    for(i = 0; cipher[i] != '\0'; i++)
        if(isalpha(cipher[i]))
            freq[tolower(cipher[i])-'a']++;

    for(i = 0; i < 26; i++)
        for(j = i+1; j < 26; j++)
            if(freq[j] > freq[i])
            {
                max = freq[i];
                freq[i] = freq[j];
                freq[j] = max;
            }

    printf("\nPossible plaintexts:\n");

    for(k = 0; k < 10; k++)
    {
        printf("\nShift %d: ", k);

        for(i = 0; cipher[i] != '\0'; i++)
        {
            if(isalpha(cipher[i]))
            {
                char ch = tolower(cipher[i]);
                printf("%c", (ch-'a'-k+26)%26+'a');
            }
            else
                printf("%c", cipher[i]);
        }
    }

    return 0;
}
