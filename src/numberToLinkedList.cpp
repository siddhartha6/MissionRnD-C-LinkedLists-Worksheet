/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/


#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node *result;

void insert(int N)
{

	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->num = N;                                          //inserting elements at front of linked list
	temp->next = result->next;
	result->next = temp;
}

struct node * numberToLinkedList(int N) {

	result = (struct node *)malloc(sizeof(struct node));
	if (N < 0)
		N = (-1)*N;                        //if Number < 0 then ignoring then converting it into +ve
	result->num = NULL;
	result->next = NULL;
	
	if (N == 0 || N < 10){
		insert(N);                         //if Number is single digit number insert directly
		N = 0;
	}

	while (N != 0 || N >= 10)
	{
		insert(N % 10);                  //if number is greater than 10 convert each digit to list
		N = N / 10;
	}
	result = result->next;
	return result;
}