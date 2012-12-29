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
    inorder(trunk);
    int c = countNodes(trunk);
    printf("count %d\n", c);
    preorder(trunk);
    printf("\n");
    min(trunk);
    max(trunk);
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
        insert(&((*head)->right), key);
    }
    else{
        insert(&((*head)->left), key);
    }

}

inorder(node *head){
    if(head){
        inorder(head->left);
        printf("%d ", head->data);
        inorder(head->right);
    }
}

preorder(node *head){
    if(head){
        printf("%d ", head->data);
        preorder(head->left);
        preorder(head->right);
    }
}

min(node *head){
    if(head->left == NULL){
        printf("Minimum value: %d\n", head->data);
    }
    else{
        min(head->left);
    }
}

max(node *head){
    if(head->right == NULL){
        printf("Maximum value: %d\n", head->data);
    }
    else{
        max(head->right);
    }
}
