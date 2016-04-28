/**24. Swap Nodes in Pairs
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(!head)
        return NULL;
    if(head->next==NULL)
        return head;
    struct ListNode *p1=NULL, *prev=head, *curr=prev->next, *head1=head->next;
    while(prev!=NULL && curr!=NULL)
    {
        prev->next = curr->next;
        curr->next=prev;
        if(p1!=NULL){
            p1->next=curr;
        }
        p1=prev;
        prev=prev->next;
        if(prev!=NULL)
            curr=prev->next;
    }
    return head1;
}
