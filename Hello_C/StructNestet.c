#include <string.h>
#include <stdlib.h>
#include "stdio.h"

struct name {
    char firstName[50];
    char lastName[50];
};

struct user {
    struct name name;
    short age;
    char sex;
};

struct node {
    int value;
    struct node *next;
};

int main(void) {
    // 嵌套赋值的写法
    // 写法一
    struct user people1 = {{"张", "三"}, 10, 'M'};
    // 写法二
    struct name name1 = {"李", "四"};
    struct user people2 = {name1, 12, 'W'};
    // 写法三
    struct user people3 = {
            .name = {"王", "五"},
            .age = 13,
            .sex = 'M'
    };
    // 写法四
    struct user people4 = {
            .name.firstName = "赵",
            .name.lastName = "六",
            .age = 13,
            .sex = 'M'
    };
    // 写法五
    struct user people5;
    people5.age = 14;
    people5.sex = 'W';
    // 报错
    /*people5.name.firstName = "钱";
    people5.name.lastName = "七";*/
    strcmp(people5.name.firstName, "钱");
    strcmp(people5.name.lastName, "七");

    // node
    struct node *head;
    head = malloc(sizeof(struct node));
    head->value = 1;

    head->next = malloc(sizeof(struct node));
    head->next->value = 2;

    head->next->next = malloc(sizeof(struct node));
    head->next->next->value = 3;
    head->next->next->next = NULL;
    // 遍历链表
    for (struct node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d\n", cur->value);
    }


}