#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct animal1 {
    int age;
    char kind[30];
};

struct animal2 {
    int age;
    char *kind;
};

int main(void) {
    struct animal1 dog1 = {4, "小狗"};
    struct animal1 dog2 = dog1;
    strcpy(dog2.kind, "拉布拉多");
    printf("dog1.kind: %s\n", dog1.kind);
    printf("dog2.kind: %s\n", dog2.kind);

    struct animal2 dog3 = {4, "小狗"};
    struct animal2 dog4 = dog3;
    // 注意的是这里改变了指针指向的内存值
    dog3.kind = "拉布拉多";
    printf("dog3.kind: %s\n", dog3.kind);
    printf("dog4.kind: %s\n", dog4.kind);
}