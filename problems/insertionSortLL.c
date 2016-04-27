/**
147. Insertion Sort List

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    struct ListNode *curr=head, *ptr=head->next;
    int tmp=0;
    while(ptr!=NULL)
    {
        while(curr!=ptr)
        {
            if(curr->val > ptr->val)
            {
                tmp=curr->val;
                curr->val=ptr->val;
                ptr->val=tmp;
            }
            curr=curr->next;
        }
        curr=head;
        ptr = ptr->next;
    }
    return head;
}
