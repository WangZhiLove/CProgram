#include "stdio.h"
#include "stdlib.h"

void swap(int* x, int* y);

void print() {
    exit(EXIT_FAILURE);
    printf("Hello World!\n");
}

void hello() {
    printf("Hello!\n");
}

int main(void) {
    atexit(hello);
    print();
//    exit(EXIT_SUCCESS);
    printf("Hello My World!\n");
    return 0;
}