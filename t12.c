#include <stdio.h>

char *occurrences(char *first_arg, char *second_arg){
    int first_arg_length = 0;
    do{
        if (*second_arg == *first_arg){
            while(*first_arg++){
                first_arg_length++;
                second_arg++;
                if (*second_arg == *first_arg){
                    if (!*first_arg+1){
                        return second_arg-first_arg_length;
                    }
                }
                else break;
            }
        }
    } while (*++second_arg);
    return NULL;
}

int main(int argc, char **argv){
    char *first_arg = *(argv + 1), *buf;
    int occurences = 1;
    argv = argv+1;
    while (*++argv){
        if (occurrences(first_arg, *argv)){
            buf = occurrences(first_arg, *argv);
            while (occurrences(first_arg, buf+1)){
                occurences++;
                buf=occurrences(first_arg, buf+1);
            }
            printf("%s, %d\n", *argv, occurences);
        }
        occurences = 1;
    }
    return 0;
}