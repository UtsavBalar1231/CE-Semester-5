// Assembly line scheduling

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Created macro for Random number generation
#define randnum(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

void printActivities(int start[], int finish[], int n)
{
    int i = 0, j;

    printf("\nActivities selected: ");
    printf("%d\t", i);

    for (j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            printf("%d\t", j);
            i = j;
        }
    }
}

// Function to swap two numbers
void swap(int array[], int i, int j)
{
    int temp = 0;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Function to all the elements in an array
void printArr(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int main()
{
    int end = 10, i, temp = 0, r;
    int *start_t, *finish_t;
    int size = end - 1;

    // Dynamic memory allocation for size of activities
    start_t = malloc(sizeof(int) * size);
    if (start_t == NULL)
    {
        printf("malloc of size %d failed!\n", size);
        return -1;
    }
    finish_t = malloc(sizeof(int) * size);
    if (finish_t == NULL)
    {
        printf("malloc of size %d failed!\n", size);
        return -1;
    }

    // To avoid repetition with each run
    srand((unsigned int)time(0));

    // Fill array with numbers in range (start, end)
    for (int temp = 0, i = 1; temp < size; i++, temp++)
        start_t[temp] = i;

    // Store all the random numbers in the array
    for (i = size - 1; i > 0; i--)
    {
        r = randnum(1, size);
        swap(start_t, i, r);
    }

    // Store all the random numbers in the array
    for (i = size - 1; i > 0; i--)
    {
        r = randnum(1, size);
        finish_t[i] = r;
    }

    printf("\nActivities: \t");
    for (int j = 1; j < size + 1; j++)
        printf("%d\t", j);

    printf("\n\nStart times: \t");
    printArr(start_t, size);
    printf("Finish times: \t");
    printArr(finish_t, size);

    printActivities(start_t, finish_t, size);

    free(start_t);
    free(finish_t);
    return 0;
}
