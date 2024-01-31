#include "stdio.h"

// 放在类型之前，允许修改指向的地址，但是不允许修改值
void print(const int *p) {
    // 下面行报错，编译不通过
    // *p = 521;

    // 下面行允许操作
    int x = 521;
    p = &x;
    printf("print: %d\n", *p);
}

// 放在变量之前，允许允许修改值，但是不修改指向的地址
void print1(int *const p) {
    // 下面行允许操作
    *p = 529;

    // 下面行报错，编译不通过
//    int x = 521;
//    p = &x;
    printf("print1: %d\n", *p);
}

void print2(const int *const p) {
    // 下面行报错，编译不通过
    // *p = 521;

    // 下面行报错，编译不通过
//    int x = 521;
//    p = &x;
    printf("print2: %d\n", *p);
}

int main(void) {
    int p = 123;
    printf("main: %d\n", p);
    print(&p);
    print1(&p);
    print2(&p);
}