#include <stdio.h>

int main (int argc, char** argv){
    char* buf;
    for (int i = 0; argv[i]; i++){
        buf = argv[i];
        if (*buf!='-'){
            printf("%s\n", argv[i]);
        }
    }
    return 0;
}
