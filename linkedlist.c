#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

typedef struct node node;

int main()
{
	node *current, *head;
	int i;
	head = NULL;
	
	for(i = 0; i < 10; i++){
		current = (node *)malloc(sizeof(node));
		current->data = i;
		current->next = head;
		head = current;
	}
	
	current = head;

	int c = count(head);
	printf("%d\n", c);
	delete(head);
    
    node* sorted = NULL;
    insert(&sorted, 3);
    insert(&sorted, 4);
    insert(&sorted, 6);
    insert(&sorted, 5);
    insert(&sorted, 9);
    insert(&sorted, 1);
    insert(&sorted, 2);
    insert(&sorted, 7);
    insert(&sorted, 8);
    print(sorted);
}

print(node *head){
    node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int count(struct node *head)
{
	int count = 0;
	node *temp = head;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return (count);
}

delete(struct node *head){
	node *temp = head;
	node *temp2;
	while(temp != NULL){
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	head = NULL;	
}

insert(node** head, int number){
	printf("Inserting %d\n", number);
    if(*head == NULL){
        printf("null list, creating a new one\n");
		*head = (node*)malloc(sizeof(node));
        (*head)->data = number;
	    (*head)->next = NULL;
		return;
	}
    else{
        node* temp = *head;
        node* prev = NULL;
        if(number < (*head)->data){
            printf("%d < %d, inserting %d as first in list\n", number, (*head)->data, number);
            node* temp2 = (node*)malloc(sizeof(node));
            temp2->data = number;
            temp2->next = temp;
            *head = temp2;
            return;
        }
        while(temp != NULL){
           if(number > temp->data){
               prev = temp;
               temp = temp->next;
           }
           else{
               printf("else %d\n", temp->data);
               node* temp3 = (node*)malloc(sizeof(node));
               temp3->data = number;
               prev->next = temp3;
               temp3->next = temp;
               return;
           }
        }
        printf("end while\n");
        if(number > prev->data){
            printf("inserting %d at end of list\n", number);
            node* temp4 = (node*)malloc(sizeof(node));
            temp4->data = number;
            prev->next = temp4;
            temp4->next = NULL;
        }
    }
}
