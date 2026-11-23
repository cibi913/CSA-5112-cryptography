#include <stdio.h>

int main()
{
    char matrix[5][5] = {
        {'M','F','H','I','K'},
        {'U','N','O','P','Q'},
        {'Z','V','W','X','Y'},
        {'E','L','A','R','G'},
        {'D','S','T','B','C'}
    };

    char text[100];
    int i, j, r1, c1, r2, c2;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Playfair matrix:\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);

        printf("\n");
    }

    printf("Plaintext: %s", text);

    printf("\nUse the matrix to encrypt two letters at a time.");

    return 0;
}
