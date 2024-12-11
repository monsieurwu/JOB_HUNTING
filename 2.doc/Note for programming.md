# Note for programming

## C语言

#### 1.计算数组元素大小

```c
int n = sizeof(arr) / sizeof(arr[0]);
```

#### 2.如果const修饰数组，则数组中所有元素的值是不能更改的

```c
const int stu_score[] = {55, 66, 77, 88, 99};
```

#### 3.数组作为参数传递时直接传递数组名就可以，不需要加取地址符，并且需要把数组大小也传递给函数

```
    reverse_array(arr, n);
```

同时函数声明有两种写法

```c
void reverse_array(int array[], int num);
```

或者

```c
void reverse_array(int *array, int num);
```

传递数组大小是因为：

- 数组在函数参数中退化为指针，无法获取长度。
- `sizeof` 在函数内只能获得指针的大小，而不是数组的大小。
- 通过传递大小，函数能够正确地操作数组，避免越界错误

#### 4.从键盘读入字符直到EOF（ctrl+d）停止

while配合getchar()函数 从键盘读取多行字符串

```c
 while ((c = getchar()) != EOF)
```

#### 5.统计输入字符中各个数字、空格符、换行符以及其他所有字符所出现的次数

```c
if (c >= '0' && c <= '9')
            ++n_digit[c - '0'];
        else if (c == ' ')
            n_space++;
        else if (c == '\n')
            n_newline++;
        else
            n_other++;
```

#### 6.字符串变量的长度不包括`\0`,但字符串变量中如果存了字符串常量，是会存在一个`\0`在末尾的

strlen中计算字符串长度 是不包括`\0`字符的；而如果用sizeof对字符串数组取值，是包括`\0`的

```c
strlen(str) == sizeof(str) - sizeof('\0');
```

#### 7.标识符可以由数字、字符和下划线组成，并且开头必须是字母或者下划线

#### 8.const修饰的变量会变成常量，初始化赋值后就不能修改

```c
const int age =33;
```

#### 9.在c语言中除0或者对0取余是不合法的语句

#### 10.函数自己调用自己就被称为递归（recursive）

斐波那契数列:每一项等于前两项之和

```c
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

#### 11.指针指向的内容不可修改

```
const int *p = &x;
int const *p = &x;
```

这两个是等价的 p指向的内容不可更改 但是p本身可以更改

```
int *const p;
```

这样才是指针本身不可更改

```
int const * const p = &x;
```

这样就是指针本身与指向内容均不可修改

#### 12.指针指向数组做遍历

```c
int score[] = {2, 3, 4, 5};
int *p = NULL;
for(p = score; p < score+4; p++)
{
	printf("%d:%d\n", i++, *p);
}
```

#### 13.数组作为函数参数

```
void calc_scores(int scores[]， int scores_length);
void calc_scores(int scores[5]， int scores_length);
void calc_scores(int *scores)， int scores_length;
```

这三种写法是等价的， 通常都会带上数组长度

#### 14.用指针指向字符串

```c
char *str = "hello world";
```

用数组下标或是取值运算符都是可以的

但不能对字符串进行修改 因为字符串是只读的常量

```c
const char *str = "hello world";
```

为避免意外修改字符串 导致crash 用const修饰

#### 15.字符串常量和字符串变量

```
char *str = "hello world";
char str[] = "hello world";
```

`char *str = "hello world";`：指针可以指向其他字符串，但内容不可变。

`char str[] = "hello world";`：数组内容可修改，但数组本身不可指向其他字符串。

#### 16.通过指针计算字符串大小

因为字符串最后一位是`\0`

```c
char hi[]= "hello world";
char *p = NULL;
for(p = hi;*p !='\0';p++);
printf("字符串hi的长度是:%d\n"，p-hi);
```

#### 17.指针作为传入参数

```c
#include <stdio.h>

void func(int *a) {
	printf("a指向空间中的值是:%d\n"，*a);
}
int main(void)
{
	int x= 100;
	int *p = &x;
	func(p);
	return 0;
}
```

a = p

把p指向的数据传给函数使用 叫传入参数

在函数中对传入的指针指向的数据进行操作 叫传出参数

```
传入参数（Input Parameter）

传入参数一般是将一个变量的值或地址传递给函数，供函数使用。
当传递一个指针（如 p）时，函数可以访问 p 指向的数据，但不会修改调用者的 p 本身，而是读取或使用 p 指向的内容。
传出参数（Output Parameter）

传出参数通常指在函数内部对传入的指针所指向的数据进行修改，以便调用者可以看到这些修改。
当函数接受一个指针参数并对其指向的数据进行更改时，实际上是在对外部变量进行修改。这就叫传出参数，因为结果“输出”到了外部环境。
```

#### 18.时间处理

```c
#include<stdio.h>
#include<time.h>

int main() {
    time_t seconds;
    seconds = time(NULL);//取时间戳
    printf("Current time: %ld \n", seconds);
    
    struct tm *p_time;
    p_time = localtime(&seconds);//时间戳转为本地时间

    printf("Current date: %d-%d-%d \n", 1900 + p_time->tm_year, 1 + p_time->tm_mon, p_time->tm_mday);
    printf("Current time: %d:%d:%d \n", p_time->tm_hour, p_time->tm_min, p_time->tm_sec);
 
    p_time = gmtime(&seconds);
    printf("UTC date: %d-%d-%d \n", 1900 + p_time->tm_year, 1 + p_time->tm_mon, p_time->tm_mday);
    printf("UTC time: %d:%d:%d \n", p_time->tm_hour, p_time->tm_min, p_time->tm_sec);
    
    return 0;
}
```



#### 19.字符串转数字 & 数字转字符串

```c
#include<stdio.h>
#include<stdlib.h>

int main() {

    char *str = NULL;
    int value = 0;
    
    str = "-2002";
    value = atoi(str);
    printf("%d\n", value);
}
```

如果要数字转字符串 用snprintf

```c
#include <stdio.h>

int main() {
    int num = 12345;       // 要转换的数字
    char str[20];          // 用于存储结果字符串，大小足够存放结果和终止符

    // 使用 snprintf 将整数转换为字符串
    snprintf(str, sizeof(str), "%d", num);

    // 输出结果
    printf("The string is: %s\n", str);

    return 0;
}
```



#### 20.用流进行文件读取

字节读入写出

```c
#include <stdio.h>

int main() {
    int c;
    FILE *stream;

    // 打开 1.txt，读取并输出内容
    if ((stream = fopen("1.txt", "a+")) == NULL) {
        perror("Error opening 1.txt");
        return 1;
    }
    printf("File 1.txt opened successfully.\n");

    // 输出文件内容
    while ((c = fgetc(stream)) != EOF) {
        putchar(c);
    }
    puts("");

    fclose(stream);

    // 打开 2.txt，追加用户输入
    if ((stream = fopen("2.txt", "a+")) == NULL) {
        perror("Error opening 2.txt");
        return 1;
    }
    printf("File 2.txt opened successfully.\n");
    printf("Input content, press Ctrl+Z (Windows) or Ctrl+D (Unix) to finish:\n");

    // 写入用户输入内容到文件
    while ((c = getchar()) != EOF) {
        fputc(c, stream);
    }

    fclose(stream);
    return 0;
}
```

字符串读入写出

```c
#include <stdio.h>

int main() {
    char str[4096] = {0};  // 调整缓冲区大小以容纳更多数据
    FILE *stream;

    // 打开 1.txt，读取并打印内容
    if ((stream = fopen("1.txt", "a+")) == NULL) {
        perror("Error opening file 1.txt");
        return 1;
    }
    printf("File 1.txt opened successfully.\n");

    while (fgets(str, sizeof(str), stream) != NULL) {
        fputs(str, stdout);  // 输出文件内容
    }
    puts("");  // 换行

    fclose(stream);

    // 打开 2.txt，追加用户输入
    if ((stream = fopen("2.txt", "a+")) == NULL) {
        perror("Error opening file 2.txt");
        return 1;
    }
    printf("File 2.txt opened successfully.\n");
    printf("Input content, press Ctrl+Z (Windows) or Ctrl+D (Unix) to finish:\n");

    while (fgets(str, sizeof(str), stdin) != NULL) {
        fputs(str, stream);  // 将输入内容写入文件
    }

    fclose(stream);
    return 0;
}
```

**字符串读写是基于行的操作**，每次遇到换行符（或达到缓冲区限制）就完成一次读写，效率更高。

#### 21.自己写strcpy

```c
#include<stdio.h>

void strcpy(char *dest, char *src);


int main() {
    char str1[10] = "Hello";
    char str2[10] = {0};

    strcpy(str2, str1);
    printf("str2: %s\n", str2);


    return 0;
}

void strcpy(char *dest, char *src){

    while (*src!= '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    //这个while可以重写为：
    //while (*dest++ = *src++);
    //一句解决赋值和自加
}
```

重点：

根据 C 语言的运算符优先级：

1. **`++`（后置自增）** 的优先级高于 **`*`（解引用）**。
2. **`*` 和 `=`** 的执行顺序是从右到左（右结合性）。

`*dest++ = *src++` 的执行顺序是：

1. 解引用 `src`，读取当前值。
2. 解引用 `dest`，准备写入。
3. 将 `*src` 的值赋值给 `*dest`。
4. 指针 `src` 和 `dest` 各自自增，移动到下一位置。



#### 22.复制文件的函数

```c
#include<stdio.h>

void file_copy(char *dfile, char *sfile);


int main() {
    char *str1 = "1.txt";
    char *str2 = "2.txt";
    file_copy(str2, str1);
    printf("File copied successfully.\n");

    return 0;
}

void file_copy(char *dfile, char *sfile) {
    FILE *src = fopen(sfile, "r+");
    FILE *dest = fopen(dfile, "w+");
    char ch;

    if (src == NULL) {
        printf("Error opening file %s\n", sfile);
        return;
    }
    if (dest == NULL) {
        printf("Error opening file %s\n", dfile);
        fclose(src);
        return;
    }
    while ((ch = fgetc(src))!= EOF) {
        fputc(ch, dest);
    }
    fclose(src);
    fclose(dest);
    
}
```

重点：

```c
 while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
```



