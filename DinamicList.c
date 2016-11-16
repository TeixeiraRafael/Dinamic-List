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

	if(index >= length(head)){
		printf("Index out of bounds.\n");
		exit(1);

	}

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
	Node *current = *head; 
	Node *deleted = NULL; //node to be deleted
	
	int l = length(*head);
	
	if(index >= l || index < 0){
		printf("Index out of bounds.\n");
		exit(1);
	}

	if(index == 0){
		/* We already have a method to delete the first item of a list */
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

int removeByValue(Node **head, int value){
	Node *current = *head;
	int data;
	int l = length(*head);
	for(int i = 0; i < l; i++){
		data = current->data;
		
		if(data == value){
			removeFromIndex(&(*head), i);
			return 0;
		}

		current = current->next;
	}
	printf("Value %d not found.\n", value);
}

/* Main function with some test cases */
int main(){
	int i, input, option, option2, retrn;

	Node *list; //Declares the list
	create(&list); //Creates the list
	
	while(1){
		printf("1 - Adds one intem to the list\n2 - Selects one intem from the list\n3 - Removes an item from the list\n4 - Prints the list\n5 - exit\n");
		printf("Option: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				printf("Value: ");
				scanf(" %d", &input);
				append(&list, input);
				printf("%d added.\n", input);
				break;
			case 2:
				printf("Index: ");
				scanf("%d", &input);
				retrn = getValue(list, input);
				printf("[%d] = %d\n", input, retrn);
				break;
			case 3:
				printf("1 - Remove from index\n2 - Remove by value\n");
				scanf("%d", &option2);
				switch(option2){
					case 1:
						printf("Index: ");
						scanf("%d", &input);
						removeFromIndex(&list, input);
						retrn = getValue(list, input);
						printf("%d removed.\n", retrn);
						break;
					case 2:
						printf("Value: ");
						scanf("%d", &input);
						removeByValue(&list, input);
						break;
					default:
						printf("Invalid option.\n");
					break; 
				}
				break;
			case 4:
				printf("\n");
				printList(list);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Invalid option.\n");
				break;
		}
	}
}
