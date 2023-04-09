#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int shortestPath(int *graph, int size, int node) {
    int path = 0;                                                       // 记录最短路径
    //int is_no_son = 1;                                                  // 记录是否有父结点
    //int is_no_path = 1;                                                 // 记录父结点是否有路径
    //printf("-----------------node%d: --------------------\n", node);
    for(int i = 0; i < size; i++) {                                     // 遍历节点
        
        if(*(graph + i * size + node) != 0) {                           // 查看是否存在父遍历节点
            //printf("----to node%d: ----\n", i);
            //is_no_son = 0;                                              // 存在则置 0
            int temp = shortestPath(graph, size, i) + *(graph + i * size + node);       // 往上走
            // if(temp != -1) {                                            // 如果该父节点存在路径，则置 0
            //     is_no_path = 0;
            // }
            if(path == 0) {
                path = temp;
            }
            path = path > temp? temp: path;                             // 寻找最短路径

            //printf("node %d to node %d path: %d\n",node, i, temp);
        }
    }

    // if( is_no_son || is_no_path) {
    //     return -1;
    // }

    return path;
}

int main() {
    srand((unsigned)time(NULL));
    int size = rand() % 3 + 5;
    printf("size = %d\n", size);
    int *graph = (int *)calloc(size * size, sizeof(int));
    
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            *(graph + size * i + j) = rand() % 10;
        }
    }

    printf("    ");
    for(int i = 0; i < size; i++) {
        printf("%3d ", i);
    }
    printf("\n");

    for(int i = 0; i < size; i++) {
        printf("%3d ", i);
        for(int j = 0; j < size; j++) {
            printf("%3d ", *(graph + size * i + j));
        }
        printf("\n");
    }
    printf("\n");

    printf("the shortest path: %d\n", shortestPath(graph, size, size - 1));
}