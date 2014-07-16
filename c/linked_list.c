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

int append(struct linked_list *list, int value){
    if (list->size == 0){
        list->head = (struct node *)malloc(sizeof(struct node));
        list->head->value = value;
        list->head->next = NULL;
        list->tail = list->head;
        return 0;
    }
    return 0;
}

int main(){
    struct linked_list *list;
    list = linked_list_init();
    printf("The size of the list is %d\n", list->size);
    append(list, 1);
    printf("The first value of the list is %d\n", list->head->value);
    printf("The  value of the list's tail is %d\n", list->tail->value);
}
