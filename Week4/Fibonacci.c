#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fibonacciRecurrence(long *arr, int n) {
    if(n == 1) {
        arr[0] = 1;
        return;
    } else if (n == 2) {
        arr[0] = 1;
        arr[1] = 1;
        return;
    }

    fibonacciRecurrence(arr, n - 1);
    arr[n - 1] = arr[n - 2] + arr[n - 3];
    printf("%ld : %ld\n", n, arr[n - 1]);
}

long fibonacci(int n){
    long arr[n];
    fibonacciRecurrence(arr, n);
    return arr[n - 1];
}

int main() {
    srand((unsigned)time(NULL));
    int n = rand() % 20 + 40;
    printf("%ld : %ld\n", n, fibonacci(n));
}