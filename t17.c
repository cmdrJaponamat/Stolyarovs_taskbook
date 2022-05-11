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
    struct list *tmp;
    if (!cnt)
        return NULL; 
    tmp = malloc(sizeof(tmp));
    tmp->num = *arr;
    tmp->next = list_fu(cnt-1, arr+1);
    return tmp;
}

int *list_to_arr(struct list *list){
    struct list *temp;
    temp = list;
    int cnt = 0;
    while (temp){
        cnt++;
        temp = temp->next;
    }
    temp = list;
    int *array = (int*)malloc((cnt+1)*sizeof(int));
    array[0] = cnt;
    for (int i = 1; i<=cnt; i++){
        array[i] = temp->num;
        temp = temp->next;
        printf("%d ", array[i]);
    }
    return array;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8}, cnt = 8;
    int *array = list_to_arr(list_fu(cnt, arr));
    printf("\n");
    for (int i = 0; i<=array[0]; i++){
        printf("%d ", array[i]);
    }
    return 0;
}