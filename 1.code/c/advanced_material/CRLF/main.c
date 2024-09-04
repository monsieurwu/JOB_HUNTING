#include <stdio.h>
#include <unistd.h>
int main() {
    int i = 0;
    while(1) {
        printf("print in %d times\r", i++);
        fflush(stdout);
        sleep(1);
    
    }

    return 0;
}