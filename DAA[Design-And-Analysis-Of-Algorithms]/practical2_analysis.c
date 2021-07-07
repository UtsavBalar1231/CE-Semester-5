// Time complexivity analysis of bubble sort algorithm
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Created macro for Random number generation
#define randnum(min, max)\
    ((rand() % (int)(((max) + 1) - (min))) + (min))

// Function to sort Array using bubble sort algorithm
void sort(int arr[], int n) {
    int i, j;
    // is_swaped: check whether any swap took place in the previous iteration.
    // If yes, only then the next iteration takes place.
    // If no, then the loop breaks.
    bool is_swapped;
    for (i = 0; i < n - 1; i++) { // n-1 = end value of array
        is_swapped = false;
        for (j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) { // Compare index with index+1 value and swap if index > index+1
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                is_swapped = true;
            }
        }
        if (!is_swapped) // Break if the array is already sorted
            break;
    }
}

// Function to print array
void printarr(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    clock_t t1, t2, t3;
    int start = 1, end, i, temp, r;
    printf("Enter the largest number for array: ");
    scanf("%d", &end);
    int size = end - start + 1;
    int arr[size];

    // Fill array with numbers in range (start, end)
    for (temp = 0, i = start; temp < size; i++, temp++)
        arr[temp] = i;

    // To avoid repetition with each run
    srand((unsigned int) time(NULL));

    // Store all the random numbers in Array arr[]
    for (i = size - 1; i > 0; i--) {
        r = randnum(start, end);
        temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
    }

    printf("Unsorted Array: (Average Case): \n");
    printarr(arr, size);

    t1 = clock();
    sort(arr, size);
    t1 = clock() - t1;
    printf("\nSorted Array: (Average Case): \n");
    printarr(arr, size);

    t2 = clock();
    sort(arr, size);
    t2 = clock() - t2;
    printf("\nSorted Array: (Best Case): \n");
    printarr(arr, size);

    // Reverse the numbers in Array arr[]
    int tmp = 0, x = 0, y = size - 1; // End value of array
    while (x < y) {
        tmp = arr[x];
        arr[x] = arr[y];
        arr[y] = tmp;
        x++;
        y--;
    }

    printf("\nUnsorted Array: (Worst Case): \n");
    printarr(arr, size);

    t3 = clock();
    sort(arr, size);
    t3 = clock() - t2;
    printf("\nSorted Array: (Worst Case): \n");
    printarr(arr, size);

    printf("\nTime Taken to execute for\n"
        "Average Case\t: (%f seconds)\n"
        "Best Case\t: (%f seconds)\n"
        "Worst Case\t: (%f seconds)\n",
        (((float) t1) / CLOCKS_PER_SEC),
        (((float) t2) / CLOCKS_PER_SEC),
        (((float) t3) / CLOCKS_PER_SEC));

    return 0;
}
