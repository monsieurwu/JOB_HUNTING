#include<stdio.h>


int main(){
    
    char str[4090] = {0};
   
    FILE *stream2 = NULL;



    stream2 = fopen("2.txt", "a+");
    if(stream2 == NULL)
    {
        printf("Error opening file 2.txt\n");
        return 1;
    }else {
        printf("File 2.txt opened successfully.\n");
    }

    printf("input content, press ctrl+z to exit:\n");
    
    while(fgets(str, sizeof(str), stdin)!=NULL){
        puts(str);
    }



    if(fclose(stream2) == EOF) {
        printf("Error closing file 2.txt\n");
        return 1;

    } 
    return 0;
}