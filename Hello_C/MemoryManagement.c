#include <string.h>
#include "stdio.h"
#include "stdlib.h"

int main(void) {
    // void 指针
    int i = 10;
    // 整数指针转化为 void 指针
    void* vPoint = &i;
    // void 指针转化为整数指针
    int* iPoint = vPoint;
    printf("iPoint: %d\n", *iPoint);
    // 以下写法错误，因为不知道类型，不可以直接使用
    // printf("iPoint: %d\n", *vPoint);

    // malloc
    int* iMalloc = malloc(sizeof(int));
    *iMalloc = 10;
    // 输出 10
    printf("iMalloc: %d\n", *iMalloc);
    free(iMalloc);
    // 使用 malloc 声明一个字符串数组，5个元素，最大长度为12
    char** strArr = malloc(5 * sizeof(char *));
    if (strArr == NULL) {
        perror("malloc for strArray failed");
        exit(EXIT_FAILURE);
    }
    // 为每一个字符串分配内存
    for (int i = 0; i < 5; ++i) {
        strArr[i] = malloc(12);
        if (strArr[i] == NULL) {
            perror("malloc for strArray[i] failed");
            // 释放之前分配的所有内存
            for (int j = 0; j < i; ++j) {
                free(strArr[j]);
            }
            free(strArr);
            exit(EXIT_FAILURE);
        }
    }
    strcpy(strArr[0], "Hello");
    strcpy(strArr[1], "World");
    strcpy(strArr[2], "This");
    strcpy(strArr[3], "Is");
    strcpy(strArr[4], "C Language");

    // 打印字符串数组
    for (int i = 0; i < 5; ++i) {
        printf("String %d: %s\n", i, strArr[i]);
    }
    // 释放内存
    for (int j = 0; j < 5; ++j) {
        free(strArr[i]);
    }
    free(strArr);

    // calloc
    int* pCalloc = calloc(10, sizeof(int));

    // 等同于
    int* qMalloc = malloc(10 * sizeof(int));
    memset(qMalloc, 0, (sizeof(int)) * 10);

    // realloc
    pCalloc = realloc(pCalloc, sizeof(int) * 1000);
    int* rCalloc = realloc(NULL, sizeof(int) * 2000);
    free(pCalloc);
    free(rCalloc);
    // restrict
    int* restrict pRestrict = malloc(sizeof(int));
    int* q = pRestrict;
    *q = 100;
    printf("pRestrict: %d\n", *pRestrict);
    free(pRestrict);
}