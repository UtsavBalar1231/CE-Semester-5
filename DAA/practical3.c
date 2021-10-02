#include <stdio.h>
#include <string.h>
#include <time.h>

// Function to print Array
void printarr(const char **array, int size);
// Function to sort Array using insertion sort algorithm
void sort(const char **array, int size);

// Driver function
int main()
{
    clock_t t;
    const char *cards[] = {
        "D",
        "W",
        "A",
        "S",
        "E",
        "U",
        "G"};
    int size = (sizeof(cards) / sizeof(const char *));

    printf("Unsorted Array\t: ");
    printarr(cards, size);

    t = clock();
    sort(cards, size);
    t = clock() - t;

    printf("\nSorted Array\t: ");
    printarr(cards, size);

    printf("\nTime Taken to execute: (%f seconds)\n",
           (((float)t) / CLOCKS_PER_SEC));

    return 0;
}

void sort(const char **array, int size)
{
    int j;
    /** UtsavBalar1231
     * Step1: Loop from the second index to last index,
     * and put each into order,
     * keeping the list from 0 to j in order at all times.
     */
    for (j = 1; j < size; j++)
    {
        /** UtsavBalar1231
         * The position goes from j - 1 to 0
         * to examine what item has a lower value than the key value.
         */
        int i = j - 1;
        /* Select the key that we are going to sort. */
        const char *key = array[j];
        /* Go from j - 1 to 0 until we find value lower than key value. */
        for (; i >= 0; i--)
        {
            if (strcasecmp(array[i], key) < 0)
                break;
            printf("\nCard moved\t: %s\n", key);
            array[i + 1] = array[i];
            printf("Card inserted\t: %s, at position : %d", key, i);
        }
        array[i + 1] = key;
        printf("\nIteration %d\t: ", j);
        printarr(array, size);
    }
}

void printarr(const char **array, int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
        printf("%s ", array[i]);
    printf("]\n");
}