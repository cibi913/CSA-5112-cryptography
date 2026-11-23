
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[] = "meet me at the usual place at ten rather than eight oclock";
    char p[100], c[100], d[100];
    int i, n = 0, a, b;
    int k[2][2] = {{9, 4}, {5, 7}};
    int inv[2][2] = {{5, 12}, {13, 25}};

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
            p[n++] = tolower(text[i]) - 'a';
    }

    if (n % 2 != 0)
        p[n++] = 'x' - 'a';

    for (i = 0; i < n; i += 2)
    {
        a = p[i];
        b = p[i + 1];

        c[i] = (k[0][0] * a + k[0][1] * b) % 26;
        c[i + 1] = (k[1][0] * a + k[1][1] * b) % 26;
    }

    printf("Encrypted text: ");
    for (i = 0; i < n; i++)
        printf("%c", c[i] + 'a');

    for (i = 0; i < n; i += 2)
    {
        a = c[i];
        b = c[i + 1];

        d[i] = (inv[0][0] * a + inv[0][1] * b) % 26;
        d[i + 1] = (inv[1][0] * a + inv[1][1] * b) % 26;
    }

    printf("\nDecrypted text: ");
    for (i = 0; i < n; i++)
        printf("%c", d[i] + 'a');

    return 0;
}
