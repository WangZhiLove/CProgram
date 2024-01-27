#include <stdio.h>

int x = 123;

int main(void) {
    printf("Hello World\n");
    printf("%5df\n", 123);
    printf("%-5d\n", 123);
    printf("%12f\n", 123.45);
    printf("%+d\n", 12);
    printf("%+d\n", -12);
    printf("Number is %.2f\n", 0.5);
    printf("%6.2f\n", 0.5);
    printf("%*.*f\n", 6, 2, 0.5);
    printf("%.5s\n", "hello world");
    // 只声明不初始化
    int lower, upper, step;
    // 声明 + 初始化
    int num = 52;
    // 可以使用 const 限定符限定，表示不可更改，相当于 Java 的 final
    const int myConst = 521;
    {
        int s = 1;
        {
            int a = 2;
            int s = 3;
            // 输出 2
            printf("%d\n", a);
            // 输出 3
            printf("%d\n", s);
        }
        // 输出 1
        printf("%d\n", s);
        // 无法编译，报错
        // printf("%d\n", a);
    }
    // 3 的 二进制是 11，输出 -4，计算过程如下
    // 3 的二进制表示法为 00000000 00000000 00000000 00000011
    //   取反得到        11111111 11111111 11111111 11111100
    // 在大多数C语言实现中，整数使用二进制补码形式表示，最高位为符号位，1表示负数，在补码表示法中，负数的值是取所有位的反（除符号位外），然后加1。
    // 所以结果是 00000000 00000000 00000000 00000100，表示 4， 因为最高位是 1，所以是 -4
    printf("%d\n", ~ 3);
    // 2 的 二进制是 10，3 的二进制是 11，输出 2
    printf("%d\n", 2 & 3);
    // 2 的 二进制是 10，3 的二进制是 11，输出 3
    printf("%d\n", 2 | 3);
    // 2 的 二进制是 10，3 的二进制是 11，输出 1
    printf("%d\n", 2 ^ 3);
    // 2 的 二进制是 10，3 的二进制是 11，输出 0
    printf("%d\n", 2 >> 3);
    // 2 的 二进制是 10，3 的二进制是 11，输出 16
    printf("%d\n", 2 << 3);
    int y;
    y = 1, 2, 3;
    // 输出 1
    printf("%d\n", y);
    return x;
}
