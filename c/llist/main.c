#include <stdio.h>
#include "list.h" /* "" for files in cwd and not in include path */

int main(){
    struct node *head;
    head = NULL;
    head = ll_prepend(head, 1);
    printf("After prepending once, head = %d\n", head->value);
    printf("----------\n");
    head = ll_prepend(head, 3);
    printf("After prepending twice, head = %d\n", head->value);
    printf("----------\n");
    ll_append(head, 2);
    printf("The values in the list are %d, %d, %d\n",
            head->value, head->next->value, head->next->next->value);
    printf("----------\n");
    printf("INSPECT\n");
    inspect_list(head);
    return 0;
}
