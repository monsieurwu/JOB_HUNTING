#include <stdarg.h>
#include <stdio.h>
void my_print(const char *format, ...)
{
	char ch;
	va_list arg;
	va_start(arg,format);
	while (ch = *format++) {
        if(ch == '%') {
            ch = *format++;
        } else {
            putchar(ch);
            continue;
        }
        switch(ch) {
            case 'd':
                printf("%d", va_arg(arg, int));
                break;
            case 'f':
                printf("%f", va_arg(arg, double));
                break;
            case's':
                printf("%s", va_arg(arg, char*));
                break;
            case 'c':
                putchar(va_arg(arg, int));
                break;
            default:
                putchar(ch);
                break;
        }
    }
    


	va_end(arg);
}
int main(){
	my_print("hello %s\n%d\n", "wolrd", 886);
	return 0;
}
