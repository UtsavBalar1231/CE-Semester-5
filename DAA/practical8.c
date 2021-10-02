#include <stdio.h>
#include <string.h>

#define max(x, y) (x) > (y) ? (x) : (y)

#define len(arr) ((int)(sizeof(arr) / sizeof(arr)[0]))

char X[] = "ABCBDAB";
char Y[] = "BDCABA";
int n = 24;
int m = 24;
int c[25][25];
char b[25][25];

int lcs_length(char *X, char *Y)
{
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
            c[i][j] = 0;

    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < m + 1; j++)
            b[i][j] = '0';

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'd';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }

    // for (int i = 0; i < strlen(X) + 1; i++)
    // {
    //     for (int j = 0; j < strlen(Y) + 1; j++)
    //     {
    //         printf("%d  ", c[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");

    // for (int i = 0; i < strlen(X) + 1; i++)
    // {
    //     for (int j = 0; j < strlen(Y) + 1; j++)
    //     {
    //         printf("%c  ", b[i][j]);
    //     }
    //     printf("\n");
    // }

    return c[n][m];
}

void print_lcs(int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == 'd')
    {
        print_lcs(i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (b[i][j] == 'u')
    {
        print_lcs(i - 1, j);
    }
    else if (b[i][j] == 'l')
    {
        print_lcs(i, j - 1);
    }
    else
    {
        return;
    }
}

void main()
{
    int lcs = lcs_length(X, Y);
    printf("LCS length of %s and %s is %d ", X, Y, lcs);

    printf("\nLCS is: ");
    print_lcs(strlen(X), strlen(Y));
}