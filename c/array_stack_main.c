#include <stdio.h>
#include "array_stack.h"

/* test file for array-based stack */

int main(){
    struct stack numbers;
    struct stack *numbers_p = &numbers;

    init(numbers_p);

    printf("pop on empty stack: %d\n", pop(numbers_p));
    push(numbers_p, 2);
    printf("pop on stack with one element: %d\n", pop(numbers_p));
    push(numbers_p, 1);
    push(numbers_p, 2);
    printf("size: %d, length: %d\n", numbers_p->size, numbers_p->length);
    push(numbers_p, 3);
    printf("size: %d, length: %d\n", numbers_p->size, numbers_p->length);
    push(numbers_p, 4);
    push(numbers_p, 5);
    push(numbers_p, 6);
    push(numbers_p, 7);
    push(numbers_p, 8);
    push(numbers_p, 9);
    push(numbers_p, 10);
    done(numbers_p);
    return 0;
}
