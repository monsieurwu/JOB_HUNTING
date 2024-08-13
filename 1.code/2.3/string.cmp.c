#include<stdio.h>
#define SIZE 100
int string_cmp(char* s1, char* s2);
int main() {
    char arr1[SIZE] = "hello";
    char arr2[SIZE] = "world";
    int result;
    result = string_cmp(arr1, arr2);
    if(result == 0) {
        printf("equal\n");

    }
    else if(result == 0) {
        printf("arr1 is bigger than arr2\n");

    }
    else {
        printf("arr1 is smaller than arr2\n");

    }
    return 0;
    


}

int string_cmp(char* s1, char* s2){
 
    while(*s1 == *s2) {
        if(*s1 == '\0')
            return 0;
        s1++;
        s2++;
      
    }

    return *s1-*s2;
   

}
