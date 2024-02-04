#include "stdio.h"

int sumArr(int arr[], int len);

int sumArr1(int arr[][4], int len);

int sumArr2(int arr[]);

int sumArr3(int len, int arr[len]);

int main(void) {
    // 声明数组
    int arr[] = {1, 2, 3, 4};
    printf("sizeof(arr) : %lu\n", sizeof(arr));
    printf("sizeof(arr[0]) : %lu\n", sizeof(arr[0]));
    // 调用函数
    printf("调用传入数组名以及长度的函数：%d\n", sumArr(arr, 4));
    printf("调用传入数组名以及长度的函数，字面量：%d\n", sumArr((int[]) {1, 2, 3, 4}, 4));
    printf("调用传入变长数组名以及长度的函数：%d\n", sumArr3(4, arr));
    printf("调用传入数组名，不传入长度的函数：%d\n", sumArr2(arr));
    // 声明二维数组
    int arr1[2][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8}};
    printf("调用传入数组名和传入长度的函数：%d\n", sumArr1(arr1, 2));
}

int sumArr(int arr[], int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }
    return sum;
}

int sumArr1(int arr[][4], int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < sizeof(arr[i]) / sizeof(arr[i][0]); ++j) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int sumArr2(int arr[]) {
    int sum = 0;
    printf("sizeof(arr) : %lu\n", sizeof(arr));
    printf("sizeof(arr[0]) : %lu\n", sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        sum += arr[i];
    }
    return sum;
}

int sumArr3(int len, int arr[len]) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }
    return sum;
}
