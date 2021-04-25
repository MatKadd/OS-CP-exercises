#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// sorry for the messy code, didn't want to start over after doing it for some time, and made it work somehow
// it is a code from project from different subject, it returns one line of file, no matter the length of it
char *get_line(FILE* ptr, int *count1, int *count2){
    int n = 8, i = 0;
    int countw = 0, countc = 0;
    char *line = (char *)malloc(n*sizeof(char));
    char read;
    while((read = fgetc(ptr)) != '\n'){
    	countc++;
        if(read == EOF){
            free(line);
            return NULL;
        }
        if(i >= n - 2){
            n *= 2;
            line =  realloc(line, n * sizeof(char));
        }
        if ((read == ' ') && (isalnum(line[i-1]))){
            countw++;
        }
        line[i] = read;
        i++;
    }
    countc++;
    if (isalnum(line[i-1])) {
        countw++;
    }
    line[i] = '\0';
    *count1 = *count1 + countc;
    *count2 = *count2 + countw ;
    return line;
}
int main (int argc, char** argv){
    if (argc == 2){
        FILE* fp = fopen(argv[1], "r");
        int c_count = 0;
        int w_count = 0;
        int l_count = 0;
        int *p1 = &c_count;
        int *p2 = &w_count;
        for(;;){
            char *temp = get_line(fp, p1, p2);
            if(temp == NULL){
                break;
            }
            free(temp);
            l_count++;
        }
        printf("\nNumber of characters: %d\nNumber of words: %d\nNumber of lines: %d\n", *p1, *p2, l_count);
        fclose(fp);
    }
    else{
        printf("\nIncorrect input\n");
    }
    return 0;
}
