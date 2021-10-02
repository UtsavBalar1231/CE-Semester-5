// quick sort algorithm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Created macro for Random number generation
#define randnum(min, max) \
    ((rand() % (int)(((max) + 1) - (min))) + (min))

// Function to swap two numbers
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to partition array and return the pivot element index
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pindex = start - 1;
    int i;

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

// Function to sort an array using quicksort algorithm
void quicksort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pindex = partition(arr, start, end);

        quicksort(arr, start, pindex - 1);
        quicksort(arr, pindex + 1, end);
    }
}

// Function to all the elements in an array
void printArr(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main()
{
    // clock variables to store execution time for each case
    clock_t t1, t2, t3;
    int size = 100, i, temp = 0, r;
    int *array;

    // Set the size as your input size
    array = calloc(sizeof(int) * size);
    if (array == NULL)
    {
        printf("malloc of size %d failed!\n", size);
        return -1;
    }

    // Fill array with numbers in range (1, size)
    for (temp = 0, i = 1; temp < size; i++, temp++)
        array[temp] = i;

    // To avoid repetition with each run
    srand((unsigned int)time(NULL));

    // Store all the random numbers in the array
    for (i = size - 1; i > 0; i--)
    {
        r = randnum(1, size);
        swap(&array[i], &array[r]);
    }

    /*
     * Average Case
     */

    printf("\nUnsorted Array:(Average Case) \t");
    printArr(array, size);

    // Start measuring time
    t1 = clock();
    // Call quicksort() function
    quicksort(array, 0, size - 1);
    // Stop measuring time and calculate the elapsed time
    t1 = clock() - t1;

    printf("Sorted Array:(Average Case) \t");
    printArr(array, size);

    /*
     * Best Case
     */

    printf("\nUnsorted Array:(Best Case) \t");
    printArr(array, size);

    // Start measuring time
    t2 = clock();
    // Call quicksort() function
    quicksort(array, 0, size - 1);
    // Stop measuring time and calculate the elapsed time
    t2 = clock() - t2;

    printf("Sorted Array:(Best Case) \t");
    printArr(array, size);

    /*
     * Worst Case
     */

    // Reverse the numbers in Array arr[]
    int x = 0, y = size - 1; // End value of array
    while (x < y)
    {
        swap(&array[x], &array[y]);
        x++;
        y--;
    }

    printf("\nUnsorted Array:(Worst Case) \t");
    printArr(array, size);

    // Start measuring time
    t3 = clock();
    // Call quicksort() function
    quicksort(array, 0, size - 1);
    // Stop measuring time and calculate the elapsed time
    t3 = clock() - t3;

    printf("Sorted Array:(Worst Case) \t");
    printArr(array, size);

    printf("\nTime Taken to execute for\n"
           "Average Case\t: (%f seconds)\n"
           "Best Case\t: (%f seconds)\n"
           "Worst Case\t: (%f seconds)\n",
           (((float)t1) / CLOCKS_PER_SEC),
           (((float)t2) / CLOCKS_PER_SEC),
           (((float)t3) / CLOCKS_PER_SEC));

    free(array);
    return 0;
}
