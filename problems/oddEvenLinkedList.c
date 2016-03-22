/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head)
        return NULL;
    if(head->next==NULL || head->next->next==NULL)
        return head;
    struct ListNode *odd=head, *even=odd->next, *curr=odd->next;
    while(odd->next && even)
    {
        odd->next=even->next;
        if(odd->next)
        {
            odd=odd->next;
            even->next=odd->next;
        }
        even=even->next;
    }
    odd->next=curr;
    return head;
    
}
