
#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[500];
    char freq[] = "etaoinshrdlcumwfgypbvkjxqz";
    int count[26] = {0};
    int i, j, max, index;
    char temp;

    printf("Enter ciphertext: ");
    fgets(text, sizeof(text), stdin);

    for(i = 0; text[i] != '\0'; i++)
        if(isalpha(text[i]))
            count[tolower(text[i])-'a']++;

    char order[] = "abcdefghijklmnopqrstuvwxyz";

    for(i = 0; i < 26; i++)
        for(j = i+1; j < 26; j++)
            if(count[order[j]-'a'] > count[order[i]-'a'])
            {
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }

    printf("\nPossible plaintext:\n");

    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            index = 0;
            while(index < 26 && order[index] != tolower(text[i]))
                index++;

            if(index < 26)
            {
                char ch = freq[index];
                if(isupper(text[i]))
                    ch = toupper(ch);
                printf("%c", ch);
            }
        }
        else
            printf("%c", text[i]);
    }

    return 0;
}
