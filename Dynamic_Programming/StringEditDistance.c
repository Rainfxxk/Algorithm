#include <stdio.h>

// 取字符串长度
int getLength(char *str) {
    char *temp = str;
    int length = 0;
    while( *temp != '\0') {
        length++;
        temp++;
    }
    return length;
}

// 比较两字符是否想等
int diff(char *c1, char *c2) {
    if (*c1 == *c2) {
        return 1;
    }
    else {
        return 0;
    }
}

// 字符串编辑距离
int editDistance(char *str1, char *str2) {
    char *t_str1 = str1;
    char *t_str2 = str2;

    //如果有一个字符串到了结尾，则直接返回另一字符串的剩余长度
    if (*t_str1 == '\0') {
        return getLength(t_str2);
    }
    else if (*t_str2 == '\0') {
        return getLength(t_str1);
    }

    // 一共有三种情况
    // 1. 在当前 str2 前加空格，则由于而之不匹配，所以需要加 1
    // 2. 在当前 str1 前加空格，则由于而之不匹配，所以需要加 1
    // 1. 二者均不加空格，则需要判断当前字符是否相同，是则加 0，反之加 1
    int temp1 = editDistance(t_str1 + 1, t_str2) + 1;
    int temp2 = editDistance(t_str1, t_str2 + 1) + 1;
    int temp3 = editDistance(t_str1 + 1, t_str2 + 1) + (diff(t_str1, t_str2)? 0 : 1);

    // 返回最小值
    int temp = temp1 < temp2? temp1 : temp2;
    temp = temp < temp3? temp : temp3;
    return temp;
}

int main() {
    char str1[1000];
    char str2[1000];

    scanf("%s", &str1);
    scanf("%s", &str2);

    printf("str1: %d, %s\nstr2: %s\n", getLength(str1), str1, str2);
    editDistance(str1, str2);
    printf("the distance is: %d\n", editDistance(str1, str2));
}