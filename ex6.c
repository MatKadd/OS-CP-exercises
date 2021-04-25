#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int main(int argc, char** argv) {
    if (argc == 3) {
        FILE *f1 = fopen(argv[1], "r");
        FILE *f2 = fopen(argv[2], "r");
        int n = 4;
        char **list = malloc(n * sizeof(char *));
        int count = 0;
        for (;;) {
            char *line1 = get_line(f1);
            if (line1 == NULL) {
                break;
            }
            if (count == n) {
                n *= 2;
                list = realloc(list, n * sizeof(char *));
            }
            count++;
            list[count-1] = line1;
        }
        for (;;) {
            char *line2 = get_line(f2);
            if (line2 == NULL) {
                break;
            }
            if (count == n) {
                n *= 2;
                list = realloc(list, n * sizeof(char *));
            }
            count++;
            list[count-1] = line2;
        }
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (strcmp(list[i], list[j]) > 0) {
                    char* temp = malloc(sizeof(list[i]));
                    strcpy(temp, list[i]);
                    strcpy(list[i], list[j]);
                    strcpy(list[j], temp);
                    free(temp);
                }
            }
        }
        for (int i = 0; i < count; i++) {
            printf("%s\n", list[i]);
            free(list[i]);
        }
        free(list);
        fclose(f1);
        fclose(f2);
    }
    else {
        printf("\nIncorrect input.\n");
    }
    return 0;
}