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

指针是什么呢？指针是一个值，这个值代表了一个内存地址，因此指针相当于内存地址的路标。指针使用`*`来表示，跟随在类型和变量名之间，指针本身还可能指向指针，所以这个时候就是两个`*`来表示了。

`*`号也可以作为运算符，比如说 `int* p = *q + 1`，表示修改指针 p 所指向的内存地址中的值。

`&`符号与`*`刚好相反，可以取出值所在的内存地址，也就是说 `i == *(&i)`等式永远成立，例如下方

````c
#include "stdio.h"

void increment(int *pInt);

int main(void) {
    int q = 1;
    increment(&q);
    // 输出 2
    printf("%d\n", q);
    return 0;
}

void increment(int* pInt) {
    *pInt = *pInt + 1;
}

````

#### 指针变量的初始化

声明指针变量后，编译器会为这个变量随机分配一个内存空间，但是这个内存空间里面的值是随机的，也就是说指针变量指向的值是随机的，这个时候一定不能取读写这个指针变量指向的地址，否则可能会造成意想不到的后果，也就是说，下面的代码用法是错误的：

````c
int* p;
*p = 1;
````

虽然编译不会出错，但是不要这么做，那正确的做法是什么呢？应该在指针变量声明后，必须先让它指向一个分配好的地址，然后进行读写，例如下方代码：

````c
int* p;
int w;
p = &w;
*p = 13;
````

这个中，编译器先会给 w 分配内存地址，然后 p 指向 w 的内存地址，这个时候完成初始化，进而可以对内存地址进行赋值。另外说明 NULL 再 C 语言中是一个常量，表示地址为 0 的内存空间，无法被使用，所以读写该地址会报错。

#### 指针的运算

##### 指针与整数的加减

指针与整数的加减表示指针的移动，并且这个移动的长度与指针的类型相关，例如

````c
#include "stdio.h"

int main(void) {
    int* i;
    i = (int*)0xD;
    i = i + 1;
    // 输出 0x11
    printf("%p\n", i);
    short* j;
    j = (short*)0xD;
    j = j + 1;
    // 输入 0xF
    printf("%p\n", j);
    return 0;
}
````

所以指针与整数的加减的是类型的长度，而不是直接值的相加。

##### 指针与指针的加法运算

指针与指针不支持加法运算，所以不要进行指针的相加。

##### 指针与指针的减法运算

相同类型的指针允许做减法运算，返回它们之间的距离，减法返回的值属于`ptrdiff_t`类型，原型定义是在头文件`stddef.h`中。

````c
#include "stdio.h"
#include "stddef.h"

int main(void) {
    int* i1;
    int* i2;
    i1 = (int*) 0x1234;
    i2 = (int*) 0x1230;
    // 输出 1
    printf("%ld\n", i1 - i2);
    // 输出 -1
    printf("%ld\n", i2 - i1);

    short* j1;
    short* j2;
    j1 = (short*) 0x1234;
    j2 = (short*) 0x1230;
    // 输出 2
    printf("%ld\n", j1 - j2);
    // 输出 -2
    printf("%ld\n", j2 - j1);
    return 0;
}
````

从上可以看到，想减的结果除以类型的长度才是之间的距离，如果无法整除，则直接去尾。

##### 指针和指针的比较运算

比较运算就是比较指针的内存地址哪一个更大，返回值是 1 或者 0。

````c
#include "stdio.h"
#include "stddef.h"
#include "stdbool.h"

int main(void) {
    int* i1;
    i1 = (int*) 0x1234;
    int* j3;
    j3 = (int*)0x1234;
    // 输出 0
    printf("%d\n", i1 > j3);
    // 输出 0
    printf("%d\n", i1 < j3);
    // 输出 1
    printf("%d\n", i1 == j3);
    return 0;
}
````

指针小结，指针其实就是内存地址，操作内存地址需要格外的小心，`*`可以取指针的值，`&`可以取变量的内存地址，指针的运算往往与指针的类型相关，指针和指针之间只允许减法。

### 函数

函数在很多地方也被称为方法，就是一段可以接受同种类型的不同参数，可重复执行的代码，函数的要素有下面几点：

1. 函数需要有返回值类型，比如我们的 main 就是入口函数，返回类型是 int，无返回值可以使用 void
2. 参数，函数需要有参数，main 函数可以接受参数，我们之前的例子都是 void，之前的 increment 函数的参数就是整数指针
3. 函数体，大括号内部的内容都是函数体
4. 返回值，因为函数有返回值类型，返回值需要和返回值类型匹配
5. 方法名，方法名很重要，要做到见名知意

函数的注意事项：

1. C 语言中规定，函数的声明必须在源码文件的顶层，不能声明在其它函数的内部，例如

````c
#include "stdio.h"
// 函数声明
void increment(int *pInt);

int main(void) {
    int q = 1;
    increment(&q);
    printf("%d\n", q);
    return 0;
}

void increment(int* pInt) {
    *pInt = *pInt + 1;
}
````

2. 函数的调用就是直接使用方法名+括号和参数就可以，参数不可以多传，也不可以少传，类型也必须和声明的参数保持一致，否则会报错



#### main()

C 语言规定，main() 是程序的入口函数，也就是所有的程序都有一个`main()`函数，执行从 main 开始，其它程序都是通过 main 引入的。如下：

````c
int main(void) {
  printf("Hello World\n");
  return 0;
}
````

C 语言规定，返回 0 表示函数执行成功，返回其它非 0 整数，表示运行失败。

#### 参数的传递

##### 值传递

如果函数的参数是一个变量，那么调用的时候，传入的是这个变量的值的拷贝，而不是变量本身，这就是值传递。

````c
#include "stdio.h"

int valueTransfer(int a);

int main(void) {
    int a = 10;
    valueTransfer(a);
    printf("值传递不改变原变量，传递的是变量值的拷贝：%d\n", a);
    a = valueTransfer(a);
    printf("值传递有返回值的变化：%d\n", a);
    return 0;
}


int valueTransfer(int a) {
    a ++;
    return a;
}

// 输出结果为
值传递不改变原变量，传递的是变量值的拷贝：10
值传递有返回值的变化：11
````

既然如此，我想传入变量本身，应该如何做呢？借用指针，指针就是一块内存地址，传入地址，那修改的就是地址的内容，如下

````c
#include "stdio.h"

void swap(int* x, int* y);

int main(void) {
    int x = 1, y = 2;
    swap(&x, &y);
    printf("交换后 x 的值为 %d, y 的值为 %d \n", x, y);
    return 0;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 输出的结果为
交换后 x 的值为 2, y 的值为 1 
````

要注意的是不要返回内部变量的指针，因为内部变量在退出方法的时候就销毁了，所以地址中的值也就为空了，没有意义。

#### 函数指针

函数本身就是一段内存里面的代码，C 语言允许通过指针获取函数，例如：

````c
#include "stdio.h"
#include "stdbool.h"

void print(int a);

int main(void) {
    // 获取函数的地址作为变量，printNum 是一个函数指针
    void (*printNum)(int) = &print;
    // 使用函数指针调用函数
    printNum(10);
    return 0;
}

void print(int a) {
    printf("%d\n", a);
}

// 输出
10
````

C 语言特殊的地方就在于函数名本身就指向函数的地址，所以下面代码会进行输出

````c
#include "stdio.h"
#include "stdbool.h"

void print(int a);

int main(void) {
    // 函数名本身指向函数代码的指针
    if (&print == print) {
        printf("函数名本身指向函数代码的指针\n");
    }
    void (*printNum1)(int) = print;
    printNum1(11);
    printf("printNum1 == printNum %d\n", printNum1 == printNum);
    return 0;
}

void print(int a) {
    printf("%d\n", a);
}

// 输出
函数名本身指向函数代码的指针
11
printNum1 == printNum 1
````

那这个函数指针的意义在哪里呢？那就是在函数原型中，函数的参数和返回值可以是函数，这个就很有意思了。

#### 函数原型

函数必须先声明，后使用，而因为 C 语言的执行入口是 main 方法，所以函数的声明必须再 main 函数之前，否则会出现编译警告，找不到函数。

函数原型是什么呢？上面说函数需要在 main 前进行声明，这样就会造成主要逻辑放在最后面，所以 C 语言提供了函数原型，告诉编译器每个函数的返回类型和参数类型，不需要写方法体，方法体可以在 main 函数之后补上，如下：

````c
#include "stdio.h"
#include "stdbool.h"

// 函数原型
void print(int a);

int main(void) {
    // 获取函数的地址作为变量，printNum 是一个函数指针
    void (*printNum)(int) = &print;
    // 使用函数指针调用函数
    printNum(10);

    // 函数名本身指向函数代码的指针
    if (&print == print) {
        printf("函数名本身指向函数代码的指针\n");
    }
    void (*printNum1)(int) = print;
    printNum1(11);
    printf("printNum1 == printNum %d\n", printNum1 == printNum);
    return 0;
}

// 函数体
void print(int a) {
    printf("%d\n", a);
}
````

#### exit()

`exit()`函数是用来终止整个程序的运行，该函数的定义是在头文件`stdlib.h`中，一旦执行到此函数，程序立即结束。

`exit()` 可以向程序外部返回⼀个值，它的参数就是程序的返回值。⼀般来说，使⽤两个常量作为它的参数： `EXIT_SUCCESS` （相当于 0）表示程序运⾏成功，`EXIT_FAILURE` （相当于 1）表示程序异常中⽌。这两个常数也是定义在`stdlib.h`⾥⾯。

````c
#include "stdio.h"
#include "stdlib.h"

void print() {
    exit(EXIT_FAILURE);
    printf("Hello World!\n");
}

int main(void) {
    print();
//    exit(EXIT_SUCCESS);
    printf("Hello My World!\n");
    return 0;
}
````

无论是在函数中，还是再 main 方法中，只要遇到了 exit，程序就会立即终止，后续的任何程序都不会运行。

C 语言还提供了另外一个函数 `atexit()`，这个和 `exit()`的区别就在于可以传递一个函数，可以用来做退出程序时的收尾工作，该函数的原型也是在`stdlib.h`中。

````c
int	 atexit(void (* _Nonnull)(void));
````

作为参数的函数是有两个要求，那就是不能有参数，并且不能有返回值，这个让我想起了 Java 中的异常，但是又不太一样。

````c
#include "stdio.h"
#include "stdlib.h"

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

// 输出
Hello!
````

#### 函数说明符

函数说明符，是为了让编译器更加精确的知道函数的具体使用。

##### extern 说明符

对于多文件的项目，源码文件会用到其他文件声明的函数，这里就需要在当前文件中给出外部函数的原型，并用 `extern`说明该函数的定义来自于其他文件。

````c
#include "stdio.h"
#include "stdlib.h"

void swap(int* x, int* y);

int main(void) {
		int x = 10, y = 11;
		swap(&x, &y);
    return 0;
}
````

上面的代码中，swap 就是声明在另外一个文件中，这里没有使用 `extern` 的原因是函数原型默认就是 `extern`，所以可以不加此说明符。

##### static 说明符

static 可以用于声明变量，也可以用于声明函数，声明变量表示只需要初始化一次，static 变量的初始化只能赋值为常量，而不能是变量，初始化后每次调用保持不变，这里给我感觉就像是全局变量，只不过这个全局变量是在作用域的全局：

````c
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

// 输出
1
2
3
4
5
````

也就是我在调用 counter 的时候，内部变量 count 不会重新赋值，而是从上一次计算之后开始继续计算。

那放在函数上是什么意思呢？可以看到 counter 就是使用 static 修饰的，这个意思就是私有，只能我当前文件使用，其它文件无法通过声明函数原型的方法来使用此函数。

另外就是 static 可以用来修饰数组的长度，但是只可以修饰一维数组，如果是二维数组，只能修饰行。

##### const 说明符

const 表示不可修改，这个主要是放在函数参数中的，表明函数内部不得修改，但是 const 放的位置不同，不允许修改的范围不同，如下：

````c
#include "stdio.h"

// 放在类型之前，允许修改指向的地址，但是不允许修改值
void print(const int *p) {
    // 下面行报错，编译不通过
    // *p = 521;

    // 下面行允许操作
    int x = 521;
    p = &x;
    printf("print: %d\n", *p);
}

// 放在变量之前，允许允许修改值，但是不修改指向的地址
void print1(int *const p) {
    // 下面行允许操作
    *p = 529;

    // 下面行报错，编译不通过
//    int x = 521;
//    p = &x;
    printf("print1: %d\n", *p);
}

void print2(const int *const p) {
    // 下面行报错，编译不通过
    // *p = 521;

    // 下面行报错，编译不通过
//    int x = 521;
//    p = &x;
    printf("print2: %d\n", *p);
}

int main(void) {
    int p = 123;
    printf("main: %d\n", p);
    print(&p);
    print1(&p);
    print2(&p);
}
````

总结下来就是：

1. const 放在类型之前，表示不允许修改值，但是允许修改地址，例如上面的 print
2. const 放在变量之前，表示不允许修改地址，但是允许修改值，例如上面的 print1
3. 如果两个地方都放了，那就都不允许修改了，例如上面的 print2

##### 可变参数

可变参数就是有多少个参数是不确定的，声明函数的时候，可以使用`...`来表示可变数量的参数：

````c
int printf(const char* format, ...);
````

在函数的原型中，表示可变参数的`...`必须放在参数的末尾，否则会报错。

那生命了如何操作呢，操作可变参数的宏放在了`stdarg.h`中，有如下几个：

1. va_list：一个数据类型，用来定义一个可变参数对象。必须在操作可变参数时，首先使用
2. va_start：一个函数，用于初始化可变参数对象。它接受两个参数，第⼀个参数是可变参数对象，第⼆个参数是原始函数⾥⾯，可变参数之前的那个参数，⽤来为可变参数定位
3. va_arg：⼀个函数，⽤来取出当前那个可变参数，每次调⽤后，内部指针就会指向下⼀个可变参数。它接受两个参数，第⼀个是可变参数对象，第⼆个是当前可变参数的类型。
4. va_end：⼀个函数，⽤来清理可变参数对象。

````c
#include "stdio.h"
#include "stdarg.h"

// 这里的 i 表示可变参数的个数
double average(int i, ...) {
    double total = 0;
    // 可变参数对象
    va_list ap;
    // 将 i 后面的参数统一放到 ap 中
    va_start(ap, i);
    // 遍历累加
    for (int j = 1; j <= i; ++j) {
        total += va_arg(ap, double);
    }
    // 清理可变参数对象
    va_end(ap);
    return total / i;
}

int main(void) {
    // 注意的是传递的参数要和期望的参数类型相同
    double avg = average(5, 2.0, 4.0, 6.0, 8.0, 10.0);
    printf("%f\n", avg);
}
````

下面提供两段错误代码，是我个人在测试的时候遇到的问题：

````c
#include "stdio.h"
#include "stdarg.h"

// 这里的 i 表示可变参数的个数
int average(int i, ...) {
    int total = 0;
    va_list ap;
    va_start(ap, i);
    for (int j = 1; j <= i; ++j) {
    		// 错误的地方
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total / i;
}

int main(void) {
    int avg = average(5, 2, 4, 6, 8, 10);
    printf("%d\n", avg);
}
````

````c
#include "stdio.h"
#include "stdarg.h"

// 这里的 i 表示可变参数的个数
double average(int i, ...) {
    double total = 0;
    va_list ap;
    va_start(ap, i);
    for (int j = 1; j <= i; ++j) {
        total += va_arg(ap, double);
    }
    va_end(ap);
    return total / i;
}

int main(void) {
		// 错误的地方
    double avg = average(5, 2, 4, 6, 8, 10);
    printf("%f\n", avg);
}
````

### 数组

数组的概念就是同一种类型的值按照顺序的方式存储在一起，数组的声明是 `int scores[100]`，其中 100 就是数组的容量，数组在声明的时候必须指明容量，数组的索引都是从 0 开始，例如上面声明的数组访问第一个和访问最后一个的代码如下
````c
int scores[100]；
scores[0] = 1;
scores[99] = 100;
````

**C 语言有个神奇的地方就是我可以访问越界的元素，并不会报错，但是会不知不觉更改其它变量的值，这很容易引发错误并不易被发现，所以不要越界访问尤为重要。**

#### 数组的初始化

数组的初始化就是两种方式，分别是索引初始化和大括号初始化，下面代码展示下：

````c
#include "stdio.h"

int main(void) {
    // 索引初始化
    int arr1[10];
    arr1[0] = 1;
    arr1[9] = 10;
    // int 中没有被初始化的
    printf("%d\n", arr1[5]);
  	// 这里的 sizeof 来计算数组的长度，这里在下面说
    for (int i = 0; i < (sizeof(arr1) / sizeof(arr1[0])); ++i) {
        printf("%d\n", arr1[i]);
    }
    printf("=================================\n");
    // 大括号初始化
    int arr2[] = {1,2,3,4,5,6,7,8};
    // 输出 8
    printf("%d\n", arr2[7]);
    for (int i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); ++i) {
        printf("%d\n", arr2[i]);
    }
    int arr3[] = {[2] = 10, [20] = 30};
    // 输出 30
    printf("%d\n", arr3[20]);
}

// 输出结果
1
1
1
1864446448
1
1864446224
1
-2007382928
-1890058239
12516752
10
=================================
8
1
2
3
4
5
6
7
8
30
````

可以看出再第一个数组中，没有被初始化的值，变成了随机值，这个是因为数组 10 的位置不直到在哪里，从而无法确定值是多少。

#### 数组的长度

数组的长度如何计算呢？上面的代码其实已经展示了，那就是 sizeof，sizeof 具体是什么意思呢？sizeof 运算符会返回整个数组的字节长度，注意是字节长度，那元素数量如何计算呢？那就是数组的字节长度除以单个元素的字节长度：`sizeof(arr2) / sizeof(arr2[0])`

#### 多维数组

C 语言允许声明多维数组，有多少个维度，就用多少个方括号，例如二维数组就是两个括号 `int board[10][10];`，但是无论数组有多少个维度，都是线性存储的。

#### 变长数组

数组声明的时候，数组长度出了使用常量外，还可以使用变量，这就叫做变长数组，变长数组在运行期间才可以确定长度

````c
int n = a + b;
int a[n];
````

其中的 a 数组就是变长数组，任何在运行期间长度才能确定的数组都是变长数组。

#### 数组的地址

数组是一连串连续存储的同类型值，所以只要获得起始地址，就能推算出其它成员的地址

````c
#include "stdio.h"

int sum(int arr[], int len);

int main(void) {
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // 使用首元素的地址推其它成员的地址
    int *p = &arr2[0];
    printf("%d\n", *p);
  	// 这里我以为是根据字节确定地址呢？其实并不是，+1 就是获取下一个索引的元素
    printf("%d\n", *(p + 4));
    printf("arr2 sum : %d\n", sum(p, sizeof(arr2) / sizeof(arr2[0])));
}

int sum(int arr[], int len) {
    int total = 0;
    for (int i = 0; i < len; ++i) {
        total += arr[i];
    }
    return total;
}
// 输出结果为
1
5
arr2 sum : 36
````

注意的是不允许修改数组名指向的地址，也是也容易思考，我如果可以随意修改数组指向的地址，那我就可以随意破坏地址，原来的数组地址也就无法找到，成为垃圾数据了，这非常不安全。

#### 数组指针的加减法

C 语言中，数组名也可以进行加法和减法运算，等同于再数组成员之间前后移动，即从一个成员的内存地址移动到另一个成员的内存地址，+1 是后移，-1 是前移。

````c
int a[5] = {11, 22, 33, 44, 55};
for (int i = 0; i < 5; i++) {
	printf("%d\n", *(a + i));
}
````

使用 while 循环

````c
#include "stdio.h"

int sum(int arr[], int len);
int sum1(int* start, int* end);
int main(void) {
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *p = &arr2[0];
    printf("%d\n", *p);
    printf("%d\n", *(p + 4));
    printf("arr2 sum : %d\n", sum(p, sizeof(arr2) / sizeof(arr2[0])));
    printf("arr2 sum : %d\n", sum1(p, p + 8));
}

int sum(int arr[], int len) {
    int total = 0;
    for (int i = 0; i < len; ++i) {
        total += arr[i];
    }
    return total;
}

int sum1(int* start, int* end) {
    int total = 0;
    while (start < end) {
        total += *start;
        start ++;
    }
    return total;
}
// 输出
1
5
arr2 sum : 36
arr2 sum : 36
````

#### 数组的复制

由于数组名就是指针，所以复制数组不能简单的复制数组名，也就是如何进行深拷贝。

复制最简单的方法还是使用循环

````c
for (i = 0; i < N; i++)
		a[i] = b[i];
````

另外一种方法是使用 `memcpy()` 函数，定义再`string.h`头文件中，意思是把数组所在的那一段内存，复制一份。

````c
memcpy(a, b, sizeof(b));
````

参数分别是目标数组 a，原数组 b，复制的长度是 sizeof(b)。

#### 将数组作为函数的参数

将数组作为函数的参数时，一般要传入数组名以及数组的长度(这里我比较疑惑的是数组的长度不能直接计算出来吗？)，下面使用实例展示。

````c
#include "stdio.h"

int sumArr(int arr[], int len);

int sumArr1(int arr[][4], int len);

int sumArr2(int arr[]);

int main(void) {
    // 声明数组
    int arr[] = {1, 2, 3, 4};
    printf("sizeof(arr) : %lu\n", sizeof(arr));
    printf("sizeof(arr[0]) : %lu\n", sizeof(arr[0]));
    // 调用函数
    printf("调用传入数组名以及长度的函数：%d\n", sumArr(arr, 4));
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

// 输出的结果是
sizeof(arr) : 16
sizeof(arr[0]) : 4
调用传入数组名以及长度的函数：10
sizeof(arr) : 8
sizeof(arr[0]) : 4
调用传入数组名，不传入长度的函数：3
调用传入数组名和传入长度的函数：36
````

从结果来看一维数组一定要传入长度，通过 sizeOf 是无法获取长度的，而是获取的指针的长度，对于二维数组而言，一维的长度要传入，二维的长度要在参数中进行声明。

如果是变长数组，则数组的长度一定要在数组之前，如下

````c
int sumArr3(int len, int arr[len]);
int sumArr3(int len, int arr[len]) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }
    return sum;
}
````

字面量数组作为参数，就是直接将数组作为参数传给方法，如下

````c
sumArr((int[]) {1, 2, 3, 4}, 4);
int sumArr(int arr[], int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }
    return sum;
}
````

### 字符串

C 语言没有单独的字符串类型，字符串被当作字符数组，比如字符串 Hello 实际存储的是`{'H','e','l','l','o','\n'}`。最后的 \n 表示的是字符串的结束符，二进制的形式为 00000000。

虽然如此，但是 C 语言提供了一种极简的写法，双引号中间的字符，会被自动视为字符数组，如果字符串过长，可以在需要折行的地方，使用 \ 结尾，将一行拆分为多行。

#### 字符串变量的声明

字符串的声明可以以字符数组的方式声明，也可以以指针的方式声明，如下：

````c
char s[14] = "Hello, world!";
// 长度可以省略或者大于实际的长度，但是不能小于，注意要考虑以后的结束符，所以在声明的时候尽量不要写长度
char s2[] = "Hello, world!";
char* s1 = "Hello, world!";
printf("%s\n", s);
printf("%s\n", s1);
printf("%s\n", s2);

//输出
Hello, world!
Hello, world!
Hello, world!
````

两种不同方法的差异是，使用指针的方式声明，字符串为常量，无法进行修改，例如：

````c
char* s = "Hello, world!";
s[0] = 'z'; // 错误，执行中断，但是是非受检异常

char s[14] = "Hello, world!";
s[0] = 'a';
printf("%s\n", s);
// 输出
aello, world!
````

为什么指针的方式无法修改呢？原因是指针的字符串保存在内存栈区，栈区的值由系统管理，一般不允许的修改；数组字符串的副本会被拷贝到堆区，堆区的值由用户管理，可以被修改。如果使用指针的方式，建议加上修饰符 const，表明只读，不可修改。

````c
const char* s = "Hello, world!";
````

第二个差异就是指针变量可以指向其它字符串，但是字符数组的变量不可以

````c
char* pointStr = "How are you?";
pointStr = "Hello, Siri!";
char arrStr[] = "Hello";
arrStr = "World"; // 错误，受检异常，编译器直接报错
````

原因在于字符数组的变量名是和指向的数组绑定的，不能指向另外一个数组。那如果我声明了，但是没有赋值，后续如何赋值呢？可以使用C语言提供的`strcpy()`函数。

````c
char arrStr[10];
strcpy(arrStr, "Hello");
printf("%s\n", arrStr);
````

函数是在头 `#include <string.h>` 中。

#### strlen() 

`strlen()`返回字符串的长度，不包括结束符号，同样是在头`string.h`中。

````c
char arrStr[10];
strcpy(arrStr, "Hello");
printf("%s\n", arrStr);
printf("字符串 arrStr 的长度为：%lu\n", strlen(arrStr));
printf("字符串 arrStr 的字符串长度为：%lu\n", sizeof(arrStr));
// 输出为
Hello
字符串 arrStr 的长度为：5
字符串 arrStr 的字符串长度为：10
````

如果要自己计算长度呢？那就只能遍历数组，然后寻找结束符，结束符之前的都是有效长度。

#### strcpy()

字符串的复制，不能使用赋值运算符(=)，如果是指针的话使用赋值运算符表示将指针的地址赋给另外一个指针，而不是值的复制。

注意的是复制的时候目标字符串数组的长度不能小于源字符串数组的长度，否则虽然不会报错，但是会溢出边界，可能造成难以预料的结果。

````c
#include <string.h>
#include "stdio.h"

int main(void) {
    char arrStr[10];
    strcpy(arrStr, "Hello");
    printf("%s\n", arrStr);

    char copyStr[100];
    strcpy(copyStr, arrStr);
    copyStr[0] = 'a';
    printf("%s\n", arrStr);
    printf("%s\n", copyStr);
}
// 输出
Hello
Hello
aello
````

`strcpy()` 返回值是第一个字符串的指针，如下

````c
char s10[] = "best!";
char s20[20] = "I'm good!";
char* ps = strcpy(s20 + 4, s10);
printf("%s\n", s10);
printf("%s\n", s20);
printf("%s\n", ps);
// 输出
best!
I'm best!
best!
````

#### strncpy()

`strncpy()`和`strcpy()`相同，只是多了第三个参数用于控制复制的最大字符数，防止溢出。

````c
char s20[20] = "I'm good!";
char s30[30];
strncpy(s30, s20, 3);
s30[4] = '\n';
printf("%s\n", s30);
// 输出
I'm
````

#### strcat() 以及 strncat()

字符串连接，`strcat()` 接收两个字符串参数，会将第二个字符串的值拼接到第一个字符串的后面，会改变第一个字符串。

`strncat()` 接收三个参数，第三个参数表示拼接的最大长度，为了不超过字符串1的最大长度，一般的写法是 `sizeof(str1) - strlen(str1) - 1`。`strncat()`总会在拼接的结尾后添加\n，并且为了避免溢出，推荐使用`strncat()`

````c
char* pointStr = "Hello, Siri!";
char s20[20] = "I'm best!";
strncat(s20, pointStr, sizeof(s20) - strlen(s20) - 1);
printf("s20: %s\n", s20);
// 输出
s20: I'm best!Hello, Sir
````

#### strcmp()以及strncmp()

字符串的对比只能一位一位字符进行对比，C 语言提供了 strcmp() 函数用于比较两个字符串的内容，根据字典的顺序，返回值有三种情况，相等返回0，s1小于s2返回值小于0，s1大于s2，返回值大于0。

````c
// 比较
char cmpS1[] = "Hello World!";
char cmpS2[] = "Hello World!";
char cmpS3[] = "Hello Z";

printf("s1 cmp s2: %d\n", strcmp(cmpS1, cmpS2));
printf("s2 cmp s3: %d\n", strcmp(cmpS2, cmpS3));
printf("s3 cmp s2: %d\n", strcmp(cmpS3, cmpS2));
// 输出如下
s1 cmp s2: 0
s2 cmp s3: -3
s3 cmp s2: 3
````

strncmp() 是只比较到前多少个字符。

````c
printf("s3 ncmp s2: %d\n", strncmp(cmpS3, cmpS2, 5));
// 输出
s3 ncmp s2: 0
````

#### sprintf()以及snprintf()

sprintf()与printf()类似，但是不是输出到显示器，而是将数据写入字符串，函数定义在 stdio.h 头文件中。

sprint()有多个参数，第一个参数是写入到的字符串，第二个是格式字符串，后续的都是待写入的变量列表。

````c
// 写入
char printS1[] = "Hello";
char printS2[] = "World";
char printS3[12];
sprintf(printS3, "%s %s", printS1, printS2);
printf("printS3: %s\n", printS3);
// 输出
printS3: Hello World
````

如果遇到错误，返回负值。

snprintf() 多了一个参数，就是写入的最大长度，如下就是 12，snprintf 返回值是写入变量的字符数量，不包括尾部的 \n，因此返回值应该小于我们定义的最大长度，如果遇到错误，返回负值。

````
// 写入
char printS1[] = "Hello";
char printS2[] = "World";
char printS3[12];
snprintf(printS3, 12, "%s %s", printS1, printS2);
printf("printS3: %s\n", printS3);
// 输出
printS3: Hello World
````

### 字符串数组

如果一个数组的每一个成员都是字符串，需要通过二维的字符数组来实现，含义就是每个字符串本身就是数组，多个字符串再组成一个数组。

````c
// 字符串数组
char colors1[4][6] = {"red", "green", "blue", "pink"};
char colors2[][6] = {"red", "green", "blue", "pink"};
char* colors3[] = {"red", "green", "blue", "pink"};
for (int i = 0; i < sizeof(colors3) / sizeof(colors3[0]); ++i) {
    printf("colors %d : %s\n", i, colors3[i]);
}
// 输出
colors 0 : red
colors 1 : green
colors 2 : blue
colors 3 : pink
````

二维数组中，一维的长度可以省略，二维的长度不可以，注意二维应该是所有字符串中最长字符串的长度，并且要包含结束符，所以一般使用指针的方式来初始化字符串数组，避免计算。

## C 语言的内存管理

内存管理是基于变量的声明周期来做的，主要是系统管理的栈区以及用户管理的堆区，对于局部变量来说，是在栈区，函数运行时进入内存，结束之后从内存中卸载，存储在**栈**上；对于全局变量来说，系统无法进行管理，只能用户来手动释放，如果使用后忘记释放，就会一直占用内存，这就是**内存泄漏**，这些变量存储在**堆**上。

### void 指针

void 指针的使用是在我不知道这个内存块是什么类型，只有在使用到该内存块的时候，再向编译器进行说明，void 指针只有内存块的地址信息。

这个 void 指针让我想起了 Java 中的 Object，是不是借鉴了 void 指针呢？Java 中所有的对象都继承了 Object，都是 Object 的子类，都可以与 Object 进行相互转换，和 void 指针式极其相似。

````c
#include "stdio.h"

int main(void) {
    // void 指针
    int i = 10;
    // 整数指针转化为 void 指针
    void* vPoint = &i;
    // void 指针转化为整数指针
    int* iPoint = vPoint;
  	// 结果输出为 10
    printf("iPoint: %d\n", *iPoint);
  	// 以下写法错误，因为不知道类型，不可以直接使用
    // printf("iPoint: %d\n", *vPoint);
}
````

### 内置函数

#### malloc() 以及 free()

malloc() 函数用于分配内存，也就是向系统要一段内存，函数存放在头 stdlib.h 中。

malloc() 函数需要传入分配内存的大小，返回的是 void 指针，因为不知道存放的是什么类型，所以常见的做法就是把分配类型的字节长度传入：

````c
// malloc
int* iMalloc = malloc(sizeof(int));
*iMalloc = 10;
// 输出 10
printf("iMalloc: %d\n", *iMalloc);
````

申请内存是有失败的风险，因此在申请完了之后尽量检查一下，如果申请失败会返回 NULL。

内存申请可以在创建数组的时候使用。下面使用 malloc 申请一个字符串数组

````c
#include <string.h>
#include "stdio.h"
#include "stdlib.h"

int main(void) {
    // 使用 malloc 声明一个字符串数组，5个元素，最大长度为12
    char** strArr = malloc(5 * sizeof(char *));
    if (strArr == NULL) {
        perror("malloc for strArray failed");
        exit(EXIT_FAILURE);
    }
    // 为每一个字符串分配内存
    for (int i = 0; i < 5; ++i) {
        strArr[i] = malloc(12);
        if (strArr[i] == NULL) {
            perror("malloc for strArray[i] failed");
            // 释放之前分配的所有内存
            for (int j = 0; j < i; ++j) {
                free(strArr[j]);
            }
            free(strArr);
            exit(EXIT_FAILURE);
        }
    }
    strcpy(strArr[0], "Hello");
    strcpy(strArr[1], "World");
    strcpy(strArr[2], "This");
    strcpy(strArr[3], "Is");
    strcpy(strArr[4], "C Language");

    // 打印字符串数组
    for (int i = 0; i < 5; ++i) {
        printf("String %d: %s\n", i, strArr[i]);
    }
    // 释放内存
    for (int j = 0; j < 5; ++j) {
        free(strArr[i]);
    }
    free(strArr);
}
// 输出
String 0: Hello
String 1: World
String 2: This
String 3: Is
String 4: C Language
````

free() 函数就是用于释放申请的内存，如果不释放，那在程序结束之前，申请的内存在不使用的情况下就会出现内存泄漏，尤其是在子函数中。

````c
void gobble(double arr[], int n) {
	double* temp = (double*) malloc(n * sizeof(double));
}
````

代码中的 temp 如果不释放的话，每次调用都会带来一个内存块的申请与泄漏，因为离开了函数之后，temp 就被销毁了，之前申请的内存谁也无法访问到。

#### calloc() 

calloc() 与 malloc() 的作用类似，都是用于内存申请，不同的地方在于 calloc 接收两个参数，第一个是需要分配的元素数量，第二个是每个元素的大小，以字节为单位，第二个不同点就是 calloc 函数会进行初始化，所以 calloc = malloc + memset。

````c
// calloc
int* pCalloc = calloc(10, sizeof(int));

// 等同于
int* qMalloc = malloc(10 * sizeof(int));
memset(qMalloc, 0, (sizeof(int)) * 10);
````

#### realloc()

realloc 的意思是重新分配内存，有种扩容以及缩减的味道在，接收两个参数，第一个参数是已经分配好的内存块指针，也可以是 NULL，如果是 NULL，表示新建一个内存块指针；第二个参数表示内存块的新大小，新大小可能大于原来的内存块大小，也可能小于，还可以是0，0表示释放，小于就是丢弃超出的部分，大于会新增内存空间，但不会对新的内存空间初始化，也就是要开发者来调用memset()。

````c
// calloc
int* pCalloc = calloc(10, sizeof(int));

// realloc,扩容为 1000
pCalloc = realloc(pCalloc, sizeof(int) * 1000);
int* rCalloc = realloc(NULL, sizeof(int) * 2000);
````

#### restrict 说明符

restrict 可以使用在指针变量声明的时候，表示受限指针，这个和 Java 中的 final 相似，比如说 String 被final 修改，一旦初始化就不可修改，这里也是相同的，一旦声明了受限指针，并且分配了内存，这意味着这块内存只有当前指针可以访问，其它指针不可以访问。

````c
int* restrict pRestrict = malloc(sizeof(int));
int* q = pRestrict;
*q = 100;
printf("pRestrict: %d\n", *pRestrict);
````

上面的程序会正常运行，也就是说违反`restrict`规则通常会导致未定义的行为，这意味着编译器可能生成的代码并不保证按照你预期的方式运行，但是这并不是强一致的运行时检查异常。 

#### memcpy()





