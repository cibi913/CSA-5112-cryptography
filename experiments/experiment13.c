
#include <stdio.h>

int main()
{
    int p[2][2], c[2][2], inv[2][2];
    int det, d, i, j;
    
    printf("Enter 4 plaintext values (0-25):\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &p[i][j]);

    printf("Enter corresponding ciphertext values:\n");
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
            scanf("%d", &c[i][j]);

    det = (p[0][0]*p[1][1] - p[0][1]*p[1][0]) % 26;
    if(det < 0) det += 26;

    for(d = 1; d < 26; d++)
        if((det*d)%26 == 1)
            break;

    if(d == 26)
    {
        printf("Inverse does not exist.\n");
        return 0;
    }

    inv[0][0] = (p[1][1]*d)%26;
    inv[0][1] = (-p[0][1]*d%26+26)%26;
    inv[1][0] = (-p[1][0]*d%26+26)%26;
    inv[1][1] = (p[0][0]*d)%26;

    printf("Recovered Hill cipher key:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            int key = (c[i][0]*inv[0][j] +
                       c[i][1]*inv[1][j]) % 26;
            printf("%d ", key);
        }
        printf("\n");
    }

    return 0;
}
