#include "stdio.h"

int main() {
    // 为 unsigned char 起别名 BYTE
    typedef unsigned char BYTE;
    // 使用 BYTE 声明变量
    BYTE c = 'z';
    printf("别名 BYTE 的属性 c 的值为：%c\n", c);

    // 为指针起别名
    typedef int* intptr;
    int a = 10;
    // 注意 x 是一个指针
    intptr x = &a;
    printf("指针别名 intptr 变量 x 的值为：%d\n", *x);

    // 为数组起别名
    typedef int five_ints[5];
    five_ints  arr = {1,2,3,4,5};
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); ++i) {
        printf("输出数组第 %d 个元素值为：%d\n", i, arr[i]);
    }
}