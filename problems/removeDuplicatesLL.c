#include <stdio.h>
#include<stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode{

	int val;
	struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *curr, *prev;
    if(!head)
        return NULL;
    if(head->next==NULL)
        return head;
    curr=head;
    prev=curr->next;
    while(curr!=NULL && curr->next!=NULL)
    {
	    while(curr->val==prev->val)
	    {
		    prev = prev->next;
		    if(!prev)
			break;
	    }
	    curr->next = prev;
	    curr=curr->next;
	    if(prev)
	    	prev=prev->next;
    }
    return head;
}
int main()
{

	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	int arr[] = {2, 5, 5, 6, 6 ,6};
	head->next=NULL;
	head->val=1;
	struct ListNode *curr=head;
	int i=0;
	for(i=0;i<6;i++)
	{
		struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
		node->next=NULL;
		node->val=arr[i];
		curr->next=node;
		curr=curr->next;
	}
	head= deleteDuplicates(head);
	curr=head;
	while(curr!=NULL)
	{
		printf("%d ", curr->val);
		curr=curr->next;
	}
return 0;
}
