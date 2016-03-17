/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
void swap(struct node *a, struct node *b);

void swap(struct node *a, struct node *b)
{
	int temp = a->num;
	a->num = b->num;
	b->num = temp;
}
struct node * sortLinkedList(struct node *head) {

	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;                                //if their is only one element then return that 1 element
	
	int check = 0;
	struct node *traverse = NULL, *temp = NULL;
 
	do
	{
		check = 0;
		traverse = head;

		while (traverse->next!= temp)
		{
			if (traverse->num > traverse->next->num)      //comparing each node with other nodes
			{
				swap(traverse, traverse->next);    //if true swapping two nodes and swap check will be 1
				check = 1;
			}
			traverse = traverse->next;
		}
		temp = traverse;
	}while(check!=0);

	return head;
}

	