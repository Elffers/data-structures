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
/* there is no namespacing in C! so you have to add silly prefixes
 * to make sure your program doesn't blow up if someone else has a 
 * function with the same name as yours. At least if you want them to 
 * include your file as a library */

void ll_free_node(struct node *node);
struct node *ll_append(struct node *node, int value);
struct node *ll_prepend(struct node *node, int value);

#endif /*_LIST_H_*/
