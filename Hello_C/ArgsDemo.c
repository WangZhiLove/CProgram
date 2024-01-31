#include "stdio.h"
#include "stdarg.h"

// 这里的 i 表示可变参数的个数
double average(int i, ...) {
    double total = 0;
    // 可变参数对象
    va_list ap;
    // 将 i 后面的参数统一放到 ap 中
    va_start(ap, i);
    // 遍历累加
    for (int j = 1; j <= i; ++j) {
        total += va_arg(ap, double);
    }
    // 清理可变参数对象
    va_end(ap);
    return total / i;
}

int main(void) {
    // 注意的是传递的参数要和期望的参数类型相同
    double avg = average(5, 2.0, 4.0, 6.0, 8.0, 10.0);
    printf("%f\n", avg);
}