#include <stdlib.h>
#include <stdio.h>

typedef struct node *ptr;

typedef struct node {
	unsigned long int data;
	ptr next;
} item;

/* Function Prototypes */

int push(ptr* headRef, unsigned int newData);
void print(ptr head);
int length(ptr head);
void clear(ptr head);

/* Main & Supporting Functions */
int main()
{
	ptr head = NULL, topHead = NULL;
	int i, n, lastData, lastLastData, status, success;	
	unsigned int sum;	

	lastData = 0;
	lastLastData = 1;
	sum = 0;

	/* Pushes the first item in a list linked to the value 0 */
	status = push(&head, 0);

	topHead = head;

	printf("\033[1m\033[34mBuils a Fibonacci series \033[0m\n");

	printf("Enter a number for the length of the series : \n");

	success = scanf("%d", &n);

	/* Checks whether the value entered from the user is correct */
	if(success < 0 || n < 0 || success == EOF) {
		
		printf("Invalid input \n");
		return 0;
	}

	/* This loop builds the linked list according to the number entered from the user */
	for(i = 0; status && i < n; i++) {
	
		/* This code snippet builds the linked list in the from of the Fibonacci series */
		sum = lastData + lastLastData;

		status = push(&head, sum);

		lastLastData = lastData;

		lastData = sum;

	}

	/* Checks whether memory allocation has failed */
	if(status) {

		topHead->next = head;

		print(head);

	} else {

		printf("Building a Fibonacci series using memory allocation faild \n");
	}

	clear(head);

	return 0;
}

/* This function pushes an item to the beginning of the linked list */
int push(ptr* headRef, unsigned int newData)
{
	item* newNode = (ptr) malloc(sizeof(item));

	if(!newNode)
		return 0;	

	newNode->data = newData;
	newNode->next = (*headRef);
	(*headRef) = newNode;

	return 1;
}

/* This function prints the values of the linked list */
void print(ptr head)
{
	int amount;
	item *curr = NULL;

	amount = length(head);
	curr = head;

	printf("\033[1m\033[34mPrint the Fibonacci series \033[0m\n");

	printf("\033[1m\033[37mThe number of items in the series is : %d \033[0m\n", amount);
	
	printf("For item [ fib(%d) ] is : %lu \n", (amount - 1), curr->data);

	curr = curr->next;

	if(amount > 0)
		amount--;
	
	/* Running in a loop to the top of the linked list */
	while(curr != head) {

		printf("For item [ fib(%d) ] is : %lu \n", (amount - 1), curr->data);

		curr = curr->next;

		if(amount > 0)
			amount--;
	}

}

/* This function returns the number of items in the linked list */
int length(ptr head)
{
	int count;
	item *curr = NULL;

	count = 1;	

	curr = head;

	curr = curr->next;

	/* Running in a loop to the top of the linked list */
	while(curr != head) {

		curr = curr->next;

		count++;
	}

	return count;
}

/* This function clears the items in the linked list */
void clear(ptr head)
{
	item *curr = NULL, *lastCurr = NULL;

	curr = head;

	curr = curr->next;

	free(head);

	if(curr) {

		/* Running in a loop to the top of the linked list */
		while(curr != head) {

			lastCurr = curr;

			curr = curr->next;

			free(lastCurr);
		}

	}
}
