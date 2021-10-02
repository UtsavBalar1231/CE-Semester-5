#include <stdio.h>

#define min(x, y) ((x) < (y) ? (x) : (y))
#define MAX 999999

/**
 * coin_change - Making coin change algorithm using dynamic programming
 * @d:   pointer for list of available coins
 * @N:   Total amount given
 * @n:   Total No. of different coins available
 */
int coin_change(int *d, int N, int n)
{
    int c[n][N + 1];
    int i = 0, j = 0;

    // Initialize whole 2-D array to 0
    for (i = 0; i < n; i++)
        for (j = 0; j < N + 1; j++)
            c[i][j] = 0;

    // Set column 1 [j=0] as 0
    for (i = 0; i < n; i++)
        c[i][0] = 0;

    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < N + 1; j++)
        {
            if (i == 1 && j < d[i - 1])
                c[i - 1][j] = MAX;
            else if (i == 1)
            {
                c[i - 1][j] = (1 + c[i - 1][j - d[i - 1]]);
            }
            else if (j < d[i - 1])
            {
                c[i - 1][j] = c[(i - 1) - 1][j];
            }
            else
            {
                c[i - 1][j] += min(c[(i - 1) - 1][j], 1 + c[i - 1][j - d[i - 1]]);
            }
        }
    }

    // for (i = 0; i < n; i++)
    // {
    //     printf("i = %d\td[i] = %d\t", i, d[i]);
    //     for (j = 0; j < N + 1; j++)
    //     {
    //         printf("c[%d][%d]=%d\t", i, j, c[i][j]);
    //     }
    //     printf("\n");
    // }

    return c[n - 1][N];
}

/**
 * swap - Swapping algorithm
 * @x:      Number 1
 * @y:      Number 2
 */
void swap(int *x, int *y)
{
    float temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * partition - Function to partition array and return the pivot element index
 * @arr:    The required Array to sort
 * @start:  Starting index of the array to sort
 * @end:    Ending index of the array to sort
 */
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pindex = start - 1;

    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            pindex++;
            swap(&arr[i], &arr[pindex]);
        }
    }
    swap(&arr[pindex + 1], &arr[end]);

    return pindex + 1;
}

/**
 * quicksort - Function to sort an array using quicksort algorithm
 * @arr:    The required Array to sort
 * @start:  Starting index of the array to sort
 * @end:    Ending index of the array to sort
 */
void quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pindex = partition(arr, start, end);

        quicksort(arr, start, pindex - 1);
        quicksort(arr, pindex + 1, end);
    }
}

int main()
{
    int d[] = {500, 100, 50, 20, 10, 1};
    int N = 732;
    int n = sizeof(d) / sizeof(d[0]);

    // Why quicksort?: Provides Best time complexity for average case
    quicksort(d, 0, n - 1);

    printf("\nNo. of coins required are: %d\n", coin_change(d, N, n));

    return 0;
}