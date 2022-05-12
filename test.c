#include <stdlib.h>
#include <stdio.h>

int *arr_fu(){
    int *arr = (int*)malloc(sizeof(int));
    *arr = 0;
    return arr;
}

int main(){
    int *point = (int*)malloc(sizeof(int));
    for (int i = 2; i<10; i++){
        point = (int*)realloc(point, i*sizeof(int));
        point[i] = 0;
        printf("%d ", point[i]);
    }
    printf("\n");
    for (int j = 0; j<10; j++){
        printf("%d ", *(point+j));
    }
    return 0;
}