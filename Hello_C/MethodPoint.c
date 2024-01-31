#include "stdio.h"
#include "stdbool.h"

void print(int a);

int main(void) {
    // 获取函数的地址作为变量，printNum 是一个函数指针
    void (*printNum)(int) = &print;
    // 使用函数指针调用函数
    printNum(10);

    // 函数名本身指向函数代码的指针
    if (&print == print) {
        printf("函数名本身指向函数代码的指针\n");
    }
    void (*printNum1)(int) = print;
    printNum1(11);
    printf("printNum1 == printNum %d\n", printNum1 == printNum);
    return 0;
}

void print(int a) {
    printf("%d\n", a);
}