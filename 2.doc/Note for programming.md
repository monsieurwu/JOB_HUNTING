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

#### 

