#include "stdio.h"
#include "stddef.h"
#include "stdbool.h"

int main(void) {
    int* i;
    i = (int*)0xD;
    i = i + 1;
    // 输出 0x11
    printf("%p\n", i);
    short* j;
    j = (short*)0xD;
    j = j + 1;
    // 输入 0xF
    printf("%p\n", j);

    int* i1;
    int* i2;
    i1 = (int*) 0x1234;
    i2 = (int*) 0x1230;
    // 输出 1
    printf("%ld\n", i1 - i2);
    // 输出 -1
    printf("%ld\n", i2 - i1);

    short* j1;
    short* j2;
    j1 = (short*) 0x1234;
    j2 = (short*) 0x1230;
    // 输出 2
    printf("%ld\n", j1 - j2);
    // 输出 -2
    printf("%ld\n", j2 - j1);

    int* j3;
    j3 = (int*)0x1234;
    // 输出 0
    printf("%d\n", i1 > j3);
    // 输出 0
    printf("%d\n", i1 < j3);
    // 输出 1
    printf("%d\n", i1 == j3);
    return 1;
}