# CProgram

C 语言我之前没有接触过,最近 打算重新梳理下自己学过的东西,因为感觉自己的基础不好,高不成低不就的,于是就决定重新学一遍编程,了解了下耗子叔和二哥推荐的学习路线,其中都有说到应该学习 C 语言,首先 C 是最接近硬件的语言 ，并且几乎现在所有的操作系统内核中都是 C 语言进行编写的，学习 C 语言对于了解操作系统有帮助，其次呢？后续的 C++，Java 都是在 C 语言的基础上进行蓬勃发展的，都是为了解决 C 语言的缺陷和局限性，所以了解 C 也相当于了解了 C++ 和 Java 的一些背景，很有帮助。

# C 语言的特点

C 语言有如下特点，特点就是我们为什么要去学习的理由。

1. C 语言属于低级语言

   如何理解这里的低级呢？这个是相对于 Java 这种高级语言而说的，越低级的语言越接近硬件，也就是可以直接和内存、操作系统、硬件进行交互，所以如果有极高性能要求的程序，可以使用 C 语言来编写

2. C 语言的移植性比较好

   C 语言最开始的目的就是要将 Unix 系统移植到其它系统的架构，意思就是说呢 C 程序可以很简单的移植到各种硬件架构和操作系统中，移植性好也决定了 C 语言是嵌入式开发的首选编程语言

3. C 语言本身比较简单

   C 语言语法比较简单，没有高级操作，比如说没有类，不提供高级的数据结构，所有的复杂数据结构都要自己构造

4. C 语言比较灵活

   这里的灵活说的是限制少，C 语言的哲学是"信任程序员，不要妨碍他们做事"。也就是程序员在使用 C 语言的时候要自己管理内存，我是 Java 出身，所以容易和 Java 产生对比，如果学会了 C 语言，会不会对 Java 中的内存管理会有一个新的感觉呢。

综上呢，都是 C 语言的优点，当然也提到了缺点，比如说内存管理需要程序员自己来做等等，接下来一步一步走进 C 语言的世界吧。

## C 语言的编译

C 语言是一门编译型语言(这里让我想到了 Java，那 Java 是什么呢？我记得是半编译半解释的，JIT 就是编译执行)，既然是编译，那就涉及到编译器，阶段也就会分为编译时和运行时，这里我直接偷懒，使用了 CLion，也就看不到编译的过程了，无论学习什么语言，第一个当然是熟悉的 Hello World 了，使用这个来初窥一下 C 语言。

这里我还是直接使用 CLion，使用命令行来编译，首先在程序中写出如下代码:

````c
#include <stdio.h>

int main(void) {
    printf("Hello World");
    return 0;
}
````

然后再编译器中打开命令行，执行编译命令

`gcc HelloWorld.c `

执行完成之后会多出一个a.out(*assembler output 的缩写*)，好了，开始执行，执行命令如下

`./a.out`

输出了结果`Hello World%` ，为啥多出来了个 % 号呢？查了下，原来是因为没有输出换行，导致终端在程序输出结束后立即显示了命令提示符，所以再上面的程序中加个换行符，也就是改成这样:`printf("Hello World\n");` 

我看着 a.out 就有点奇怪，那我能自己指定名字吗？当然可以，使用指令 `gcc -o`就可以，例如

`gcc -o HelloWorld HelloWorld.c`

生成的文件就是 HelloWorld，没有后面的 .out，这个也是可以直接执行的。这里先不研究语法，后面再研究这里的 include 是什么意思，main 是什么意思，不过参考 Java 应该可以想到，include 相当于 import，main 就相当于 Java 中的 main，作为程序的入口。

## C 语言的基本语法

C 语言的基本语法主要包括了语句、表达式、语句块、逻辑跳转、注释、头文件、标准库等等。一个一个来！

### 语句

语句就是要知道 C 语言的行结束符号，C 语言的行结束符号是 `;`，也就是说如果写了一行代码，但是没有加英文分号，则程序会报错，如果使用的是高级编辑器，会直接有红色波浪线。

### 表达式

表达式是一个计算式，也就是用来获取值的，C 语言的各种计算，都是使用表达式来完成的。比如说 `int i = 1 + 2;`

### 语句块

就是一个大括号，大括号中的内容就是语句块，比如说 if - else 语句

### 注释

C 语言的注释有以下几种情况：

`/* 注释 */`这种注释支持换行，也就是可以一行写 `/*`，然后换行写注释，最后加上 `*/`

`// 注释`

### printf()

`printf()` 的作用是将参数输出到屏幕，f 代表 format，`printf()`不会自动换行，如果需要换行，则要加上 \n。

### 占位符

这个占位符说起来是我不熟悉的，之前学习 Java 的时候就看到有些代码中有 `%s`等等，根本不知道啥意思，原来是从 C 语言这块继承过去的呀。

下面是常用的占位符：

````
%a ：浮点数。
%A ：浮点数。
%c ：字符。
%d ：⼗进制整数。
%e ：使⽤科学计数法的浮点数，指数部分的e 为⼩写。
%E ：使⽤科学计数法的浮点数，指数部分的E 为⼤写。
%i ：整数，基本等同于%d 。
%f ：⼩数（包含float 类型和double 类型）。
%g ：6个有效数字的浮点数。整数部分⼀旦超过6位，就会⾃动转为科学计数法，指数部分的e 为⼩
写。
%G ：等同于%g ，唯⼀的区别是指数部分的E 为⼤写。
%hd ：⼗进制 short int 类型。
%ho ：⼋进制 short int 类型。
%hx ：⼗六进制 short int 类型。
%hu ：unsigned short int 类型。
%ld ：⼗进制 long int 类型。
%lo ：⼋进制 long int 类型。
%lx ：⼗六进制 long int 类型。
%lu ：unsigned long int 类型。
%lld ：⼗进制 long long int 类型。
%llo ：⼋进制 long long int 类型。
%llx ：⼗六进制 long long int 类型。
%llu ：unsigned long long int 类型。
%Le ：科学计数法表示的 long double 类型浮点数。
%Lf ：long double 类型浮点数。
%n ：已输出的字符串数量。该占位符本身不输出，只将值存储在指定变量之中。
%o ：⼋进制整数。
printf("%s says it is %i o'clock\n", "Ben", 21);
%p ：指针。
%s ：字符串。
%u ：⽆符号整数（unsigned int）。
%x ：⼗六进制整数。
%zd ： size_t 类型。
%% ：输出⼀个百分号。
````

先记住常用的，比如说 `%s`、`%i`、%f、`%a` 等等。

### 输出格式

#### 限制宽度

输出格式常常与前面的占位符一起使用，表示占位符的宽度，例如下面

```c
printf("%5df\n", 123); // 表示最小宽度为 5，所以会在 123 前面加两个空格
printf("%-5d\n", 123); // 输出为 "123 "，在末尾添加两个空格
printf("%12f\n", 123.45); // 输出 " 123.450000"，因为⼩数的默认显示精度是⼩数点后6位
```

#### 总是显示正负号

````c
printf("%+d\n", 12); // 输出 +12
printf("%+d\n", -12); // 输出 -12
````

#### 限定小数位数

小数点后保留几位，可以如下写：

````c
printf("Number is %.2f\n", 0.5); // 输出Number is 0.50
printf("%6.2f\n", 0.5); // 输出为 " 0.50"
printf("%*.*f\n", 6, 2, 0.5); // %*.*f 的两个星号通过printf() 的两个参数6 和2 传⼊
````

#### 输出部分字符串

⽤`%.[m]s`指定输出的⻓度，其中[m]代表⼀个数字，表示所要输出的⻓度。

````c
printf("%.5s\n", "hello world"); // 输出 hello
````

#### 标准库和头文件

我们一直在使用的 printf 是输出方法，那这个方法在哪呢？我又没有写呀，这个就是 C 语言已经提供的功能，像这种类似的只需要调用就可以，这些自带的功能，统称为"标准库"，不同的功能定义在不同的文件里面，头文件的后缀一般是 .h，要使用功能，必须先加载，如何加载呢？就是使用 #include，如下

`#include <stdio.h>`

### 变量

变量的解释很有意思，变量就是一块内存区域的名字，通过变量名，可以引用到这块内存区域的值，而因为内存区域的值经常会发生变化，所以就是变量，不会变的就是常量。

#### 变量名

先说名字吧，在编程语言中，变量的名字非常有讲究，C 语言中，变量名的规范如下：

- 只能有小写字母、大写字母、数字和下划线组成
- 变量名不能以数字开头
- 变量名的长度不能超过 63 个字符

关于这个规则，大部分语言都是相同的，这里为什么不能以数字开头，主要是为了避免编译器解析错误，例如 123abc，在解析的时候到底是变量名还是字面量呢？这就会产生歧义。

为什么长度是 63 个字符呢？因为 C 语言诞生的比较早，当时计算资源有限，长度小的变量名可以减少编译器的复杂度和内存空间，其次过长的变量名会增加代码的阅读难度，降低代码的可读性。

注意的是并非所有符合规范要求的都可以作为变量名，每一个编程语言中都有自己的关键字，关键字不能作为变量名，C 的关键字如下:
>*auto, break, case, char, const, continue, default, do, double, else, enum, extern, float, for, goto,*
>
>*if, inline, int, long, register, restrict, return, short, signed, sizeof, static, struct, switch, typedef,*
>
>*union, unsigned, void, volatile, while*

#### 变量的声明

变量的声明需要确定类型，所以变量声明前先了解下数据类型，C 语言只提供了下列几种基本的数据类型：

- char 字符型，占用一个字节
- int 整型，通常反映了所用机器中整数的最自然长度
- float 单精度浮点数
- double 双精度浮点数
- short 限定符，严格意义上来说 short 是 int 的限定整型
- long 限定符，严格意义上来说 long 是 int 的限定整型

int、short 和 long 的区别在于 short 和 int 至少为 16 位，long 至少为 32 位，并且 short 的类型不能长于 int，int 的类型不得常于 long。这个限制主要是限制编译器的。

说回变量的声明，就是类型 + 变量名，并且允许再声明变量的时候进行初始化，例如：

````c
// 只声明不初始化
int lower, upper, step;
// 声明 + 初始化
int num = 52;
// 可以使用 const 限定符限定，表示不可更改，相当于 Java 的 final
const int myConst = 521;

````

#### 作用域

作用域说的是一个变量的有效范围，C 语言的变量作用域有两种，分别是文件作用域和块作用域。

文件作用域是在源码文件顶层声明，从声明位置到文件结束都有效。例如
````c
#include <stdio.h>

int x = 123;

int main(void) {
    return x;
}
````

块作用域说的就是大括号形成的代码块，如下

````c
{
    int s = 1;
    {
        int a = 2;
        int s = 3;
        // 输出 2
        printf("%d\n", a);
        // 输出 3
        printf("%d\n", s);
    }
    // 输出 1
    printf("%d\n", s);
    // 无法编译，报错
    printf("%d\n", a);
}
````

可以看到不同的作用域可以有相同的变量名，直接访问的话就近原则取变量。

### 运算符

C 语言的运算符非常多，下面按照类别来说明。

#### 算术运算符

算术运算符就是专门用于计算的，有如下几种：

- +：正值运算符(一元运算符)
- -：负值运算符(一元运算符)
- +：加法运算符(二元运算符)
- -：减法运算符(二元运算符)
- *：乘法运算符
- /：除法运算符
- %：余值运算符

其中的一元二元的区别就是需要几个运算符。

#### 自增和自减

自增和自减就是自身加一和减一

- ++：自增运算符
- --：自减运算符

````c
i++; // 等同于 i = i + 1
i--; // 等同于 i = i - 1
````

#### 关系运算符

关系运算符一般就是用来比较的，常用用于关系表达式中

- `>`大于运算符
- `<` ⼩于运算符
- `>=` 大于等于运算符
- `<=` ⼩于等于运算符
- `==` 相等运算符
- `!=` 不相等运算符

#### 逻辑运算符

逻辑运算符提供逻辑判断的功能

- ! ：否运算符（改变单个表达式的真伪）
- && ：与运算符（两侧的表达式都为真，则为真，否则为伪）
- || ：或运算符（两侧⾄少有⼀个表达式为真，则为真，否则为伪）

#### 位运算符

位运算符一般用于操作二进制位

- 取反运算符：～，将一个二进制变成相反值
- 与运算符：&，将两个值的每⼀个⼆进制位进⾏⽐较，返回⼀个新的值。当两个⼆进制位都为1，就返回1，否则返回0 *。*
- 或运算符：|，将两个值的每⼀个⼆进制位进⾏⽐较，返回⼀个新的值。两个⼆进制位只要有⼀个为1（包含两个都为1的情况），就返回1，否则返回0 *。*
- 异或运算符：^，将两个值的每⼀个⼆进制位进⾏⽐较，返回⼀个新的值。两个⼆进制位有且仅有⼀个为1，就返回1，否则返回0
- 左移运算符：<<，将左侧运算数的每⼀位，向左移动指定的位数，尾部空出来的位置使⽤0填充，相当于将运算数乘以2的指定次⽅
- 右移运算符：`>>`，将左侧运算数的每⼀位，向右移动指定的位数，尾部⽆法容纳的值将丢弃，头部空出来的位置使⽤0填充，相当于将运算数除以2的指定次⽅

````c
// 3 的 二进制是 11，输出 -4，计算过程如下
// 3 的二进制表示法为 00000000 00000000 00000000 00000011
//   取反得到        11111111 11111111 11111111 11111100
// 在大多数C语言实现中，整数使用二进制补码形式表示，最高位为符号位，1表示负数，在补码表示法中，负数的值是取所有位的反（除符号位外），然后加1。
// 所以结果是 00000000 00000000 00000000 00000100，表示 4， 因为最高位是 1，所以是 -4
printf("%d\n", ~ 3);
// 2 的 二进制是 10，3 的二进制是 11，输出 2
printf("%d\n", 2 & 3);
// 2 的 二进制是 10，3 的二进制是 11，输出 3
printf("%d\n", 2 | 3);
// 2 的 二进制是 10，3 的二进制是 11，输出 1
printf("%d\n", 2 ^ 3);
// 2 的 二进制是 10，3 的二进制是 11，输出 0
printf("%d\n", 2 >> 3);
// 2 的 二进制是 10，3 的二进制是 11，输出 16
printf("%d\n", 2 << 3);
````

#### 逗号运算符

我没想到逗号也算运算符呀。

````c
int z = 10, b = 20;

int y;
y = 1, 2, 3;
// 输出 1，逗号的优先级低于赋值运算符，所以先执⾏赋值运算，再执⾏逗号运算
printf("%d\n", y);
````

#### 运算优先级

在遇到多个运算符一起运算的时候，需要明确哪一个运算符先计算，哪一个后计算，下列由高到低的优先级顺序排列：

- 圆括号（ () ）
- ⾃增运算符（ ++ ），⾃减运算符（ -- ）
- ⼀元运算符（ + 和- ）
- 乘法（ * ），除法（ / ）
- 加法（ + ），减法（ - ）
- 关系运算符（ < 、> 等）
- 赋值运算符（ = ）

### 流程控制

流程控制在大多数语言中都相同，分别是 if、while、do-while、for、switch、三元，c 语言中支持 goto。下面用代码展示

````c
// if - else
int a = 1, b = 2;
if (a == b) {
    printf("%s\n", "1 == 2");
} else {
    printf("%s\n", "1 != 2");
}
// for
for (int i = 0; i < 10; ++i) {
    if (i % 2 == 0) {
        continue;
    }
    printf("%d\n", i);
    if (i == 7) {
        break;
    }
}
// while
while (a != b) {
    printf("%s\n", a + " != " + b);
    a ++;
}
// do-while
do {
    printf("%d, %d\n", a, b);
} while (a != b);
int x = a == b ? 521 : 125;
// 输出 521
printf("%d\n", x);
// switch
switch (a) {
    case 1:
        printf("%d\n", 1);
        break;
    case 2:
        printf("%d\n", 2);
        break;
    default:
        printf("%d\n", 521);
        break;
}
// goto 一般用于跳出多层 for 循环，不过不建议使用，增加代码的复杂度，下面简单掩饰, goto 需要标签，比如下面代码
goto floor;
// 下面这行代码不会执行
printf("%s\d", "goto");
floor:
printf("%s\d", "floor");
````

### 类型说明

C 语言支持的基础类型相对较少，每种类型都有自己的边界。

#### 整数类型

C 语言使用关键字 signed 和 unsigned 表示类型带有正负号，相同字节的不同关键字，表示的范围不相同。

- 16 位：signed 是 -2^(16 - 1)~2^(16-1)-1；unsigned 是 0～2^16 - 1
- 32 位：signed 是 -2^(32 - 1)~2^(32-1)-1；unsigned 是 0～2^32 - 1
- 64 位：signed 是 -2^(64 - 1)~2^(64-1)-1；unsigned 是 0～2^64 - 1

**整数的子类型**：

- short int （简写为short ）：占⽤空间不多于int ，⼀般占⽤2个字节（整数范围为-32768～32767)
- long int （简写为long ）：占⽤空间不少于int ，⾄少为4个字节
- long long int （简写为long long ）：占⽤空间多于long ，⾄少为8个字节

为什么需要子类型呢？一般在静态编程语言中，类型声明之后分配的内存大小是固定的，不会根据实际的值而发生改变，有的时候在知道不会占据更大的内存的时候，可以用小整型，如果内存不够了，就用大整型。

对于上面的极限值来说，C 语言是有静态声明的，是在 limit.h 的头中，一般有下面几种：

- SCHAR_MIN ， SCHAR_MAX ：signed char 的最⼩值和最⼤值
- SHRT_MIN ， SHRT_MAX ：short 的最⼩值和最⼤值
- INT_MIN ， INT_MAX ：int 的最⼩值和最⼤值
- LONG_MIN ， LONG_MAX ：long 的最⼩值和最⼤值
- LLONG_MIN ， LLONG_MAX ：long long 的最⼩值和最⼤值
- UCHAR_MAX ：unsigned char 的最⼤值
- USHRT_MAX ：unsigned short 的最⼤值
- UINT_MAX ：unsigned int 的最⼤值。
- ULONG_MAX ：unsigned long 的最⼤值
- ULLONG_MAX ：unsigned long long 的最⼤值。

代码输出掩饰如下：

````c
#include "stdio.h"
#include "limits.h"

int main(void) {
    // char
    printf("signed char min: %d\n", SCHAR_MIN);
    printf("signed char max: %d\n", SCHAR_MAX);
    printf("unsigned char max: %d\n", UCHAR_MAX);
    // short
    printf("signed short min: %d\n", SHRT_MIN);
    printf("signed short max: %d\n", SHRT_MAX);
    printf("unsigned short max: %d\n", USHRT_MAX);
    // int
    printf("signed int min: %d\n", INT_MIN);
    printf("signed int max: %d\n", INT_MAX);
    printf("unsigned int max: %u\n", UINT_MAX);
    // long
    printf("signed long min: %ld\n", LONG_MIN);
    printf("signed long max: %ld\n", LONG_MAX);
    printf("unsigned long max: %lu\n", ULONG_MAX);
    // long long
    printf("signed long long min: %lld\n", LLONG_MIN);
    printf("signed long long max: %lld\n", LLONG_MAX);
    printf("unsigned long long max: %llu\n", ULLONG_MAX);
    return 0;
}
// 输出如下
signed char min: -128
signed char max: 127
unsigned char max: 255
signed short min: -32768
signed short max: 32767
unsigned short max: 65535
signed int min: -2147483648
signed int max: 2147483647
unsigned int max: 4294967295
signed long min: -9223372036854775808
signed long max: 9223372036854775807
unsigned long max: 18446744073709551615
signed long long min: -9223372036854775808
signed long long max: 9223372036854775807
unsigned long long max: 18446744073709551615
````

**整数的进制**

C 语言的整数默认都是十进制，如果要表示 8 进制和 16 进制，就需要特殊的表示方法。

八进制一般用 0 表示前缀；十六 进制一般用 0X 作为前缀；二进制一般用0b 作为前缀。如果想用 printf 输出对应的进制整数，需要用不同的占位符

- %d：⼗进制整数
- %o ：⼋进制整数
- %x ：⼗六进制整数
- %#o ：显示前缀0 的⼋进制整数
- %#x ：显示前缀0x 的⼗六进制整数
- %#X ：显示前缀0X 的⼗六进制整数

````c
#include "stdio.h"

int main(void) {
    // 八进制
    int a = 012;
    printf("八进制 012 输出十进制为:%d\n", a);
    printf("八进制 012 输出八进制为:%o\n", a);
    printf("八进制 012 输出八进制为:%#o\n", a);
    // 16进制
    int b = 0X10;
    printf("十六进制 0X10 输出十进制为:%d\n", b);
    printf("十六进制 0X10 输出十六进制为:%x\n", b);
    printf("十六进制 0X10 输出十六进制为:%#x\n", b);
    // 二进制
    int c = 0b10;
    printf("二进制 0b10 输出十进制为:%d\n", c);
    return 0;
}
// 输出如下
八进制 012 输出十进制为:10
八进制 012 输出八进制为:12
八进制 012 输出八进制为:012
十六进制 0X10 输出十进制为:16
十六进制 0X10 输出十六进制为:10
十六进制 0X10 输出十六进制为:0x10
二进制 0b10 输出十进制为:2
````

#### 浮点数类型

浮点数的声明用的是 float，float 类型占用 4 个字节，前八位存放指数的值和符号，后面 24 位存放小数的值和符号，C 语言还提供了 double 和 long double 来表示更准确的精度和数值范围，double 占用 8 个字节，long double 占据 16 个字节。由于精度的限制，浮点数只是一个近似值，所以计算也是不准确的，比如说

````c
// 下面 if 中的语句是会输出的
if (0.1 + 0.2 != 0.3) {
    printf("0.1 + 0.2 != 0.3");
}
````

#### 布尔类型

C 语⾔原来并没有为布尔值单独设置⼀个类型，⽽是使⽤整数0表示伪，所有⾮零值表示。

在头文件 `stdbool.h` 中，true 代表 1，false 代表中，使用如下：

````c
#include "stdbool.h"

int main(void) {
    bool flag = true;
    bool flag1 = false;
    return 0;
}
````

#### 溢出

溢出代表着存放的值超出了类型的范围，单吃编译器对待溢出不会报错，而是正常执行，只是输出的结果往往是意想不到的结果。例如下面代码：

````c
#include "stdio.h"
#include "stdbool.h"
#include "limits.h"

int main(void) {
    unsigned char x = 255;
    x = x + 1;
    printf("%d\n", x); // 0
    unsigned int ui = UINT_MAX; // 4,294,967,295
    ui++;
    printf("ui = %u\n", ui); // 0
    ui--;
    printf("ui = %u\n", ui); // 4,294,967,295
    return 0;
}

// 输出如下
0
ui = 0
ui = 4294967295
````

这个就是溢出的一个表现，另外如下代码会出现死循环

````c
// 因为 i 是无符号，所以不可能为负值，当 i = 0 的时候 -1 得到的是 2^32 - 1
for (unsigned int i = n; i >= 0; --i) // 错误
````

所以在进行比较的时候能使用`limits.h`就尽量使用。

#### sizeof 运算符

sizeof是 C 语⾔提供的⼀个运算符，返回某种数据类型或某个值占⽤的字节数量。它的参数可以是数据类

型的关键字，也可以是变量名或某个具体的值。

````c
printf("%zd\n", sizeof(int));
// 参数为变量
int i;
printf("%zd\n", sizeof(i));
// 参数为数值
printf("%zd\n", sizeof(3.14));

// 输出结果为
4
4
8
````

#### 类型自动转换

**赋值运算**

浮点数赋予整数变量时，C 语⾔直接丢弃⼩数部分，⽽不是四舍五⼊。

整数赋值给浮点数变量时，会⾃动转为浮点数。

字节宽度较⼩的整数类型，赋值给字节宽度较⼤的整数变量时，会发⽣类型提升，即窄类型⾃动转为宽类

型。

字节宽度较⼤的类型，赋值给字节宽度较⼩的变量时，会发⽣类型降级，⾃动转为后者的类型。这时可能会

发⽣截值（truncation），系统会⾃动截去多余的⼆进制位，导致难以预料的结果。

````c
#include "stdio.h"

int main(void) {
    int x = 12.99;
    printf("%d\n", x);
    float y = 12 * 2;
    printf("%f\n", y);
    char z = 10;
    int i = z + y;
    printf("%d\n", i);
    int a = 321;
    // 二进制截值
    char ch = a;
    printf("%d\n", ch);
    return 0;
}

// 输出
12
24.000000
34
65
````

有自动转换就有显示转换，我们可以将一个值或者变量强制转换为想要的类型，例如 `(unsigned char) ch`将 ch 变为无符号的字符类型。

之前说过在不同计算机上，可能同一种类型所占用的字节是不相同的，为了控制精确的字节宽度，C 语言再头文件`stdint.h`创造了新的类型别名。

精确宽度类型：

- int8_t ：8位有符号整数
- int16_t ：16位有符号整数
- int32_t：32位有符号整数
- int64_t：64位有符号整数
- uint8_t：8位⽆符号整数
- uint16_t：16位⽆符号整数
- uint32_t：32位⽆符号整数
- uint64_t ：64位⽆符号整数

最小宽度类型：

- int_least8_t
- int_least16_t
- int_least32_t
- int_least64_t
- uint_least8_t
- uint_least16_t
- uint_least32_t
- uint_least64_t

最快的最⼩宽度类型：

- int_fast8_t
- int_fast16_t
- int_fast32_t
- int_fast64_t
- uint_fast8_t
- uint_fast16_t
- uint_fast32_t
- uint_fast64_t

可以保存指针的整数类型：

- intptr_t ：可以存储指针（内存地址）的有符号整数类型
- uintptr_t：可以存储指针的⽆符号整数类型

最⼤宽度整数类型，⽤于存放最⼤的整数：

- intmax_t：可以存储任何有效的有符号整数的类型
- uintmax_t：可以存放任何有效的⽆符号整数的类型

不同的场景可以使用不同的类型别名。

### 指针

