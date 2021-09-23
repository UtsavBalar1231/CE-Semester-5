// Knapsack problem algorithm
#include <stdio.h>
#include <time.h>

/**
 * swap - Swapping algorithm
 * @x:      Number 1
 * @y:      Number 2
 */
void swap(float *x, float *y) {
    float temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * fractional_knapsack - Fractional knapsack algorithm using Greedy approach
 * @w:      List of all the objects weight
 * @V:      List of all the objects value
 * @W:      Capacity of the knapsack
 * @n:      Total numbers of objects
 */
void fractional_knapsack(float w[], float V[], float W, int n) {
    float x[3], weight = 0.0, profit = 0.0;

    // Initialization
    for (int i = 0; i < n; i++)
        x[i] = 0.0;

    for (int i = 0; weight < W; i++) {
        if (weight + w[i] < W) {
            x[i] = 1.0;
            weight = weight + w[i];
            profit = profit + V[i];
            // printf("Object: %d: \tx[%d] = %0.1f\tweight = %0.1f\tw[%d] = %0.1f\tV[%d] = %0.1f\tW = %0.1f\n",
            //        i + 1, i + 1, x[i], weight, i + 1, w[i], i + 1, V[i], W);
        } else {
            x[i] = (W - weight) / w[i];
            weight = W;
            profit = profit + (x[i] * V[i]);
            // printf("Object: %d: \tx[%d] = %0.1f\tweight = %0.1f\tw[%d] = %0.1f\tV[%d] = %0.1f\tW = %0.1f\n",
            //        i + 1, i + 1, x[i], weight, i + 1, w[i], i + 1, V[i], W);
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     if (x[i] == 1.0)
    //         printf("\nObject added = %d\t\tProfit = $%0.1f\tWeight = %0.1f",
    //                i + 1, V[i], w[i]);
    //     else if (x[i] > 0.0)
    //         printf("\nAdded %0.1f part of Object %d\tProfit = $%0.1f\tWeight %0.1f",
    //                x[i], i + 1, (x[i] * V[i]), w[i]);
    // }

    printf("\nThe Maximum Value for %d objects with load %0.1f = $%0.1f\n\n",
        n, W, profit);
}

int main(void) {
    // Start: provided from the question
    int object[3] = {
        1,
        2,
        3
    };
    float weight[3] = {
        10,
        20,
        30
    };
    float value[3] = {
        60,
        100,
        150
    };
    float capacity = 50;
    int n = 3;
    // End:

    clock_t t;

    /* NOTE: Create an array for storing value/weight
     * for all the objects
     */
    float ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = value[i] / weight[i];
        // printf("Object: %d\t ratio=%0.1f\n", i, ratio[i]);
    }

    /* NOTE: Re-Arrange the array in such a way
     * that value/weight is in descending order
     */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ratio[i] > ratio[j]) {
                swap( &ratio[i], &ratio[j]);
                swap( &weight[i], &weight[j]);
                swap( &value[i], &value[j]);
            }
        }
    }

    printf("Using Fractional values\n");
    t = clock();
    fractional_knapsack(weight, value, capacity, n);
    t = clock() - t;

    printf("\nTime Taken to execute: (%f seconds)\n",
           (((float)t) / CLOCKS_PER_SEC));

    return 0;
}
