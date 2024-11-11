# Note for Sep.

1.sizeof包含最后的'\0' strlen不包含

2.atoi atof 注意输入的字符串需要时十进制数字 正负号 或是以空格开头的十进制数 不能是字母或是其他字符

3.使用strcpy或者strncpy的时候 记得在后面手动添加终止符 这样才能安全的复制 不会缓冲区溢出（Buffer Overflow）

```c
    // 使用 sizeof - 1，确保不会溢出目标缓冲区
    size_t max_length = sizeof(destination) - 1;
    strncpy(destination, source, max_length);
    destination[max_length] = '\0';  // 手动添加终止符
    printf("Destination (small): %s\n", destination);
```

也可以这么写

```
strncpy(string, string2, strlen(string2));
strncat((string, string2, strlen(string2));)
```

3.strcmp依次比较两个字符串的ascii码; strncmp依次比较两个字符串的前n个字符

4.查找字符串需要这样使用

```c
    char *pdest;
    pdest = strstr(string3, string2);
    if (pdest!= NULL) {
        printf("String1 found at position: %ld\n", pdest - string3);
    } else {
        printf("String1 not found in string2.\n");
    }
```

5.写入和读出字符串

```
 ret = sprintf(buffer, "hello world");
 ret = sscanf(buffer, "%s", input);
```

buffer相当于就是屏幕和键盘

sprintf把hello world打印到buffer

然后sscanf是把buffer中的第一个字符串给到input

```
 ret = sprintf(buffer, "input: hello world");
 ret = sscanf(buffer, "input: %s", input);
```

sprintf的ret返回的是写入buffer了多少个字符 打印buffer的话是打印出来input: hello world

sscanf的ret返回的是成功地根据格式字符串匹配并提取的字段数，如果用 `sscanf` 读取了一个整数和一个字符串，并且这两个值都被正确解析并存储，那么返回值将是 `2`。如果解析到一个就是1 如果没解析到就是0.

input打印出来是hello

而且必须格式一样才能解析得到 也就是说buffer里面🉐有一个inputs： 不然解析不到

当然也可以不要加任何限定 input就是buffer里的第一个字符串

```
ret = sscanf(buffer, "%s", input);
```

也就是说sscanf就是把buffer里面的值读到变量中

6.c语言中表示流的数据结构的类型被称为**文件指针（FILE  *）** 

7.文件的打开关闭

```
int main(){
    FILE *stream1 = NULL;
    FILE *stream2 = NULL;

    stream1 = fopen("1.txt", "a+");
    if(stream1 == NULL)
    {
        printf("Error opening file 1.txt\n");
        return 1;
    }else {
        printf("File 1.txt opened successfully.\n");
    }

    if(fclose(stream1) == EOF) {
        printf("Error closing file 1.txt\n");
        return 1;

    } 
    return 0;
}
```

"a+"：打开或创建文本文件用于读和追加写操作。

8.从流（文件指针）中 读字节fgetc  和 写字节fputc到流（文件指针）中

读取整个文档内容 打印到屏幕

```c
    int c;
	while((c = fgetc(stream1))!= EOF) {
        putchar(c);
    }
```

写入内容到文档

```c
    printf("input content, press ctrl+z to exit:\n");
    while((c=getchar()) != EOF){
        fputc(c, stream2);
    }
```

注意 ubuntu的ctrl+z由ctrl+d替代

9.从流（文件指针）中 读字符串 和 写入字符串到流（文件指针）中

读

```c
    while((fgets(str, sizeof(str), stream1) != NULL) {
        printf("%s", str);
    }
```

先读（从标准输入读 也就是键盘输入）存到一个字符数组中 然后写入流

```c
    printf("input content, press ctrl+z to exit:\n");
    while((fgets(str, sizeof(str), stdin)!=NULL){
        fputs(str, stream2);
    }
```

区别不大 只是用字符和字符串 都可以用 一个处理单个字符，另一个处理字符串

9.写字符串到屏幕（相当于fgets(str, stdout)）

```C
    while(fgets(str, sizeof(str), stdin)!=NULL){
        puts(str);
    }
```

输入啥就输出啥

10.格式化写入到流中fprintf

```c
    ret = fprintf(stream1, "\n%d-%d-%d\n", year, month, day);
    if(ret > 0)
    {
        printf("Data written to file 1.txt successfully.\n");
    }
    else {
        printf("Error writing to file 1.txt\n");
        return 1;
    }
```

把流中的数据读出来 注意格式一定要一致 不然怎么叫格式化读 fscanf

```c
    ret = fscanf(stream2, "%d.%d.%d", &a, &b, &c);
    if(ret > 0){
        printf("Data read from file 2.txt successfully: %d-%d-%d\n", a, b, c);
    }
    else {
        printf("Error reading from file 2.txt\n");
        return 1;
    }
```

2.txt的内容只有是这样 才能把a, b, c读出来

```
1996.5.30
```

如果文件中有多个匹配项：

- `fscanf` 只会读取**第一个**与格式匹配的项，然后返回。
- 文件指针会移动到匹配项之后的第一个字符位置，这意味着，如果再调用 `fscanf`，它会从上一次读取结束的地方继续向后查找。

11.输入26个字母到字符数组

```c
    for(i=0; i<26; i++) {
        list[i] = 'a'+ i;
    }
```

12.按字节读和按字节写

把字符数组list里的26个char写到stream1中

```c
    int numwrite = fwrite(list, sizeof(char), 26, stream1);
    printf("write %d\n", numwrite);
```

从streaml2中读26个char到list字符数组中

```c
    int numread = fread(list, sizeof(char), 26, stream2);
    printf("read %d\n", numread);
    printf("content:%s\n", list);
```

13.自己写一个strcpy

```c
void strcpy1(char *str1, char *str2)
{
    while(*str2!= '\0'){
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';  // append null terminator to the copied string
}
```

14.从一个流传入另一个流（复制文件）

```c
    int c
    while((c = fgetc(stream1))!= EOF)
    {
        fputc(c, stream2);
    }
```

每次调用 `fgetc()` 后，文件流的内部文件指针会自动向前移动一个位置，这就是为什么在循环中每次调用 `fgetc()` 都能读取到下一个字符的原因。

因此，通过重复调用 `fgetc()`，代码能够顺序读取文件中的每一个字符，直到文件结束。

15.统计流指向文件的的行数

```c
    while((c = fgetc(stream1))!= EOF)
    {
        if(c == '\n')
            n++;
    }
```

16.取时间戳和local time

```c
#include<time.h>
	time_t seconds;
    seconds = time(NULL);
    struct tm *p_time;
    p_time = localtime(&seconds);
	printf("Current date: %d-%d-%d \n", 1900 + p_time->tm_year, 1 + p_time->tm_mon, p_time->tm_mday);
    printf("Current time: %d:%d:%d \n", p_time->tm_hour, p_time->tm_min, p_time->tm_sec);
```

17.window上查看文件<io.h>

通过文件返回句柄和文件信息结构体

通过句柄查看下一个文件的文件信息结构体

关闭句柄

```c
    struct _finddata_t c_file;
    intptr_t hFile;
    int i= 0;
    if((hFile = _findfirst("test\\*", &c_file)) == -1);
    {
        printf("_findfirst error\n");
        return -1;
    }
    do {


    } while(_findnext(hFile, &c_file) == 0);

    _findclose(hFile);
```

循环的地方可以用于判断文件属性 文件名字 文件大小 创建和写入时间

```c
        printf("%d.name: %s\n", i++, c_file.name);

        printf("readonly file: %s\n", (c_file.attrib & _A_RDONLY) ? "Yes" : "No");
        printf("hidden file: %s\n", (c_file.attrib & _A_HIDDEN) ? "Yes" : "No");
        printf("system file: %s\n", (c_file.attrib & _A_SYSTEM) ? "Yes" : "No");
        printf("directory file: %s\n", (c_file.attrib & _A_SUBDIR) ? "Yes" : "No");
        printf("size of file: %d\n", c_file.size);

        struct tm *p_time;
        
        p_time = localtime(&c_file.time_create);
        printf("creat time: %d-%d-%d %d:%d:%d\n", 
            1900+p_time->tm_year, 1+p_time->tm_mon, p_time->tm_mday, p_time->tm_hour, p_time->tm_min, p_time->tm_sec);

        p_time = localtime(&c_file.time_write);
        printf("last write time: %d-%d-%d %d:%d:%d\n", 
            1900+p_time->tm_year, 1+p_time->tm_mon, p_time->tm_mday, p_time->tm_hour, p_time->tm_min, p_time->tm_sec);

        printf("-----------------------------------------------------\n");
```









1.指针指向的内容不可修改

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

2.指针指向数组做遍历

```c
int score[] = {2, 3, 4, 5};
int *p = NULL;
for(p = score; p < score+4; p++)
{
	printf("%d:%d\n", i++, *p);
}
```

3.数组作为函数参数

```
void calc_scores(int scores[]， int scores_length);
void calc_scores(int scores[5]， int scores_length);
void calc_scores(int *scores)， int scores_length;
```

这三种写法是等价的， 通常都会带上数组长度

4.用指针指向字符串

```c
char *str = "hello world";
```

用数组下标或是取值运算符都是可以的

但不能对字符串进行修改 因为字符串是只读的常量

```c
const char *str = "hello world";
```

为避免意外修改字符串 导致crash 用const修饰

5.字符串常量和字符串变量

```
char *str = "hello world";
char str[] = "hello world";
```

`char *str = "hello world";`：指针可以指向其他字符串，但内容不可变。

`char str[] = "hello world";`：数组内容可修改，但数组本身不可指向其他字符串。

6.通过指针计算字符串大小

因为字符串最后一位是`\0`

```c
char hi[]= "hello world";
char *p = NULL;
for(p = hi;*p !='\0';p++);
printf("字符串hi的长度是:%d\n"，p-hi);
```

7.指针作为传入参数

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

8.





