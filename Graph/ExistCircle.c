#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum state {
    WHITE,
    GREY,
    BLACk
} state;

int existCircle(int **graph, int size) {
    state states[size];
    for (int i = 0; i < size; i++) {
        states[i] = WHITE;
    }

    int stack[size];
    int top = -1;
    for (int i = 0; i < size; i++) {
        if (states[i] == WHITE) {
            stack[++top] = i;
            states[i] = GREY;

            while (top != -1) {
                int node = stack[top];
                int flag = 1;
                for (int j = 0; j < size; j++) {
                    if (graph[node][j] == 1) {
                        if (states[j] == GREY) {
                            return 1;
                        }
                        else {
                            if (states[j] == WHITE){
                                stack[++top] = j;
                                flag = 0;
                                break;
                            }
                        }
                    }
                }

                if (flag) {
                    states[node] = BLACk;
                    top--;
                }
            }
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    int size = rand() % 10 + 5;
    printf("size: %d\n", size);

    int **graph = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        graph[i] = (int *) malloc(size * sizeof(int));
    }

    for( int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = rand() % 2;
            }
        }
    }

    for( int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    if (existCircle(graph, size)) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}