#include <stdio.h>

int main()
{
    int k[2][2], p[2][2], c[2][2];
    int i, j, det;

    printf("Enter 2x2 key matrix:\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &k[i][j]);

    printf("Enter plaintext matrix:\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &p[i][j]);

    det = k[0][0] * k[1][1] - k[0][1] * k[1][0];

    printf("Encrypted matrix:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            c[i][j] = 0;

            for(int x = 0; x < 2; x++)
                c[i][j] += k[i][x] * p[x][j];

            c[i][j] %= 26;
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("Determinant = %d", det);

    return 0;
}
