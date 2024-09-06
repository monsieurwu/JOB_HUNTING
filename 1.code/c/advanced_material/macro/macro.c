#include <stdio.h>
#define VERSION "1.0.0"
void print_version_info(void)
{
    printf("Software Version: %s\n", VERSION);
    printf("Compiled on: %s %s\n", __DATE__, __TIME__);

}
void exampleFunction()
{
    printf("function name: %s\n", __func__);
}

int main() {
    print_version_info();
    printf("Current file: %s\n", __FILE__);
    printf("Line number: %d\n", __LINE__);
    exampleFunction();

    return 0;
}