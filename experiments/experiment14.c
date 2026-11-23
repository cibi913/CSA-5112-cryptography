
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char p[] = "send more money";
    char target[] = "cash not needed";
    int key[] = {9,0,1,7,23,15,21,14,11,11,2,8,9};
    int cipher[13], newkey[13];
    int i, j = 0;

    printf("Encrypted text: ");

    for(i = 0; p[i] != '\0'; i++)
    {
        if(isalpha(p[i]))
        {
            cipher[j] = (tolower(p[i])-'a'+key[j])%26;
            printf("%c", cipher[j]+'a');
            j++;
        }
        else
            printf("%c", p[i]);
    }

    printf("\n");

    printf("New key for target plaintext:\n");

    j = 0;
    for(i = 0; p[i] != '\0'; i++)
    {
        if(isalpha(p[i]))
        {
            newkey[j] = (cipher[j]-(target[i]-'a')+26)%26;
            printf("%d ", newkey[j]);
            j++;
        }
    }

    return 0;
}
