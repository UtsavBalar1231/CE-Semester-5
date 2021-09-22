#include <stdio.h>
#include <string.h>

int m, n;

void print(int b[8][5], int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 3)
        printf("b: %d", b[i][j]);

    // if (b[i][j] == 'c')
    // {
    //     print(i - 1, j - 1);
    //     printf("%c", x[i - 1]);
    // }
    // else if (b[i][j] == 'u')
    //     print(i - 1, j);
    // else
    //     print(i, j - 1);
}

void lcs()
{
    char x[] = "ABBCDA";
    char y[] = "ABCD";
    int m = strlen(x);
    int n = strlen(y);
    int c[m + 1][n + 1];
    int b[m + 1][n + 1];

    for (int i = 0; i < m; i++)
        c[i][0] = 0;
    for (int j = 0; j < n; j++)
        c[0][j] = 0;

    //c, u and l denotes cross, upward and downward directions respectively
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (x[i] == y[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 2;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 3;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; i < n; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    printf("LCS = %d\n", c[m][n]);
    // printf("c[i][j]=%d\n", c[m][n])
    print(b, m, n);
}

int main()
{
    printf("\nThe Longest Common Subsequence is ");
    lcs();
    return 0;
}