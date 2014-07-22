#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Binary Search Tree */

struct node{
    int value;
    struct node *left, *right;
};
/* To avoid memory leak of the pointer to root, either 
always return the root or have separate init function to deal
with setting the root*/
struct node *addnode(struct node *root, int value){
    if(root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        /* lazy way of catching malloc failure */
        assert(root);
        root->value = value;
        root->left = root->right = NULL;
        return root;
    }
    else {
        struct node *seeker, *current;
        seeker = current = root;
        while(seeker){
            current = seeker;
            if (value < seeker->value){
                seeker = seeker->left;
            }
            else if (value >= seeker->value){
                seeker = seeker->right;
            }
        }
        if(value < current->value) {
            current->left = (struct node *)malloc(sizeof(struct node));
            /* can also move current to the current->left for readability */
            current->left->value = value;
            current->left->left = current->left->right = NULL;
            return current->left;
        }
        else { 
            current->right = (struct node *)calloc(1, sizeof(struct node));
            current->right->value = value;
            return current->right;
        }
    }
}

/* have recursive way to free all the mallocs */
/* can also use this same method in postorder traversal, replacing
free with print */

void freetree(struct node *root){
    if(root == NULL){
        return;
    }
    freetree(root->left);
    freetree(root->right);
    free(root);
}

void postorder(struct node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\n",root->value);
}
int main(){
    struct node *root = addnode(NULL, 5);
    printf("Expected value of root: 5\n");
    printf("value of root: %d\n", root->value);
    /* can cast the return value of addnode to void, ie
    (void) addnode(root, 7) to avoid memory leak */
    addnode(root, 7);
    printf("Expected value of insert: 7\n");
    printf("value of first insert: %d\n", root->right->value);
    addnode(root, 3);
    printf("Expected value of insert: 3\n");
    printf("value of 2nd insert: %d\n", root->left->value);
    addnode(root, 1);
    printf("Expected value of insert: 1\n");
    printf("value of 3rd insert: %d\n", root->left->left->value);
    addnode(root, 2);
    printf("Expected value of insert: 2\n");
    printf("value of insert: %d\n", root->left->left->right->value);
    addnode(root, 2);
    printf("Expected value of insert: 2\n");
    printf("value of insert: %d\n", root->left->left->right->right->value);
    addnode(root, 1);
    printf("Expected value of insert: 1\n");
    printf("value of insert: %d\n", root->left->left->right->left->value);
    postorder(root);
    freetree(root);
    return 0;
}

