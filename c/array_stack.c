#include <stdio.h>
#include <stdlib.h>
#include "array_stack.h"
/* Stack data structure in C */

/* The *stack indicates that the actual stack being passed 
 * into the function is initialized elsewhere (i.e. in main). 
 * This makes it so that the pop function can only accept a 
 * pointer to a stack struct as its argument */

void init(struct stack *s){
    s->length = 0;
    s->size = CHUNK;
    s->contents = (int *)malloc(sizeof(int) * s->size);
    if (!s->contents) {
        printf("There was not enough memory");
        abort();
    }
}

int pop(struct stack *s){
    /* use -> if s is a pointer. Otherwise, can call variables in a struct with . */
    if (s->length == 0){
        return -1;
    }
    else {
        s->length--;
        return s->contents[s->length];
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

