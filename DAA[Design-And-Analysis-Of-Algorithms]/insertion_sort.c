#include <stdio.h>

void pr_arr(int arr[], int n);

void sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        printf("Iteration #%d:\n", i);

        int k = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j--;
            printf("key/hole is: %d\nkey[%d] < j[%d]\n", k, k, arr[j + 1]);

            printf("Item moved: %d\n", arr[j + 1]);
        }

        arr[j + 1] = k;
        printf("Item inserted: %d at position: %d\n", k, j + 1);
        pr_arr(arr, n);
        printf("___________________________________________________\n\n");
    }
}

void pr_arr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d \t", arr[i]);
    printf("\n");
}

void main()
{
    int arr[5] = {4, 3, 1, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array:\n");
    pr_arr(arr, n);
    sort(arr, n);
    printf("Sorted Array:\n");
    pr_arr(arr, n);
}
