// Assembly line scheduling

#include <stdio.h>

// Prints a maximum set of activities that can be done by a single
// person, one at a time.
//  n   -->  Total number of activities
//  s[] -->  An array that contains start time of all activities
//  f[] -->  An array that contains finish time of all activities
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;

    printf("Following activities are selected n");

    // The first activity always gets selected
    i = 0;
    printf("%d ", i);

    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (s[j] >= f[i])
        {
            printf("%d ", j);
            i = j;
        }
    }
}
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
    int size = 50, i, temp = 0, r;
    int *array;
    array = (int *)calloc(sizeof(int) * size);
    if (array == NULL)
    {
        printf("malloc of size %d failed!\n", size);
        return 0;
        exit(1);
    }

    // To avoid repetition with each run
    srand((unsigned int)time(NULL));

    // Store all the random numbers in the array
    for (i = size - 1; i > 0; i--)
    {
        r = randnum(1, size);
    }

    printf("\nUnosrted Start times: \t");
    printf("\nUnsorted Finish times: \t");
    printArr(array, size);

    quicksort(array, 0, size - 1);

    return 0;
}
