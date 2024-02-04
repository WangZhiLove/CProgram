#include "stdio.h"

int sum(int arr[], int len);
int sum1(int* start, int* end);
int main(void) {
    // 索引初始化
    int arr1[10];
    arr1[0] = 1;
    arr1[9] = 10;
    // int 中没有被初始化的
    printf("%d\n", arr1[5]);
    for (int i = 0; i < (sizeof(arr1) / sizeof(arr1[0])); ++i) {
        printf("%d\n", arr1[i]);
    }
    printf("=================================\n");
    // 大括号初始化
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // 输出 8
    printf("%d\n", arr2[7]);
    for (int i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); ++i) {
        printf("%d\n", arr2[i]);
    }
    int arr3[] = {[2] = 10, [20] = 30};
    // 输出 30
    printf("%d\n", arr3[20]);
    printf("================================\n");
    // 使用首元素的地址推其它成员的地址
    int *p = &arr2[0];
    printf("%d\n", *p);
    printf("%d\n", *(p + 4));
    printf("arr2 sum : %d\n", sum(p, sizeof(arr2) / sizeof(arr2[0])));
    printf("arr2 sum : %d\n", sum1(p, p + 8));
}

int sum(int arr[], int len) {
    int total = 0;
    for (int i = 0; i < len; ++i) {
        total += arr[i];
    }
    return total;
}

int sum1(int* start, int* end) {
    int total = 0;
    while (start < end) {
        total += *start;
        start ++;
    }
    return total;
}
