#include <stdio.h>



int main(){
    char hi[]= "hello world";
    char *p = NULL;
    for(p = hi;*p !='\0';p++);
    printf("字符串hi的长度是:%d\n", p-hi);
	return 0;
}


