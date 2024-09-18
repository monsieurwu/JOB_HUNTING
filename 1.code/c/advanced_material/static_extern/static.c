#include<stdio.h>
void fun(void)
{
    static int count = 0;
    count++;
    count =1;
    printf("count = %d\n", count);


}
int main() {
    fun();
    fun();
    return 0;
}