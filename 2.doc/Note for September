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

