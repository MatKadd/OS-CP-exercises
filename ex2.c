#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char** argv){
    if (argc == 3) {
        FILE *fp = fopen(argv[2], "a");
        char buf[1];
        while (read(0, buf, sizeof(buf[0])) > 0) {
            fprintf(stdout, "%C", buf[0] );
            fprintf(fp, "%C", buf[0]);
        }
        fclose(fp);
    }
    else if (argc == 2){
        FILE *fp = fopen(argv[1], "w");
        char buf[1];
        while (read(0, buf, sizeof(buf[0])) > 0) {
            fprintf(stdout, "%C", buf[0] );
            fprintf(fp, "%C", buf[0]);
        }
        fclose(fp);
    }
    else{
        printf("\nIncorrect input.\n");
    }
    return 0;
}
