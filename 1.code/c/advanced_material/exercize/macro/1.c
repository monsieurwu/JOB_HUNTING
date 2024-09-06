#include <stdio.h>

#define A(x) ((x)*(x))
#define B(n) ((n)%4)
#define C(a, b) ((a)*(b)<100? 1:0)

int main(int argc, char *argv[]) {
    int x = 4;
    printf("The square of %d is %d\n", x, A(x));
    int y = 2014;
    printf("The remainder when %d is divided by 4 is %d\n", y, B(y));
    int z= 0;
    z = C(x, x);
    printf("The result of C(%d, %d) is %d\n", x, y, z);

    return 0;
}