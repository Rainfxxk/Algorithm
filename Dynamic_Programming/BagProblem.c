#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct item {
    int weight;
    int value;
    int num;
} item;

int myBagProblem(int bag, item *items, int num) {
    int value = 0;
    for (int i = 0; i < num; i++) {
        if ((items + i)->weight <= bag) {
            int flag = 0;
            if ((items + i)->num != -1) {
                if ((items + i)->num > 0) {
                    (items + i)->num--;
                    flag = 1;
                }
                else {
                    continue;
                }
            }
            int temp = myBagProblem(bag - (items + i)->weight, items, num) + (items + i)->value;
            value = value > temp? value : temp;
            (items + i)->num += flag;
        }
    }

    return value;
}

int BagProblem(int bag, item *items, int num) {
    int *dp = malloc((bag + 1) * sizeof(int));
    memset(dp, 0, bag + 1);
    int result = 0;

    for(int i = 0; i < num; i ++) {
        for (int j = 0; j <= bag; j++) {
            if(j >= items[i].weight) {
                if (dp[j] < dp[j - items[i].weight] + items[i].value){
                    dp[j] = dp[j - items[i].weight] + items[i].value;
                }
            }
        }
    }

    for (int i = 0; i <= bag; i++) {
        if(dp[i] > result) {
            result = dp[i];
        }
    }
    free(dp);

    return result;
}

int Bag01Problem(int bag, item *items, int num) {
    int *dp = malloc((bag + 1) * sizeof(int));
    memset(dp, 0, bag + 1); 
    int result = 0;

    for(int i = 0; i < num; i++) {
        for(int j = bag; j >= 0; j--) {
            if(j >= (items + i)->weight) {
                if(dp[j] < dp[j - (items + i)->weight] + (items + i)->value) {
                    dp[j] = dp[j - (items + i)->weight] + (items + i)->value;
                }
            }
        }
    }
    
    for (int i = 0; i <= bag; i++) {
        if(dp[i] > result) {
            result = dp[i];
        }
    }
    free(dp);

    return result;
}

int main() {
    srand((unsigned)time(NULL));
    int bag = rand() % 50 +50;
    printf("bag: %d\n", bag);
    int num = rand() % 10 + 5;
    printf("num: %d\n", num);
    item *items = calloc(num, sizeof(item));

    for (int i = 0; i < num; i++) {
        (items + i)->weight = rand() % 50;
        (items + i)->value = rand() % 100;
        (items + i)->num = -1;                        // 用 -1 表示数量无限制
    }

    for (int i = 0; i < num; i++) {
        printf("item%d: weight = %d, value = %d\n", i, (items + i)->weight, (items + i)->value);
    }
    
    int result = Bag01Problem(bag, items, num);
    int result1 = BagProblem(bag, items, num);
    printf("01 Bag problem: %d\nTotally Bag Problem: %d\n", result, result1);

    result = myBagProblem(bag, items, num);
    printf("My Totally Bag Problem: %d\n", result);

    for (int i = 0; i < num; i++) {
        (items + i)->num = rand() % 5 + 1;                        // 用 -1 表示数量无限制
    }

    for (int i = 0; i < num; i++) {
        printf("item%d: weight = %d, value = %d, num = %d\n", i, (items + i)->weight, (items + i)->value, (items + i)->num);
    }
}