#include <stdio.h>
#include <stdlib.h>

/* linked list data structure in C */

struct node {
    int value;
    struct node *next;
};

/* struct containing actual linked list */
struct linked_list {
    struct node *head;
    struct node *tail;
    int size;
};

/* calloc used to clear the memory for the types contained in the struct */
/* using calloc instead of malloc also makes it unnecessary to initialize
 * the head pointer, since it will already be pointing to null */

struct linked_list *linked_list_init(){
   struct linked_list *list;
   list = (struct linked_list *)calloc(1, sizeof(struct linked_list));
   return list;
};

int prepend(struct linked_list *list, int value){
    if (list->size == 0){
        list->head = (struct node *)malloc(sizeof(struct node));
        list->head->value = value;
        list->head->next = NULL;
        list->tail = list->head;
    }
    else {
        struct node *node_p = (struct node *)malloc(sizeof(struct node));
        node_p->value = value;
        node_p->next = list->head;
        list->head = node_p;
    }
    list->size++;
    return 0;
}

int append(struct linked_list *list, int value){
    if (list->size == 0){
        list->head = (struct node *)malloc(sizeof(struct node));
        list->head->value = value;
        list->head->next = NULL;
        list->tail = list->head;
    }
    else{
        struct node *node_p = (struct node *)malloc(sizeof(struct node));
        node_p->value = value;
        node_p->next = NULL;
        list->tail->next = node_p;
        list->tail = node_p;
    }
    list->size++;
    return 0;
}
/* this requires an arbirary int size to be declared first, such that 
 * the pointer to that integer can be passed in as an argument to 
 * the contents_p function */

int *contents_p(struct linked_list *list, int *size_p){
    *size_p = list->size;
    int *output = (int *)malloc(sizeof(int)*list->size);
    struct node *current;
    int i;
    i = 0;
    current = list->head;
    while(current){
        output[i] = current->value;
        i++;
        current=current->next;
    }
    return output;
}

void inspect(struct linked_list *list){
    int size;
    int *contents = contents_p(list, &size);
    int i;
    i = 0;
    printf("[");
    while(i < size){
        if (i == size-1){
            printf("%d",contents[i]);
        }
        else{
            printf("%d,",contents[i]);
        }
        i++;
    }
    printf("]\n");
}

int main(){
    struct linked_list *list;
    list = linked_list_init();
    printf("The size of the empty list is %d\n", list->size);
    inspect(list);
    printf("----------\n");
    prepend(list, 1);
    printf("The first value after prepending once to the list is %d\n", list->head->value);
    printf("The  value of the list's tail is %d\n", list->tail->value);
    printf("The size of the list is %d\n", list->size);
    inspect(list);
    printf("----------\n");
    prepend(list, 2);
    printf("The  value of the list's head is %d\n", list->head->value);
    printf("The size of the list after prepending twice is %d\n", list->size);
    inspect(list);
    printf("----------\n");
    append(list, -1);
    printf("The  value of the list's tail is %d\n", list->tail->value);
    printf("The size of the list is %d\n", list->size);
    inspect(list);
    printf("----------\n");
    append(list, -2);
    printf("The  value of the list's tail is %d\n", list->tail->value);
    printf("The size of the list is %d\n", list->size);
    inspect(list);
    printf("----------\n");
}
