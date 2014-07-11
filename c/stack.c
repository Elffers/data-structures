#include <stdio.h>
#include <stdlib.h>
#define CHUNK 10
/* Stack data structure in C */

/* initialize stack of fixed size 10 */
/* having a length variable keeps track of times pushed/popped */
struct stack{
    int *contents;
    int length;
    int size;
};

/* The *stack indicates that the actual stack being passed 
 * into the function is initialized elsewhere (i.e. in main). 
 * This makes it so that the pop function can only accept a 
 * pointer to a stack struct as its argument */

int pop(struct stack *s){
    /* use -> if stack is a pointer. Otherwise, can call variables in a struct with . */
    if (s->length == 0){
        return -1;
    }
    else {
        s->length--;
        return s->contents[s->length];
    }
}
void init(struct stack *s){
    s->length = 0;
    s->size = CHUNK;
    s->contents = (int *)malloc(sizeof(int) * s->size);
    if (!s->contents) {
        printf("There was not enough memory");
        abort();
    }
}

int push(struct stack *s, int element){
    if (s->length == s->size){
        int *tmp;
        s->size += CHUNK;
        /* what happens if realloc fails?? WHAT DO HERE */
        tmp = (int*)realloc(s->contents, sizeof(int)* s->size);
        if (!tmp)
        {
            printf("There was not enough memory");
        }
        else
        {
            s->contents = tmp;
        }
    }
    s->contents[s->length] = element;
    s->length++;
    return 0;
}

void done(struct stack *s){
    free(s->contents);
}

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
