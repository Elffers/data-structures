#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Binary Search Tree */

struct node{
    int value;
    struct node *left, *right;
};

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
            current->left = (struct node *)calloc(1, sizeof(struct node));
            current->left->value = value;
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

int main(){
    struct node *root = addnode(NULL, 5);
    printf("Expected value of root: 5\n");
    printf("value of root: %d\n", root->value);
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
    return 0;
}

