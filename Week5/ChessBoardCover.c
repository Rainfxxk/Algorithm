#include <stdio.h>
#include <math.h>

int fill;

void cover(int size, int div_size, int start_x, int start_y, int x, int y, int *board) {
    if(div_size == 2)
    {
        for(int i = start_x; i < start_x + 2; i++) {
            for(int j = start_y; j < start_y + 2; j++) {
                if(i == x && j == y) {
                    continue;
                }
                *(board + i * size + j) = fill;
            }
        }

        fill++;

        return;
    }

    div_size = div_size / 2;
    int x1 = start_x + div_size - 1, y1 = start_y + div_size - 1,
        x2 = start_x + div_size,     y2 = start_y + div_size - 1,
        x3 = start_x + div_size - 1, y3 = start_y + div_size,
        x4 = start_x + div_size,     y4 = start_y + div_size;

    if(x <= start_x + div_size - 1) {
        if(y <= start_y + div_size - 1) {
            x1 = x;
            y1 = y;
            *(board + x2 * size  +y2) = fill;
            *(board + x3 * size +y3) = fill;
            *(board + x4 * size +y4) = fill;
            fill++;
        }
        else {
            x3= x;
            y3 = y;
            *(board + x1 * size +y1) = fill;
            *(board + x2 * size +y2) = fill;
            *(board + x4 * size +y4) = fill;
            fill++;
        }
    }
    else {
        if(y <= start_y + div_size - 1) {
            x2 = x;
            y2 = y;
            *(board + x1 * size +y1) = fill;
            *(board + x3 * size +y3)= fill;
            *(board + x4 * size +y4) = fill;
            fill++;
        }
        else {
            x4= x;
            y4 = y;
            *(board + x1 * size +y1) = fill;
            *(board + x2 * size +y2) = fill;
            *(board + x3 * size +y3) = fill;
            fill++;
        }
    }

    cover(size, div_size, start_x, start_y, x1, y1, board);
    cover(size, div_size, start_x + div_size, start_y, x2, y2, board);
    cover(size, div_size, start_x, start_y + div_size, x3, y3, board);
    cover(size, div_size, start_x + div_size, start_y + div_size, x4, y4, board);
}

int main() {
    int size, x, y;

    scanf("%d", &size);
    printf("%d\n", size);
    double temp = log2(size);
    while (temp > (int) temp) {
        printf("fail\n");
        scanf("%d", &size);
    }
    
    printf("x : ");
    scanf("%d", &x);
    printf("y : ");
    scanf("%d", &y);
    while (x > size || y > size) {
        printf("fail\nx : ");
        scanf("%d", &x);
        printf("y : ");
        scanf("%d", &y);
    }

    int board[size][size];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }
    fill = 1;
    cover(size, size, 0, 0, x - 1, y - 1, board);

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
}