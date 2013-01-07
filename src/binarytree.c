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
    insertInTree(&trunk, 10);
    insertInTree(&trunk, 3);
    insertInTree(&trunk, 2);
    insertInTree(&trunk, 6);
    insertInTree(&trunk, 12);
    insertInTree(&trunk, 1);
    inorder(trunk);
    int c = countNodes(trunk);
    printf("count %d\n", c);
    preorder(trunk);
    printf("\n");
    min(trunk);
    max(trunk);
    search(trunk, 6);
    int d = maxDepth(trunk);
    printf("Max Depth %d\n", d);
	int path[30];
	printAllPaths(trunk, path, 0);
	int same = compareTrees(trunk, trunk);
	if(same){
		printf("Trees are the same\n");
	}
	else{
		printf("Trees are not the same\n");
	}
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

insertInTree(node **head, int key){
    if(*head == NULL){
        (*head) = (node *)malloc(sizeof(node));
        (*head)->data = key;
        (*head)->left = NULL;
        (*head)->right = NULL;
        return;
    }
    if(key > (*head)->data){
        insertInTree(&((*head)->right), key);
    }
    else{
        insertInTree(&((*head)->left), key);
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

search(node *head, int key){
    if(head->data == key){
        printf("found %d\n", key);
        return;
    }
    if(key > head->data){
        search(head->right, key);
    }
    if(key < head->data){
        search(head->left, key);
    }
}

int maxDepth(node *head){
    if(head == NULL){
        return 0;
    }
    else{
        printf("head %d\n", head->data);
        int left = maxDepth(head->left);
        int right = maxDepth(head->right);
        if(left > right){
            return left + 1;
        }
        else{
            return right + 1;
        }
    }
}

printAllPaths(node *trunk, int path[], int length){
    if(trunk == NULL) return;

    path[length++] = trunk->data;

    if(trunk->left == NULL & trunk->right == NULL){
		printPath(path, length);
    }
    else{
        printAllPaths(trunk->left, path, length);
        printAllPaths(trunk->right, path, length);
    }
}

printPath(int path[], int length){
	int i;
	printf("Path: ");
	for(i = 0; i < length; i++){
		printf("%d ", path[i]);
	}
	printf("\n");
}

int compareTrees(node *treeA, node *treeB){
	if(treeA == NULL && treeB == NULL) return 1;
	else if(treeA != NULL && treeB != NULL){
		return (treeA->data == treeB->data &&
			compareTrees(treeA->left, treeB->left) &&
			compareTrees(treeA->right, treeB->right)
			);
	}
	else{
		return 0;
	}
}
