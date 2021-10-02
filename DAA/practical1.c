// Factorial using recursion and iteration with execution time
#include <stdio.h>
#include <time.h>

unsigned long long int recur(int n);
unsigned long long int iter(int n);

int main() {
    int num, c;
    clock_t t;

    printf("Enter the number: ");
    scanf("%d", &num);

    printf("1 = Recursion | 2 = Iteration ? Enter 1 or 2: \n");
    scanf("%d", &c);

    switch(c)
    {
    case 1:
        printf("\nUsing Recursion: \n");
        t = clock();
        if (num < 0)
            printf("No factorial for negative number\n");
        else
            printf("Factorial of %d is %llu\n", num, recur(num));
        t = clock() - t;
        printf("Time Taken to execute: (%f seconds).\n",
               ((float)t) / CLOCKS_PER_SEC);
        break;
    case 2:
        printf("\nUsing Iterative: \n");
        t = clock();
        if (num < 0)
            printf("No factorial for negative number\n");
        else
            printf("Factorial of %d is %llu\n", num, iter(num));
        t = clock() - t;
        printf("Time Taken to execute: (%f seconds).\n",
               ((float)t) / CLOCKS_PER_SEC);
        break;
    default:
        printf("Invalid Input\n");
        break;
    }
    return 0;
}

unsigned long long int recur(int n) {
    if (n == 0)
        return 1;
    return (n * recur(n - 1));
}

unsigned long long int iter(int n) {
    long fact = 1;
    while (n > 0) {
        fact = fact * n;
        n--;
    }
    return fact;
}
