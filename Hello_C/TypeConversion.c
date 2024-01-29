#include "stdio.h"

void increment(int *pInt);

int main(void) {
    int x = 12.99;
    printf("%d\n", x);
    float y = 12 * 2;
    printf("%f\n", y);
    char z = 10;
    int i = z + y;
    printf("%d\n", i);
    int a = 321;
    // 二进制截值
    char ch = a;
    printf("%d\n", ch);
    int q = 1;
    increment(&q);
    printf("%d\n", q);
    return 0;
}

void increment(int* pInt) {
    *pInt = *pInt + 1;
}


