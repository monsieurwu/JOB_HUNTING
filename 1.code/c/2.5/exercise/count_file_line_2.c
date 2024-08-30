#include <stdio.h>
int count_file_line(const char *path);
int main() {
    int count = 0;
    
    count = count_file_line("data.txt");

    printf("%d lines in total\n", count);
    return 0;
}

int count_file_line(const char *path)
{
    int n = 0;
    char c, prev_char;

    FILE *stream = NULL;

    if((stream =fopen(path, "a+")) == NULL)
    {
        printf("error in open\n");
        return -1;
    } else
    {
        printf("open succesed\n");
    }

    while((c = fgetc(stream)) != EOF)
    {
        if(c == '\n')
            n++;
        prev_char = c;
    }
    if (prev_char != '\n' && prev_char != '\0') 
    {
        n++;
    }

    if(fclose(stream) == EOF)
    {
        printf("close error\n");
    }
    return n;

}