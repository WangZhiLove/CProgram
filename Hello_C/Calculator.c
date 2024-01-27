#include <stdio.h>

int main(void) {
    while(1 == 1) {
        int num1;
        int num2;
        char symbol;
        // 输入第一个整数
        first:
        printf("请输入第一个整数：\n");
        int num1Result = scanf("%d", &num1);
        if (num1Result != 1) {
            printf("错误输入，请输入整数\n");
            goto first;
        }

        // 输入运算符
        cal:
        printf("请输入运算符，目前仅支持 +、-、*、/：\n");
        scanf(" %c", &symbol);
        if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') {
            printf("输入错误，当前仅支持+、-、*、/");
            goto cal;
        }

        // 输入第二个整数
        second:
        printf("请输入第二个整数：\n");
        int num2Result = scanf("%d", &num2);
        if (num2Result != 1) {
            printf("错误输入，请输入整数\n");
            goto second;
        }

        switch (symbol) {
            case '+':
                printf("计算结果为 %d + %d = %d\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("计算结果为 %d - %d = %d\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("计算结果为 %d * %d = %d\n", num1, num2, num1 * num2);
                break;
            case '/':
                printf("计算结果为 %d / %d = %d\n", num1, num2, num1 / num2);
                break;
            default:
                printf("未知错误\n");
        }
    }
}