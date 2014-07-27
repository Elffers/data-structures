#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "array_stack.h"
/* Reverse Polish Notation Calculator */

void init(struct stack *s){
    s->length = 0;
    s->size = CHUNK;
    s->contents = (int *)malloc(sizeof(int) *s->size);
    if (!s->contents) {
        printf("There was not enough memory!");
        abort();
    }
}

int eval(struct stack *s, char *expression){
    const char delim[] = " ";
    char *token, *expr;

    if (!(expr = (char *)malloc(strlen(expression))))
        abort();

    /* for some reason, this was necessary to avoid a bus error */
    strcpy(expr, expression);

    /* get the first token */
    token = strtok(expr, delim);

    while(token != NULL){
        char *remainder;
        long num;
        num = strtol(token, &remainder, 10);
        printf("This is the token: %s\n", token);
        printf("Number: %ld\n", num);
        if(remainder == token){
            printf("This is an operator: %s\n", token);
        }
        printf("remaining input:  %s\n", remainder);
        printf("---\n");
        token = strtok(NULL, delim);
    }

    return 0;
}

int main(){
    struct stack input;
    struct stack *input_p = &input;
    init(input_p);
    char *expression = "1 2 +";
    eval(input_p, expression);
    return 0;
}
