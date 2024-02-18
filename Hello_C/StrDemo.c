#include <string.h>
#include "stdio.h"

int main(void) {
    char s[14] = "Hello, world!";
    char s2[] = "Hello, world!";
    char* s1 = "Hello, world!";
    printf("%s\n", s);
    printf("%s\n", s1);
    printf("%s\n", s2);
    /*
    s1[0] = 'a';
    printf("%s\n", s1);
    */
    s[0] = 'a';
    printf("%s\n", s);

    char* pointStr = "How are you?";
    pointStr = "Hello, Siri!";
    /*char arrStr[] = "Hello";
    arrStr = "World";*/

    char arrStr[10];
    strcpy(arrStr, "Hello");
    printf("%s\n", arrStr);
    printf("字符串 arrStr 的长度为：%lu\n", strlen(arrStr));
    printf("字符串 arrStr 的字符串长度为：%lu\n", sizeof(arrStr));

    char copyStr[100];
    strcpy(copyStr, arrStr);
    copyStr[0] = 'a';
    printf("%s\n", arrStr);
    printf("%s\n", copyStr);

    char s10[] = "best!";
    char s20[20] = "I'm good!";
    char* ps = strcpy(s20 + 4, s10);
    printf("s10: %s\n", s10);
    printf("s20: %s\n", s20);
    printf("ps: %s\n", ps);

    char s30[30];
    strncpy(s30, s20, 3);
    s30[4] = '\n';
    printf("s30: %s\n", s30);

    strncat(s20, pointStr, sizeof(s20) - strlen(s20) - 1);
    printf("s20: %s\n", s20);

}