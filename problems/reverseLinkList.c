/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
92. Reverse Linked List II
Reverse a linked list from position m to n. Do it in-place and in one-pass.
 */

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *startprev, *start,*curr, *prev, *next;
    int i=0,k=m;
    if(!head)
        return NULL;
    if(head->next==NULL)
        return head;
    if(m==n)
        return head;
    prev=head;
    while((k-1)>0)
    {
        startprev=prev;
        prev=prev->next;
        k--;
    }
    start=prev;
    curr=prev->next;
    next=curr->next;

    for(i=0;i<(n-m);i++)
    {
        curr->next=prev;
        prev=curr;
        curr=next;
        if(next)
            next=next->next;
    }
    if(m==1)
        head=prev;
    else
        startprev->next=prev;
    start->next=curr;
    return head;
}


/**
206. Reverse a singly linked list.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev=NULL, *curr=head, *next=NULL;
    if(head==NULL)
        return NULL;
    else if(head->next==NULL)
        return head;
    next = curr->next;
    while(curr!=NULL)
    {
        curr->next=prev;
        prev=curr;
        curr=next;
        if(next)
            next=next->next;
    }
    return prev;
}
