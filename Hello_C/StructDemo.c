#include "stdio.h"

struct animal {
    int age;
    char *kind;
};

int main(void) {
    struct animal dog;
    dog.kind = "狗";
    dog.age = 5;
    printf("动物的种类是：%s\n", dog.kind);
    printf("动物的年龄是：%d\n", dog.age);

    struct animal cat = {3, "猫"};
    printf("动物的种类是：%s\n", cat.kind);
    printf("动物的年龄是：%d\n", cat.age);

    struct animal animals[100];

    struct user {
        char *name;
        char *email;
    } user1, user2;
    user1.name = "大王";
    user1.email = "da.wang@qq.com";
    user2.name = "小王";
    user2.email = "xiao.wang@qq.com";
    printf("%s 的邮箱为：%s\n", user1.name, user1.email);
    printf("%s 的邮箱为：%s\n", user2.name, user2.email);

    struct {
        char *name;
        char *email;
    } people1 = {"王炸", "wang.zha@huohua.cn"},
    people2 = {"不玩了", "wanbuqi@qq.com"};
    printf("%s 的邮箱为：%s\n", people1.name, people1.email);
    printf("%s 的邮箱为：%s\n", people2.name, people2.email);

    // 别名
    typedef struct account {
        char *name;
        char *email;
    } people;
    people p1 = {"别名来了", "123@qq.com"};
    printf("别名 %s 的邮箱为：%s\n", p1.name, p1.email);
    // 输出结构的长度
    printf("p1 结构的长度：%lu\n", sizeof(p1));
    printf("dog 结构的长度：%lu\n", sizeof(dog));
}

