#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int *arr, int len) {
    int temp[len];
    mergeSortRecursive(arr,temp, 0, len - 1);
}

void mergeSortRecursive(int *arr, int temp[], int begin, int end) {
    if (begin >= end) {
        return;
    }

    int mid = (end + begin) / 2;

    int start1 = begin, end1 = mid;
    int start2 = mid + 1, end2 = end;
    mergeSortRecursive(arr, temp, start1, end1);
    mergeSortRecursive(arr, temp, start2, end2);

    int i = begin;
    while (start1 <= end1 && start2 <= end2) {
        temp[i++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    }

    while(start1 <= end1) {
        temp[i++] = arr[start1++];
    }
    while(start2 <= end2) {
        temp[i++] = arr[start2++];
    }

    for(i = begin; i <= end; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int length;
    srand((unsigned)time(NULL));
    length = rand() % 10 + 10;
    printf("length : %d\n", length);

    int *arr = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i++) {
        arr[i] = rand() % 100;
    }

    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);    
    }
    printf("\n");

    mergeSort(arr, length);
    
    for(int i = 0; i < length; i++) {
        printf("%d ", arr[i]);    
    }
    printf("\n");

    /*int * arr = (int*) malloc(sizeof(int) * 2);
    arr[0] = 18;
    arr[1] = 0;

    quickSort(arr, 0, 1);*/

    return 0;
}