// Activity Selection Problem

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Created macro for Random number generation
#define randnum(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))

// Function to all the elements in an array
void pr_arr(int array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d\t", array[i]);
    printf("\n");
}

/**
 * @select_activities: Function to select activities using greedy approach
 * 
 * @param start: Array of start times of activities
 * @param finish: Array of finish times of activities
 * @param n: Total number of activities
 */
void select_activities(int start[], int finish[], int n)
{
    int i = 0, j;
    int *selected;
    selected = (int *)malloc(sizeof(int) * n);
    if (selected == NULL)
    {
        printf("Malloc of size: %d failed\n", n);
        return;
    }

    // Always select the first activity as per the algorithm
    selected[0] = i;

    for (j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            selected[j] = j;
            i = j;
        }
    }

    printf("\nActivities selected:\t");
    printf("%d\t", selected[0]);
    for (int i = 1; i < n; i++)
        if (selected[i] != 0) // avoid printing no tselected activities
            printf("%d\t", selected[i]);
    printf("\n");

    free(selected);
}

// Function to swap two numbers
void swap(int array[], int i, int j)
{
    int temp = 0;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
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
    for (i = size; i >= 0; i--)
    {
        r = randnum(0, size);
        swap(start_t, i, r);
    }

    // Store all the random numbers in the array
    for (i = size; i >= 0; i--)
    {
        r = randnum(0, size);
        finish_t[i] = r;
    }

    printf("\nActivities are\t:\t");
    for (int j = 1; j < size + 1; j++)
        printf("%d\t", j);

    printf("\nStart times are\t:\t");
    pr_arr(start_t, size);
    printf("Finishtimes are\t:\t");
    pr_arr(finish_t, size);

    select_activities(start_t, finish_t, size);

    free(start_t);
    free(finish_t);
    return 0;
}
