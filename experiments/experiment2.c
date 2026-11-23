#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;

    printf("Enter the plaintext: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = key[str[i] - 'A'];

        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = key[str[i] - 'a'] + 32;
    }

    printf("Encrypted text: %s", str);

    return 0;
}
