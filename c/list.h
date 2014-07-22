#include <stdlib.h>

/* the ifndef ... endif indicates that the code in between should only be 
 * included once, in the event that this .h file is included in other files.
 * otherwise, the compiler will yell at you because you're telling it to 
 * allocate the same code in two different "places". 
 *
 * NOTE: Ruby's 'require' tracks what files have already been loaded, so 
 * you, dear reader, don't have to worry about such things. */

#ifndef _LIST_H_
#define _LIST_H_

struct node {
    int value;
    struct node *next;
};

/* function prototypes */

void free_node(struct node *node);
struct node *append(struct node *node, int value);
struct node *prepend(struct node *node, int value);

#endif /*_LIST_H_*/
