#include <stdio.h>

int main(void) {
    // if - else
    int a = 1, b = 2;
    if (a == b) {
        printf("%s\n", "1 == 2");
    } else {
        printf("%s\n", "1 != 2");
    }
    // for
    for (int i = 0; i < 10; ++i) {
        if (i % 2 == 0) {
            continue;
        }
        printf("%d\n", i);
        if (i == 7) {
            break;
        }
    }
    // while
    while (a != b) {
        printf("%s\n", a + " != " + b);
        a ++;
    }
    // do-while
    do {
        printf("%d, %d\n", a, b);
    } while (a != b);
    int x = a == b ? 521 : 125;
    // 输出 521
    printf("%d\n", x);
    // switch
    switch (a) {
        case 1:
            printf("%d\n", 1);
            break;
        case 2:
            printf("%d\n", 2);
            break;
        default:
            printf("%d\n", 521);
            break;
    }
    // goto, goto 需要标签，比如下面代码
    goto floor;
    // 下面这行代码不会执行
    printf("%s\d", "goto");
    floor:
    printf("%s\d", "floor");

}