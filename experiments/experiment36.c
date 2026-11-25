#include <stdio.h>

int main()
{
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter values of a and b: ");
    scanf("%d%d", &a, &b);

    if(a < 0 || a > 25 || b < 0 || b > 25)
    {
        printf("Invalid key");
        return 0;
    }

    if(a % 2 == 0 || a == 13)
    {
        printf("Invalid key: a must be coprime with 26");
        return 0;
    }

    printf("Encrypted text: ");
    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
            printf("%c", ((a * (text[i] - 'A') + b) % 26) + 'A');
        else
            printf("%c", text[i]);
    }

    return 0;
}
