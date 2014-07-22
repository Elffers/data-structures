#include <stdio.h>
#include "list.h" /* "" for files in cwd and not in include path */

int main(){
    struct node *head;
    head = NULL;
    head = prepend(head, 1);
    printf("The first value after prepending once is %d\n", head->value);
    printf("----------\n");
    head = prepend(head, 2);
    printf("The size of the list after prepending twice is %d\n", head->value);
    return 0;
}
