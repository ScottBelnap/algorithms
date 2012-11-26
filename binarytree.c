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
    node *trunk = NULL;
    insert(&trunk, 10);
    insert(&trunk, 3);
    insert(&trunk, 2);
    insert(&trunk, 6);
    insert(&trunk, 12);
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

insert(node **head, int key){
    if(*head == NULL){
        (*head) = (node *)malloc(sizeof(node));
        (*head)->data = key;
        (*head)->left = NULL;
        (*head)->right = NULL;
        return;
    }
    if(key > (*head)->data){
        insert(&((*head)->left), key);
    }
    else{
        insert(&((*head)->right), key);
    }

}

