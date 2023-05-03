#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum state {
    WHITE, GREY, BLACK
} state;

void BFS(int *graph, int size) {
    printf("Breadth First Search\n");
    state states[size];
    for (int i = 0; i < size; i++) {
        states[i] = WHITE;
    }

    int stack[size];
    int *top = stack - 1;

    for (int i = 0; i < size; i++) {
        if (states[i] == WHITE) {
            *(++top) = i;
            states[i] = GREY;

            while (top != stack - 1)
            {
                int node = *top;
                int flag = 0;

                for (int i = 0; i < size; i++) {
                    if (*(graph + size * node + i) == 1 && states[i] == WHITE) {
                        flag++;
                        *(++top) = i;
                        states[i] = GREY;
                    }
                }

                if (!flag) {
                    states[node] = BLACK;
                    top--;
                }

                for (int i = 0; i < size; i++) {
                    printf("%3d ", states[i]);
                }
                printf("\n");
            }
            
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    int size = rand() % 10 + 5;
    printf("lenth: %d\n", size);

    int *graph = (int *)calloc(size * size, sizeof(int));
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            *(graph + size * i + j) = rand()%2;
            *(graph + size * j + i) = *(graph + size * i + j);
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", *(graph + size * i + j));    
        }
        printf("\n");
    }

    BFS(graph, size);
}