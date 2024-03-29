/*array to list to array with cnt in array[0]*/

#include <stdlib.h>
#include <stdio.h>

struct list
    {
        int num;
        struct list *next;
    };

// struct list *list_fu(int *cnt, int *arr){
//     struct list  *first = NULL , *last = NULL, *tmp;
//     for (int i=0; i<*cnt; i++){
//         tmp = malloc(sizeof(tmp));
//         tmp->num = arr[i];
//         tmp->next = NULL;
//         if (last){
//             last->next = tmp;
//             last = last->next;
//         }
//         else
//             first = last = tmp;
//     }
//     return first;
// }

struct list *list_fu(int cnt, int *arr){
    struct list *tmp = malloc(sizeof(tmp));
    if (!cnt)
        return NULL;
    tmp->num = *arr;
    tmp->next = list_fu(cnt-1, arr+1);
    return tmp;
}

int *list_to_arr(struct list *list){
    int *array = (int*)malloc(sizeof(int));
    for (int i = 1; list; i++){
        array = (int*)realloc(array, (i+1)*sizeof(int));
        array[i] = list->num;
        array[0] = i;
        list = list->next;
    }
    return array;
}

int main(){
    int arr[] = {1,2,3,45,5,6,7,8}, cnt = 8;
    int *array = list_to_arr(list_fu(cnt, arr));
    for (int i = 0; i<=array[0]; i++){
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}