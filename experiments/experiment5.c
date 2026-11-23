#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((a * (text[i] - 'A') + b) % 26) + 'A';

        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((a * (text[i] - 'a') + b) % 26) + 'a';
    }

    printf("Encrypted text: %s", text);

    return 0;
}
