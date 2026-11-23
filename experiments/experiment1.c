#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int k, i;

    printf("Enter the plaintext: ");
    gets(str);

    printf("Enter the key (1-25): ");
    scanf("%d", &k);

    if (k < 1 || k > 25)
    {
        printf("Invalid key");
        return 0;
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = (str[i] - 'A' + k) % 26 + 'A';

        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (str[i] - 'a' + k) % 26 + 'a';
    }

    printf("Encrypted text: %s", str);

    return 0;
}
