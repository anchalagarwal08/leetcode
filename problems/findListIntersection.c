/*Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL || headB==NULL)
        return NULL;
    if(headA==headB)
        return headA;
    int len1=0, len2=0,val=0;
    struct ListNode *curr1=headA, *curr2=headB, *returnNode=(struct ListNode*)malloc(sizeof(struct ListNode));
    returnNode->next=NULL;
    while(curr1!=NULL)
    {
        len1++;
        curr1=curr1->next;
    }
    while(curr2!=NULL)
    {
        len2++;
        curr2=curr2->next;
    }
    curr1=headA;
    curr2=headB;
    if(len1>len2)
    {
        while(len1>len2)
        {
            curr1=curr1->next;
            len1--;
        }
    }
    else if(len1<len2)
    {
        while(len2>len1)
        {
            curr2=curr2->next;
            len2--;
        } 
    }
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1==curr2){
            returnNode->val=curr1->val;
            return returnNode;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return NULL;
}
