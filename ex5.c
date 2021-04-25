#include <stdio.h>
#include <stdlib.h>


char *get_line(FILE* ptr){
    int n = 8, i = 0;
    char *line = (char *)malloc(n*sizeof(char)), read;
    while((read = fgetc(ptr)) != '\n'){
        if(read == EOF){
            free(line);
            return NULL;
        }
        if(i >= n - 2){
            n *= 2;
            line =  realloc(line, n * sizeof(char));
        }
        line[i] = read;
        i++;
    }
    line[i] = '\0';

    return line;
}

int main(int argc, char** argv){
    if (argc==2){
        FILE* fp = fopen(argv[1], "r");
        int n = 4;
        int count = 0;
        char** list = malloc(n*sizeof(char*));
        for(int i = 0;; i++) {
            char *temp = get_line(fp);
            if (temp == NULL) {
                break;
            }
            if (i == n) {
                n *= 2;
                list = realloc(list, n*sizeof(char*));
            }
            list[i] = temp;
            count = i;
        }
        for (int i = count; i >= 0 ; i--){
            printf("%s\n", list[i]);
            free(list[i]);
        }
        free(list);
        fclose(fp);
    }
    else {
        printf("\nIncorrect input.\n");
    }
    return 0;
}
