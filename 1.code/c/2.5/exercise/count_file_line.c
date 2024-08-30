#include<stdio.h>

int count_file_line(const char *path);
int main(){
    int line_num; 
    const char *p = "1.txt";
    line_num = count_file_line(p);
    printf("Number of lines in the file %s: %d\n", p, line_num);  // Output: Number of lines in the file 1.txt: 3
    
    return 0;
}

int count_file_line(const char *path)
{
    int c, n = 0;  // Initialize count and line number variables
    FILE *stream1 = NULL;
    stream1 = fopen(path, "a+");
    if(stream1 == NULL)
    {
        printf("Error opening file path\n");
        return -1;
    }else {
        printf("File path opened successfully.\n");
    }

    while((c = fgetc(stream1))!= EOF)
    {
        if(c == '\n')
            n++;
    }

    if(fclose(stream1) == EOF) {
        printf("Error closing file path\n");
        return -1;
    } 
    return n;  // Return the total number of lines in the file.

}

/*
 
*/
   
