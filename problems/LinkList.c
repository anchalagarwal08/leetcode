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

/*reverse a linklist in place*/
struct ListNode* reverseList(struct ListNode *head)
{
  if(!head)
    return NULL;
  if(head->next==NULL)
    return head;
  struct ListNode *prev=NULL, *curr=head, *next=head->next;
  while(curr!=NULL)
  {
    curr->next=prev;
    prev=curr;
    curr=next;
    if(next!=NULL)
      next=next->next;
  }
  printf("prev->val=%d", prev->val);
  return prev;
}
int countNodes(struct ListNode *head)
{
  if(!head)
    return 0;
  struct ListNode *curr=head;
  int count=0;
  while(curr!=NULL)
  {
    count++;
    curr=curr->next;
  }
  return count;
}

/*234. Palindrome Linked List   O(n) time and O(1) space*/
bool isPalindrome(struct ListNode* head) {
  if(!head)
    return true;
  struct ListNode *head2=NULL;
  int size = countNodes(head);
  if(size==1)
    return true;
  if(size==2)
    return (head->val==head->next->val);
  int lim=0, count=0;
  if(size%2==0)
    lim=size/2-1;
  else
    lim=size/2;
  struct ListNode *curr=head;
  while(count<lim)
  {
    curr=curr->next;
    count++;
  }
  head2=curr->next;
  curr->next=NULL;
  head2 = reverseList(head2);
  while(head && head2)
  {
    if(head->val !=head2->val)
      return false;
    head = head->next;
    head2=head2->next;
  }
  return true;
}

/*142. Linked List Cycle II   : Given a linked list, return the node where the cycle begins. If there is no cycle, return null.*/
struct ListNode *detectCycle(struct ListNode *head) {
  if(!head || head->next==NULL)
    return NULL;
  if(head->next==head)
    return head;
  struct ListNode *slow=head, *fast=head->next, *curr=NULL;
  bool cycleFound=false;
  int count=1;
  while(fast!=NULL && slow!=NULL && fast->next!=NULL)
  {
    slow=slow->next;
    fast=fast->next->next;
    if(fast==slow){
      cycleFound=true;
      break;
    }
  }
  if(cycleFound)
  {   curr=slow->next;
    while(curr!=slow)
    {
      curr=curr->next;
      count++;
    }
    printf("count=%d",count);
    curr=head;
    while(count>0)
    {
      curr=curr->next;
      count--;
    }
    while(head!=curr)
    {
      head=head->next;
      curr=curr->next;
    }
    return head;
  }
  return NULL;
}
