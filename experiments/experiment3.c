#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char key[30], text[100], matrix[5][5];
    int i, j, k, r1, c1, r2, c2, used[26] = {0};

    printf("Enter keyword: ");
    scanf("%s", key);

    printf("Enter plaintext: ");
    scanf(" %[^\n]", text);

    k = 0;

    for (i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);
        if (ch == 'J') ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (i == 9) continue;

        if (!used[i])
        {
            matrix[k / 5][k % 5] = 'A' + i;
            k++;
        }
    }

    char p[100];
    j = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char ch = toupper(text[i]);
            if (ch == 'J') ch = 'I';
            p[j++] = ch;
        }
    }

    p[j] = '\0';

    char result[200];
    k = 0;

    for (i = 0; i < j; i += 2)
    {
        char a = p[i];
        char b = (i + 1 < j) ? p[i + 1] : 'X';

        if (a == b)
        {
            b = 'X';
            i--;
        }

        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 5; y++)
            {
                if (matrix[x][y] == a)
                    r1 = x, c1 = y;
                if (matrix[x][y] == b)
                    r2 = x, c2 = y;
            }

        if (r1 == r2)
        {
            result[k++] = matrix[r1][(c1 + 1) % 5];
            result[k++] = matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            result[k++] = matrix[(r1 + 1) % 5][c1];
            result[k++] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            result[k++] = matrix[r1][c2];
            result[k++] = matrix[r2][c1];
        }
    }

    result[k] = '\0';

    printf("Encrypted text: %s", result);

    return 0;
}
