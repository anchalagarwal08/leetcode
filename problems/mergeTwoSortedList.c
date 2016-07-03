#include<stdio.h>
#include <stdlib.h>
#include "node.h"
struct ListNode{
	int val;
	struct ListNode *next;
};

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

void moveNode(Node **dest, Node ** src)
{
  Node *newNode = *src;
  *src=newNode->next;
  newNode->next=NULL;
  (*dest)->next=newNode;
}
Node* merge2Lists(Node *list1, Node *list2)
{
  Node dummy;
  Node *tail = &dummy;
  dummy.next=NULL;
  while(1)
  {
    if(list1==NULL)
    {
      tail->next=list2;
      break;
    }
    if(list2==NULL)
    {
      tail->next=list1;
      break;
    }
    if(list1->val<=list2->val)
    {
      moveNode(&tail, &list1);
    }
    else
      moveNode(&tail, &list2); 
    tail=tail->next;
  }
  return dummy.next;
}
Node* mergeKLists(Node** lists, int listsSize) {
  if(lists==NULL)
    return NULL;
  int last=listsSize-1,i=0,j=0;
  while(last!=0)
  {
    i=0;j=last;
    while(i<j)
    {
      lists[i]=merge2Lists(lists[i],lists[j]);
      i++;j--;
      if(i>=j)
        last=j;
    }
  }
  return lists[0];
}
int main()
{
  int k = 3; // Number of linked lists
  int n = 4; // Number of elements in each list
  Node* arr[k];

  arr[0] = newNode(1);
  arr[0]->next = newNode(3);
  arr[0]->next->next = newNode(5);
  arr[0]->next->next->next = newNode(7);

  arr[1] = newNode(2);
  arr[1]->next = newNode(4);
  arr[1]->next->next = newNode(6);
  arr[1]->next->next->next = newNode(8);

  arr[2] = newNode(0);
  arr[2]->next = newNode(9);
  arr[2]->next->next = newNode(10);
  arr[2]->next->next->next = newNode(11);

  // Merge all lists
  Node* head = mergeKLists(arr, k);
  while(head!=NULL)
  {
    printf(" %d->", head->val);
    head=head->next;
  }
  return 0;
}
