#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int TCP(int *graph, int size) {
    int state_MAX = 1 << size;

    int dp[size][state_MAX];

    for (int i = 0 ; i < size; i++) {
        for (int j = 0; j < state_MAX; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < state_MAX; i++) {
        for (int j = 0; j < size; j++) {
            if (!(i & 1)) {
                continue;
            }

            if ( i & (1 << j)) {
                continue;
            }

            for (int k = 0; k < size; k++) {
                int temp = __INT_MAX__;
                int state = i | 1 << j;
                if (i & 1 << k) {
                    temp = temp > (dp[k][i] + *(graph + k * size + j)) ? dp[k][i] + *(graph + k * size + j) : temp;
                    dp[j][state] = temp;
                }
            }
            
        }
    }

    int result = __INT_MAX__;
    for (int i = 1; i < size; i++) {
        result = result > (dp[i][state_MAX - 1] + *(graph + i * size)) ? (dp[i][state_MAX - 1] + *(graph + i * size)) : result;
    }

    return result;
}

int main() {
    srand((unsigned)time(NULL));
    int size = rand() % 5 + 5;
    size = 4;
    printf("size: %d\n", size);
    int *graph = (int *) calloc(size * size, sizeof(int));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                continue;
            }
            *(graph + i * size + j) = rand() % 10 + 1;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", *(graph + i * size + j));
        }
        printf("\n");
    }

    int circle = TCP(graph, size);
    printf("the shortest circle: %d\n", circle);
}