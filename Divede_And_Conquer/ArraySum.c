#include <stdio.h>

int sumOfArray(int *arr, int start, int end) {
    if(start == end){
        return arr[start];
    }

    int mid = (start + end) / 2;
    return sumOfArray(arr, start, mid) + sumOfArray(arr, mid + 1, end);
}

int main() {
    int length, sum;
    srand((unsigned)time(NULL));
    length = rand() % 10 + 10;
    printf("length : %d\n", length);

    int *arr = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i++) {
        arr[i] = rand() % 100;
        sum += arr[i];
    }

    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);    
    }
    printf("\n");

    if(sum == sumOfArray(arr, 0, length - 1)) {
        printf("Success!\n%d\n", sum);
    }
    else {
        printf("Fail!");
    }

    return 0;
}