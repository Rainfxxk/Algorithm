#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matrixConcatenate(int *matrix, int n) {
    int *concatenate = calloc(n * n, sizeof(int));

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            *(concatenate + j*n + j + i) = __INT_MAX__;
            for(int k = j; k < j + i; k++) {
                int a = *(concatenate + j * n + k);
                int b = *(concatenate + (k + 1) * n + j + i);
                int temp = *(concatenate + j * n + k) + *(concatenate + (k + 1) * n + j + i) + matrix[j] * matrix[k + 1] * matrix[j + i + 1];
                if (*(concatenate + j * n + j + i) > temp) {
                    *(concatenate + j * n + j + i) = temp;
                }
            }
        }

        // 用于打印每次计算的结果矩阵
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%3d ", *(concatenate + i * n + j));
            }
            printf("\n");
        }
    }

    int result = *(concatenate + n - 1);
    return result;
}

int main() {
    srand((unsigned)time(NULL));
    int n = rand() % 10 + 10;
    int *matrix = calloc(n + 1, sizeof(int));

    for (int i = 0; i <= n; i++) {
        matrix[i] = rand() % 10 +1;
    }

    for (int i = 0; i <= n; i++) {
        printf("%d ", matrix[i]);
    }
    printf("\n");

    int result = matrixConcatenate(matrix, n);
    printf("result: %d\n", result);
}