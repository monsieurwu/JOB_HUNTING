#include <stdarg.h>
#include <stdio.h>
void print_numbers(int count, ...)
{
	int i, value;
	va_list args;
	va_start(args,count);
	printf("参数%d个:", count);
	for(i =0;i< count;i++){
		value = va_arg(args,int);
		printf("%d ", value);
    }
		printf("\n");
		va_end(args);
}
int main(){
	print_numbers(2,3,5);
	print_numbers(4,3,5,7,9);
	return 0;
}
