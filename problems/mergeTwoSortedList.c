#include<stdio.h>
#include <stdlib.h>
struct ListNode{
	int val;
	struct ListNode *next;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*Returning a new List*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    struct ListNode* head=(struct ListNode *)malloc(sizeof(struct ListNode));
    head->next=NULL;
    struct ListNode *node, *curr;
    struct ListNode *ptr1=l1, *ptr2=l2;
    if(ptr1->val<ptr2->val){
        head->val=ptr1->val;
        ptr1=ptr1->next;
    }
    else{
        head->val=ptr2->val;
        ptr2 = ptr2->next;
    }
    curr=head;
    while(ptr1 && ptr2)
    {
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->next=NULL;
        if(ptr1->val<ptr2->val)
        {
            node->val=ptr1->val;
            ptr1=ptr1->next;
        }
        else 
        {
            node->val=ptr2->val;
            ptr2=ptr2->next;
        }
        curr->next=node;
        curr=curr->next;
    }
    if(ptr1)
    {
        while(ptr1!=NULL)
        {
            node = (struct ListNode *)malloc(sizeof(struct ListNode));
            node->next=NULL;
            node->val=ptr1->val;
            curr->next = node;
            curr=curr->next;
            ptr1=ptr1->next;
        }
    }
    if(ptr2)
    {
          while(ptr2!=NULL)
        {
            node = (struct ListNode *)malloc(sizeof(struct ListNode));
            node->next=NULL;
            node->val=ptr2->val;
            curr->next = node;
            curr=curr->next;
            ptr2=ptr2->next;
        }
    }
  return head;
}

/*No extra space. Merge in place*/
struct ListNode* mergeTwoLists2(struct ListNode* l1, struct ListNode* l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    struct ListNode* head;
    struct ListNode *prev, *curr;
    struct ListNode *ptr1=l1, *ptr2=l2;
    if(ptr1->val<ptr2->val){
        head=ptr1;
        ptr1=ptr1->next;
    }
    else{
        head=ptr2;
        ptr2 = ptr2->next;
    }
    prev=head;
    while(ptr1 && ptr2)
    {
	    if(ptr1->val<ptr2->val)
	    {
		    prev->next=ptr1;
		    prev=prev->next;
		    ptr1=ptr1->next;
	    }
	    else{
		    prev->next=ptr2;
		    prev=prev->next;
		    ptr2=ptr2->next;
	    }
    }
    if(ptr1)
    {
        while(ptr1!=NULL)
        {
            prev->next = ptr1;
            prev=prev->next;
            ptr1=ptr1->next;
        }
    }
    if(ptr2)
    {
          while(ptr2!=NULL)
        {
            prev->next =ptr2;
            prev=prev->next;
            ptr2=ptr2->next;
        }
    }
  return head;
}
