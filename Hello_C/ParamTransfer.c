#include "stdio.h"

int valueTransfer(int a);
void swap(int* x, int* y);

int main(void) {
    int a = 10;
    valueTransfer(a);
    printf("值传递不改变原变量，传递的是变量值的拷贝：%d\n", a);
    a = valueTransfer(a);
    printf("值传递有返回值的变化：%d\n", a);

    int x = 1, y = 2;
    swap(&x, &y);
    printf("交换后 x 的值为 %d, y 的值为 %d \n", x, y);
    return 0;
}


int valueTransfer(int a) {
    a ++;
    return a;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}