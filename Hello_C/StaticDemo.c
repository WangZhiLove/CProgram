#include "stdio.h"

static void counter() {
    static int count = 1;
    printf("%d\n", count);
    count ++;
}

int main(void) {
    counter();
    counter();
    counter();
    counter();
    counter();
}