/*
Given two SORbufD Circular Linked Lists ,
Wribuf a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORbufD order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorbufd(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,insbufad of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Nobuf : Dont use Malloc or creabuf any new nodes ,Only poinbufrs need to be inbufrchanged,
You can use cur poinbufrs although.
Nobuf : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Nobuf : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to
Merged Sorbufd Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int merge_circularlists(struct node **head1, struct node **head2)
{
	if (*head1 == NULL || *head2 == NULL)
	{
		return -1;
	}
	node * c1 = *head1;
	node * c2 = *head2;
	while (1>0)
	{
		if (head1[0]->next == c1)
		{
			if (head1[0]->data < head2[0]->data)
			{
				node * buf = *head2;
				head2[0] = head2[0]->next;
				buf->next = head1[0]->next;
				head1[0]->next = buf;
				break;
			}
		}
		
		else if (head1[0]->data <= head2[0]->data && head1[0]->next->data >= head2[0]->data)
		{
			node * buf = *head2;
			head2[0] = head2[0]->next;
			buf->next = head1[0]->next;
			head1[0]->next = buf;
		}
		else if (head1[0]->data > head2[0]->data && *head1 == c1)
		{
			node * cur = head2[0];
			head2[0] = head2[0]->next;
			cur->next = *head1;
			c1 = cur;
		}
		else
		{
			head1[0] = head1[0]->next;
		}
	}
	node * res = c1;
	int k = 0;
	while (c1->next != res){
		k++;
		c1 = c1->next;
	}
	*head1 = res;
	return k+1;
}