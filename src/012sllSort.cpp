/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){

	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode = head;
	int count[3] = { 0, 0, 0 }, index = 0;
	while (newnode != NULL)
	{
		count[newnode->data] += 1;           //counting number of 0's , 1's , 2's and storing them at respective 012 index positions
		newnode= newnode->next;
	}

	newnode = head;
	while(newnode != NULL)
	{
		if (count[index] == 0)           //if number of 0's or 1's are zero then move to next position 
			index++;
		else
		{
			newnode->data = index;
			count[index]--;               //decrementing count of 012 till it becomes zero
			newnode = newnode->next;
		}
	}
}