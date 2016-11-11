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

int length(Node *head){
	int cont = 0;

	while(head != NULL){
		//iterates through the list
		head = head->next;
		cont++;		
	}

	return cont;
}

int getValue(Node *head, int index){
	int i;
	for(i = 0; i < index; i++){
		head = head->next;
	}
	return head->data;
}

void printList(Node *head){
	int i;
	int l = length(head);
	for(i = 0; i < l; i++){
		printf("[%d] = %d\n", i, head->data);
		head = head->next;
	}
}

int removeFirst(Node **head){
	Node *next = (*head)->next;

	if(*head == NULL){
		printf("The list is empty\n");
		return -1;
	}

	free(*head);
	*head = next;
}

int removeFromIndex(Node **head, int index){
	int i;
	
	Node *current = *head; 
	Node *deleted = NULL; //node to be deleted
	
	int l = length(*head);

	if(index > (l-1)){
		printf("Index out of range\n");
		return -1;
	}

	if(index == 0){
		removeFirst(&(*head));
		return 0;
	}

	/* Goes to the index before the one to be deleted */
	for (int i = 0; i < index - 1; i++){
		current = current->next;
	}

	/* Links the previous node to the next Node */
	deleted = current->next;
	current->next = deleted->next;

	/* finally deletes the given node */
	free(deleted);
	deleted = NULL;
}

/* Main function with some test cases */
int main(){
	int m, n, i, j;
	
	Node *list; //Declares the list
	create(&list); //Creates the list

	/* Adds 10 values to the list */
	for(i = 0; i < 10; i++){
		append(&list, i);
	}

	/* Prints the list */
	printList(list);
	printf("\n");
	
	/* Removes the first item of the list */
	removeFirst(&list);

	/* Removes the item on the index 5 */
	removeFromIndex(&list, 5);

	/* Prints the list again */
	printList(list);
}