#include "stdio.h"

struct user {
    char *name;
    char *phone;
    int age;
};

void ageIncr(struct user me) {
    me.age += 1;
}

void ageIncr1(struct user *me) {
    // (*me).age += 1;
    // 使用 -> 优化上面复杂的写法
    me->age += 1;
}

int main(void) {
    struct user me = {"王智", "test123456", 29};
    // 输出增加之前的age
    printf("before age : %d\n", me.age);
    ageIncr(me);
    // 发现并没有变化，这个的原因是因为函数内部得到的是副本的变量
    printf("after age : %d\n", me.age);
    // 调用指针写法的函数
    printf("before age : %d\n", me.age);
    ageIncr1(&me);
    // 改变
    printf("after age : %d\n", me.age);
}