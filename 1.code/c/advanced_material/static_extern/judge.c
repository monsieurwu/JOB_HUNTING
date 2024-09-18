#include<stdio.h>
void check_end(void)
{
    int a = 0x12345678;
    char *p = (char *)&a;

    if(*p == 0x78) {
        printf("little end\n");
    }else if(*p == 0x12){
        printf("big end\n");
    }


}
int main() {
    check_end();
    return 0;
}