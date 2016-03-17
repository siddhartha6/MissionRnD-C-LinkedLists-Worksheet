/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};



struct node *removeEveryKthNode(struct node *head, int K)
{
	
	if (head == NULL || K<1) 
		return NULL;                   //Error cases
	if (K == 1){
		head = NULL;                 //if k == 1 all nodes must be deleted, then return NULL
	    return head;
    } 
	int index = 0;
	struct node *newnode = head;

	while (head->next != NULL){

		index++;
		if (index == K - 1)
		{
			if ((head->next->next) == NULL){              //if element next to Kth element is NULL then assign kth element as NULL and exit
						
				head->next = NULL;
				break;
			}
			else
				head->next = (head->next)->next;      //Kth node is replaced by next node to that of kth node

		   index = 0;                       
		}
		head = head->next;

	}

	return newnode;
}