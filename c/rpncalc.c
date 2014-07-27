#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "array_stack.h"
/* Reverse Polish Notation Calculator */

void rpncalc_init(struct stack *s){
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

        /* strtol ("string to long") converts as much of the string into
         * a long int until it  hits a non-numeric character or NULL.
         * The remainder is then set to point to that non-num character */

        num = strtol(token, &remainder, 10);
        printf("This is the token: %s\n", token);

        /* this block gets hit at the last strtol iteration, bc the preceding
         * strtok iteration would have returned the "operator + NULL" string,
         * which would be assigned to remainder since operator is non-numeric*/
        if(remainder == token){
            int operand2 = pop(s);
            int operand1 = pop(s);
            int value;
            switch (*token){
                case '+':
                    value = operand1 + operand2;
                    break;
                case '-':
                    value = operand1 - operand2;
                    break;
                case '*':
                    value = operand1 * operand2;
                    break;
                case '/':
                    value = operand1 / operand2;
                    break;
            }
            push(s, value);
            printf("value: %d\n", value);
        }
        else{
            push(s, num);
            printf("Number: %ld\n", num);
        }
        printf("---\n");
        /* strtok will continue to grab bits of the original expression
         * up until the next delimiter, which in this case is a single space.
         * This effectively means that the token will always be a short
         * string that is either number + NULL or operator + NULL */
        token = strtok(NULL, delim);
    }

    return 0;
}

int main(){
    struct stack input;
    struct stack *input_p = &input;
    rpncalc_init(input_p);
    char *expression1 = "1 2 +";
    eval(input_p, expression1);
    char *expression2 = "2 3 *";
    eval(input_p, expression2);
    char *expression3 = "2 3 -";
    eval(input_p, expression3);
    char *expression4 = "6 3 /";
    eval(input_p, expression4);
    char *expression5 = "1 3 + 7 4 - *";
    eval(input_p, expression5);
    return 0;
}
