#include "stdio.h"
#include "stdbool.h"
#include "limits.h"

int main(void) {
    // 八进制
    int a = 012;
    printf("八进制 012 输出十进制为:%d\n", a);
    printf("八进制 012 输出八进制为:%o\n", a);
    printf("八进制 012 输出八进制为:%#o\n", a);
    // 16进制
    int b = 0X10;
    printf("十六进制 0X10 输出十进制为:%d\n", b);
    printf("十六进制 0X10 输出十六进制为:%x\n", b);
    printf("十六进制 0X10 输出十六进制为:%#x\n", b);
    // 二进制
    int c = 0b10;
    printf("二进制 0b10 输出十进制为:%d\n", c);

    if (0.1 + 0.2 != 0.3) {
        printf("0.1 + 0.2 != 0.3\n");
    }

    bool flag = true;
    bool flag1 = false;

    unsigned char x = 255;
    x = x + 1;
    printf("%d\n", x); // 0
    unsigned int ui = UINT_MAX; // 4,294,967,295
    ui++;
    printf("ui = %u\n", ui); // 0
    ui--;
    printf("ui = %u\n", ui); // 4,294,967,295


    printf("%zd\n", sizeof(int));
    // 参数为变量
    int i;
    printf("%zd\n", sizeof(i));
    // 参数为数值
    printf("%zd\n", sizeof(3.14));
    return 0;
}