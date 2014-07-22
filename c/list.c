#include <stdlib.h>
#include "list.h"

/* returns pointer to new head */
struct node *ll_prepend(struct node *node, int value){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = node;
    return new_node;
}

/* returns pointer to new tail */
struct node *ll_append(struct node *node, int value){
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->next = node->next;
    node->next = new_node;
    return new_node;
}

void ll_free_node(struct node *node){
    free(node);
}
