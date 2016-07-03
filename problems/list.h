typedef struct ListNode{
    int val;
      struct ListNode *next;
}List;

List *createList();
int countNodes(List *head);
List *createList()
{
  List *head = (List*)malloc(sizeof(List));
  head->val=1;
  head->next=NULL;
  List *curr=head;
  int i=2;
  while(i<=7)
  {
    List *node = (List*)malloc(sizeof(List));
    node->val=i;
    node->next=NULL;
    curr->next=node;
    curr=curr->next;
    i++;
  }
  return head;
}

int countNodes(List *head)
{
  if(!head)
    return 0;
  List *curr=head;
  int count=0;
  while(curr!=NULL)
  {
    count++;
    curr=curr->next;
  }
  return count;
}
