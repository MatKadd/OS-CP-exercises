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

int main(int argc, char** argv){
    if (argc == 3){
        char* start = argv[1];
        int len = strlen(start);
        FILE *fp = fopen(argv[2], "r");
        for(;;) {
            char *temp = get_line(fp);
            if (temp == NULL) {
       	break;
            }
            int check = 0;
            for (int i = 0; i < len; i++) {
                if (temp[i] != start[i]) {
                    check = 1;
                    break;
                }
            }
            if (check == 0){
                printf("%s\n", temp);
            }
            free(temp);
        }
        fclose(fp);
    }
    else {
        printf("\nIncorrect input.\n");
    }

    return 0;
}
