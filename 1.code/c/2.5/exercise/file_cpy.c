#include<stdio.h>

int file_copy(char *dfile, char *sfile);
int main(){
    int ret;
    char *str1 = "1.txt";
    char *str2 = "2.txt";

    ret = file_copy(str2, str1);
    if(ret>0)
    {
        printf("File copied successfully\n");
    }
    else {
        printf("Error in copying file\n");
    }
    
    return 0;
}

int file_copy(char *dfile, char *sfile)
{
    int c;
    FILE *stream1 = NULL;
    FILE *stream2 = NULL;
    stream1 = fopen(sfile, "a+");
    stream2 = fopen(dfile, "a+");
    if(stream1 == NULL)
    {
        printf("Error opening file sfile\n");
        return -1;
    }else {
        printf("File sfile opened successfully.\n");
    }
    if(stream2 == NULL)
    {
        printf("Error opening file dfile\n");
        return -1;
    }else {
        printf("File dfile opened successfully.\n");
    }

    while((c = fgetc(stream1))!= EOF)
    {
        fputc(c, stream2);
    }







    if(fclose(stream1) == EOF) {
        printf("Error closing file sfile\n");
        return -1;
    } 
    if(fclose(stream2) == EOF) {
        printf("Error closing file dfile\n");
        return -1;

    } 

    


    return 1;

    
    
    /*
    FILE *source, *destination;
    char ch;

    source = fopen(sfile, "r");
    if(source == NULL)
    {
        printf("Error opening file %s\n", sfile);
        return -1;
    }

    destination = fopen(dfile, "w");
    if(destination == NULL)
    {
        printf("Error opening file %s\n", dfile);
        fclose(source);
        return -1;
    }

    while((ch = fgetc(source))!= EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);
    return 0;
    */

}
