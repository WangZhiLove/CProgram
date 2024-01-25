#include <stdio.h>

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
    return 0;
}
