#include <string.h>
#include "stdio.h"

int main(void) {
    // 初始化
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
    // 复制
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

    // 比较
    char cmpS1[] = "Hello World!";
    char cmpS2[] = "Hello World!";
    char cmpS3[] = "Hello Z";

    printf("s1 cmp s2: %d\n", strcmp(cmpS1, cmpS2));
    printf("s2 cmp s3: %d\n", strcmp(cmpS2, cmpS3));
    printf("s3 cmp s2: %d\n", strcmp(cmpS3, cmpS2));
    printf("s3 ncmp s2: %d\n", strncmp(cmpS3, cmpS2, 5));

    // 写入
    char printS1[] = "Hello";
    char printS2[] = "World";
    char printS3[12];
    sprintf(printS3, "%s %s", printS1, printS2);
    printf("printS3: %s\n", printS3);

    // 字符串数组
    char colors1[4][6] = {"red", "green", "blue", "pink"};
    char colors2[][6] = {"red", "green", "blue", "pink"};
    char* colors3[] = {"red", "green", "blue", "pink"};
    for (int i = 0; i < sizeof(colors3) / sizeof(colors3[0]); ++i) {
        printf("colors %d : %s\n", i, colors3[i]);
    }
}