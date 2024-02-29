#include "stdio.h"

struct synth {
    // 每个属性后面的 1 表示占据二进制位
    unsigned int ab:1;
    unsigned int cd:1;
    unsigned int ef:1;
    unsigned int gh:1;
};

int main(void) {
    // 位字段
    struct synth synth;
    synth.ab = 0;
    synth.cd = 1;
}