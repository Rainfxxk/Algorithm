#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum state {
    WHITE,
    GREY,
    BLACk
} state;

int * topologicalSort(int **graph, int size) {
    state states[size];
    for (int i = 0; i < size; i++) {
        states[i] = WHITE;
    }

    int *topological = (int *) malloc(sizeof(int) * size);
    int order = size;

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
                    if (states[j] == WHITE && graph[node][j] == 1) {
                        flag = 0;
                        stack[++top] = j;
                        states[j] = GREY;
                        break;
                    }
                }

                if (flag) {
                    topological[--order] = node;
                    top--;
                }
            }
        }
    }

    return topological;
}

int ** targin_doubleDFS(int ** graph, int size) {
    int *topo = topologicalSort(graph, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");

    int graph_t[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            graph_t[i][j] = graph[j][i];
        }
    }

    int ** targin = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        targin[i] = (int *) malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            targin[i][j] = -1;
        }
    }
    int m = 0, n = 0;

    state states[size];
    for (int i = 0; i < size; i++) {
        states[i] = WHITE;
    }

    int stack[size];
    int top = -1;
    
    for (int i = size - 1; i >= 0;) {
        stack[++top] = topo[i];
        states[topo[i]] = GREY;
        targin[m][n++] = topo[i];

        while (top != -1) {
            int node = stack[top];
            int flag = 1;

            for (int j = 0; j < size; j++) {
                if (graph[node][j] == 1 && states[j] == WHITE) {
                    stack[++top] = j;
                    states[j] = GREY;
                    targin[m][n++] = j;
                    flag = 0;
                    break;
                }
            }

            if (flag) {
                top--;
                states[node] = BLACk;
            }
        }

        m++;
        i -= n;
        n = 0;
    }

    free(topo);
    return targin;
}

int * targin(int ** graph, int size) {
    state states[size];
    for (int i = 0; i < size; i++) {
        states[i] = WHITE;
    }

    int stack[size];
    int top = -1;

    int targinStack[size];
    int targinTop = -1;
    int dfsn[size];
    int *low = (int *) malloc(sizeof(int) * size);
    int isInStack[size];
    int count = 0;
    for (int i = 0; i < size; i++) {
        dfsn[i] = 0;
        low[i] = 0;
        isInStack[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        if (states[i] == WHITE) {
            stack[++top] = i;
            states[i] = GREY;

            while (top != -1) {
                int node = stack[top];
                int flag = 1;
                if (isInStack[node] == 0) {
                    isInStack[node] = 1;
                    targinStack[++targinTop] = node;
                    low[node] = dfsn[node] = count++;
                }

                for (int j = 0; j < size; j++) {
                    if (graph[node][j] == 1) {
                        if (states[j] == WHITE) {
                            stack[++top] = j;
                            states[j] = GREY;
                            flag = 0;
                            break;
                        }
                        else if (isInStack[j] == 1) {
                            low[node] = low[node] < dfsn[j] ? low[node] : dfsn[j];
                        }
                    }
                }

                if (flag) {
                    if (low[node] == dfsn[node]) {
                        int tempNode;
                        if (targinTop != -1) {
                            do {
                            tempNode = targinStack[targinTop--];
                            isInStack[tempNode] = 0;
                            low[tempNode] = dfsn[node];
                        } while (tempNode != node);
                        }
                    }

                    top--;
                    states[node] = BLACk;

                    if (top != -1) {
                        int tempNode = stack[top];
                        low[tempNode] = low[node] < low[tempNode] ? low[node] : low[tempNode]; 
                    }
                }
            }
        }
    }

    printf("\n");
    return low;
}

int main() {
    srand((unsigned) time(NULL));
    int size = rand() % 10 + 5;
    size = 6;
    printf("size: %d\n", size);

    int ** graph = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        graph[i] = (int *) calloc(size, sizeof(int));
        for (int j = 0; j < size; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = rand() % 2;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%2d ", graph[i][j]);
        }
        printf("\n");
    }

    int ** result = targin_doubleDFS(graph, size);
    printf("\n");
    for (int i = 0; i < size; i++) {
        if (result[i][0] == -1) {
            break;
        }
        for (int j = 0; j < size; j++) {
            if (result[i][j] == -1) {
                break;
            }
            printf("%2d ", result[i][j]);
        }
        printf("\n");
    }

    int * targinResult = targin(graph, size);
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%2d ", targinResult[i]);
    }
    printf("\n");
}