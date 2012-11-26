#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
    struct node *right;
};

typedef struct node node;

int main()
{
    node *trunk = (node *)malloc(sizeof(node));
    node *left = (node *)malloc(sizeof(node));
    node *right = (node *)malloc(sizeof(node));
    trunk->data = 1;
    trunk->right = NULL;
    left->data = 2;
    left->left = NULL;
    left->right = NULL;
    right->data = 3;
    right->left = NULL;
    right->right = NULL;
    trunk->left = left;
    trunk->right = right;
    int c = countNodes(trunk);
    printf("count %d\n", c);
}

int countNodes(node *trunk){
    node *temp = trunk;
    if(trunk != NULL){
        return countNodes(temp->left) + 1 + countNodes(temp->right);
    }
    else{
        return 0;
    }
}
