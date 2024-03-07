#include <stdio.h>
#include <stdlib.h>

struct elasticArr {
    // 记录 chars 数组的长度
    int len;
    // 弹性数组成员
    char chars[];
};

int main() {
    // 声明数组的长度
    int arrLen = 10;
    struct elasticArr *myArr = malloc(sizeof(struct elasticArr) + arrLen * sizeof(char));
    myArr->len = arrLen;
    // 检查内存是否分配成功
    if (!myArr) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    // 使用弹性数组
    for (int i = 0; i < myArr->len; ++i) {
        myArr->chars[i] = 'a' + i;
    }

    // 打印弹性数组的内容
    for (int i = 0; i < myArr->len; ++i) {
        printf("%c ", myArr->chars[i]);
    }
    printf("\n");

    // 释放内存
    free(myArr);
}