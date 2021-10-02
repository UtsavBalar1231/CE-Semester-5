// Bubble sort algorithm with execution time
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void sort(int arr[], int n) {
    int i, j, swap;
    bool is_sorted = false;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
                is_sorted = true;
            }
            if (!is_sorted)
                return;
        }
    }
}

int main() {
    clock_t t;
    int height[10] = {
        89,
        42,
        100,
        93,
        11,
        234,
        30,
        82,
        22,
        75
    };
    int n = (sizeof(height) / sizeof(height[0]));
    printf("Input Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", height[i]);
    t = clock();
    sort(height, n);
    t = clock() - t;
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", height[i]);
    printf("\nTime Taken to execute: (%f seconds).\n",
            ((float) t) / CLOCKS_PER_SEC);

    return 0;
}


