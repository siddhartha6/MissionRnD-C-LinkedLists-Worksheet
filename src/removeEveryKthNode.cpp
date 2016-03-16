/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head == NULL || K < 0 || K ==0 || K==1)
		return NULL;
	int index = 0;
	for (index = 1; head != NULL; index++)
	{
		if (index % K == 0){
			head = head->next;
			head->next = (head->next)->next;
		}
		//printf("  %d", head1->data);
		head = head->next;
	}
	return head;
}