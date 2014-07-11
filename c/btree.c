#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node{
    int value;
    struct node *left, *right;
};

struct node *addnode(struct node *root, int value){
    if(root == NULL){
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
            else if (value <= seeker->value){
                seeker = seeker->right;
            }
        }
        if (value < current->value){
            current->left = (struct node *)malloc(sizeof(struct node));
            current->left->value = value;
            return current->left;
        }
        else{ 
            current->right = (struct node *)malloc(sizeof(struct node));
            current->right->value = value;
            return current->right;
        }
    }
}

int main(){
    struct node *root = addnode(NULL, 1);
    printf("value of root: %d\n", root->value);
    addnode(root, 2);
    printf("value of first insert: %d\n", root->right->value);
    return 0;
}

