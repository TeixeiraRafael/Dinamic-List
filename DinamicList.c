#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;


void create(Node **head){
	*head = NULL;
}


void prepend(Node **head, int value){
	Node *new;
	/* Allocating space */
	new = malloc(sizeof(Node));
	
	/* The allocated space recieves the data */
	new->data = value;
	
	/* next node recieves the old head node */
	new->next = *head;
	
	/* new node becomes the new head */
	*head = new;
}

void append(Node **head, int value){
	Node *new;
	Node *current;
	
	/* Allocating space */
	new = malloc(sizeof(Node));
	new->data = value;
	new->next = NULL;
	
	/* if the list is empty (no head) */
	if(*head == NULL){
		/* the input value becomes the head */
		*head = new;
	}else{
		/* if not, go to the end of the list */
		current = *head;
		
		while(current->next != NULL){
			current = current->next;
		}
		/* Adds the input node at the end of the list */
		current->next = new;
	}
	
}

void printList(Node *head){
	int cont = 0;

	while(head != NULL){
		printf("[%d] = %d\n", cont, head->data);
		head = head->next;
		cont++;		
	}
	
}

int main(){
	int m, n, i, j;
	
	Node *lista;
	
	create(&lista);
	
	for(i = 0; i < 10; i++){
		append(&lista, i*i);
	}

	printList(lista);
}

























