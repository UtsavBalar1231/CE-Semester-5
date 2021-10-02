#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Created macro for Random number generation
#define randnum(min, max) \
    ((rand() % (int)(((max) + 1) - (min))) + (min))

// Function to print Array
void printarr(int array[], int size);
// Function to sort Array using insertion sort algorithm
void sort(int array[], int size);
// Function to swap numbers in array
void swap(int array[], int i, int j);

// Driver function
int main()
{
    clock_t t1, t2, t3;
    int start = 1, end, i, temp = 0, r;
    int *array;

    // Loop until user enters a valid size
    while (end <= 0) {
        printf("\nPlease enter the size of random array: ");
        scanf("%d", & end);

        if (end <= 0)
            printf("Please enter a number above 0.");
    }

    int size = end - start + 1;
    // Set the size as your input size
    array = malloc(sizeof(int) * size);
    if (array == NULL) {
        printf("malloc of size %d failed!\n", size);
        return -1;
    }

    // Fill array with numbers in range (start, end)
    for (temp = 0, i = start; temp < size; i++, temp++)
        array[temp] = i;

    // To avoid repetition with each run
    srand((unsigned int)time(NULL));

    // Store all the random numbers in Array arr[]
    for (i = size - 1; i > 0; i--)
    {
        r = randnum(start, end);
        swap(array, i, r);
    }

    printf("Unsorted Array\t: ");
    printarr(array, size);

    t1 = clock();
    sort(array, size);
    t1 = clock() - t1;
    printf("\nSorted Array: (Average Case): \n");
    printarr(array, size);

    t2 = clock();
    sort(array, size);
    t2 = clock() - t2;
    printf("\nSorted Array: (Best Case): \n");
    printarr(array, size);

    // Reverse the numbers in Array arr[]
    int x = 0, y = size - 1; // End value of array
    while (x < y)
    {
        swap(array, x, y);
        x++;
        y--;
    }

    printf("\nUnsorted Array: (Worst Case): \n");
    printarr(array, size);

    t3 = clock();
    sort(array, size);
    t3 = clock() - t2;
    printf("\nSorted Array: (Worst Case): \n");
    printarr(array, size);

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

void sort(int array[], int size)
{
    for (int j = 1; j < size; j++)
    {
        int key = array[j];
        int i = j - 1;
        for (; i >= 0; i--)
        {
            if (array[i] < key)
                break;
            array[i + 1] = array[i];
        }
        array[i + 1] = key;
    }
}

void printarr(int array[], int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("]\n");
}

void swap(int array[], int i, int j)
{
    int temp = 0;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
