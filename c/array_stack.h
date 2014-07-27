#include <stdlib.h>
#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_
#define CHUNK 10

/* initialize stack of fixed size 10 */
/* having a length variable keeps track of times pushed/popped */
struct stack{
    int *contents;
    int length;
    int size;
};

/* function prototypes */
void init(struct stack *s);
int pop(struct stack *s);
int push(struct stack *s, int element);
void done(struct stack *s);

#endif /*_ARRAY_STACK_H_ */
