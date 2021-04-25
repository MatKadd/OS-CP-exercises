#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv){
    if (argc == 3){
        FILE* fp1 = fopen(argv[1], "r");
        FILE* fp2 = fopen(argv[2], "r");
        int read1, read2;
        while (1){
            read1 = fgetc(fp1);
            read2 = fgetc(fp2);
            printf("%C %C\n", read1, read2);
            if (read1 == EOF && read2 == EOF)
                break;
            if (read1 != read2){
                printf("\nFiles are different.\n");
                fclose(fp1);
                fclose(fp2);
                return 0;
            }
        }
        printf(("\nFiles are identical.\n"));
        fclose(fp1);
        fclose(fp2);
    }
    else {
        printf("\nIncorrect input.\n");
    }
    return 0;
}
