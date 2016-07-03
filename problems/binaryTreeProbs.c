/**
110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"
#include <limits.h>
int max(int a,int b){
    return (a>=b)?a:b;
}
int min(int a,int b){
      return (a<=b)?a:b;
}
void preorder(Node* root)
{
  if(root==NULL)
    return;
  printf("%d ", root->val);
  preorder(root->left);
  preorder(root->right);
}
int height(Node *node)
{
    if(node==NULL)
        return 0;
    return 1+max(height(node->left), height(node->right));
}
/*complexity of this is nlogn, since each node we recurse through its entire tree*/
bool isBalanced(Node* root) {
    int lh, rh;
    if(root==NULL)
        return true;
    lh = height(root->left);
    rh = height(root->right);
    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}


/**
101. Symmetric Tree 
 */
bool isSymmetricHelper(Node *root1, Node *root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1 && root2 && root1->val==root2->val)
        return isSymmetricHelper(root1->left, root2->right) && isSymmetricHelper(root1->right, root2->left);
    return false;
}
bool isSymmetric(Node* root) {
    if(root==NULL)
        return true;
    return isSymmetricHelper(root, root);
}



/**
112. Path Sum 
 */
bool hasPathSumHelper(Node *root, int sum)
{
    if(root==NULL)
        return (sum==0);
    else
    {   bool ans=false;
        int subsum = sum - root->val;
        if(root->left==NULL && root->right==NULL && subsum==0)
            return true;
        if(root->left)
            ans = ans || hasPathSumHelper(root->left,subsum);
        if(root->right)
            ans = ans || hasPathSumHelper(root->right,subsum);
        return ans;
    }
}
bool hasPathSum(Node* root, int sum) {
    if(root==NULL)
        return false;
   int curr=0;
    return hasPathSumHelper(root, sum);
}

/*Print root to leaf paths for binary tree*/
void printPath(int *arr, int length)
{
    int i=0;
      for(i=0;i<length;i++)
          {
                printf("%d,", arr[i]);
                  }
        printf("\n");
}

void printPathBT(Node *root, int *arr, int pathlen)
{
  if(root==NULL)
    return;
  arr[pathlen++]=root->val;
  if(root->left==NULL && root->right==NULL)
    printPath(arr, pathlen);
  else{
    printPathBT(root->left, arr, pathlen);
    printPathBT(root->right, arr, pathlen);
  }
}
/*Print path ends*/

/*mirror binary tree. Change the tree to its mirror*/
/*Doing postorder traversal here. to swap left and right children of a node traverse left and right first and swap them when u r at node*/
void mirrorBT(Node *root)
{
  if(root==NULL)
    return;
  mirrorBT(root->left);
  mirrorBT(root->right);
  Node *tmp = root->left;
  root->left = root->right;
  root->right = tmp;
}

/*Find if Binary tree is a BST*/
bool isBSTUtil(Node *root, int min, int max)
{
  if(root==NULL)
    return true;
  if(root->val<min || root->val>max)
    return false;
  else
    return(isBSTUtil(root->left, min, root->val-1) && isBSTUtil(root->right, root->val+1, max));
}
/*189. Rotate Array */
void reverseArray(int *arr, int start, int end)
{
  int i=0;
  for(i=0;i<=(end-start)/2;i++)
  {
    int tmp = arr[start+i];
    arr[start+i] = arr[end-i];
    arr[end-i] = tmp;
  }
}
void rotate(int* nums, int numsSize, int k) {
  if(numsSize==1 || k==0 || k==numsSize)
    return;
  if(k>numsSize)
    k=k%numsSize;
  reverseArray(nums,0,numsSize-k-1);
  reverseArray(nums, numsSize-k, numsSize-1);
  reverseArray(nums, 0, numsSize-1);
}

/*102. Binary Tree Level Order Traversal */
void levelOrderTraverse(Node *root, int level, int *arr, int *size)
{
	if(root==NULL || level==0)
		return;
	if(level==1){
		arr[*size]=root->val;
		printf("%d ,", arr[*size]);
		(*size)++;
	}
	levelOrderTraverse(root->left, level-1, arr, size);
	levelOrderTraverse(root->right, level-1, arr, size);
}
int** levelOrder(Node* root, int** columnSizes, int* returnSize) {
	int h = height(root);
	int i=1,j=0, size=0, count=0, returnsize=0;
	int **arr = (int**)malloc(sizeof(int*)*(h+1));
	*columnSizes = (int*)malloc(sizeof(int)*(h+1));
	*returnSize=0;
	for(i=1;i<=h;i++)
	{
		int *arr1= (int*)malloc(sizeof(int)*50);
		levelOrderTraverse(root, i, arr1, &size);
		*columnSizes[count++]=size;
		arr[(*returnSize)++]=arr1;
		size=0;
	}
	*returnSize = *returnSize-1;
	return arr;
}

void printPathArray(int *path, int size)
{
  int i=0;
  printf("\n");
  for(i=0;i<size;i++)
    printf("%d ,", path[i]);
}
void hasPathSumHelper2(Node *root, int sum, int *pathArray, int size)
{
  if(root==NULL)
    return;
  int subsum=sum-root->val;
  pathArray[size++]=root->val;
  if(subsum==0 && root->left==NULL && root->right==NULL)
    printPathArray(pathArray,size);
  hasPathSumHelper2(root->left, subsum, pathArray, size);
  hasPathSumHelper2(root->right, subsum, pathArray, size);
}
void pathSum2(Node* root, int sum) {
  if(root==NULL)
    return;
  int *pathArray = (int *)malloc(sizeof(int)*100);
  memset(pathArray, 0, 100);
  int size=0;
  hasPathSumHelper2(root, sum, pathArray, size);
}

/*314 Binary Tree Vertical Order Traversal.Print a Binary Tree in Vertical Order 
 * eg:
 *      1
 *    /    \
 *   2      3
 *  / \    / \
 * 4   5  6   7
 *        \   \
 *         8   9 
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9 

The idea is to calculate the minumum and maximum horizontal distance from root to leftmost child and to rightmost child
Horizontal distance(hd) of root = 0
If you go left then hd = hd(of its parent)-1, and
if you go right then hd = hd(of its parent)+1.

Once you get maximum/minumum hd, print values at each distance
*/

void findMinMaxHd(Node *root, int *max, int *min, int hd)
{
  if(root==NULL)
    return;
  if(*min>hd)
    *min=hd;
  else if(*max<hd)
    *max=hd;
  findMinMaxHd(root->left, max, min, hd-1);
  findMinMaxHd(root->right, max, min, hd+1);
}
/*This is of O(n^2) solution because in worst case width=n. This can be resolved in O(n) using hahsmap. Save nodes at same hd while finding hd and later traverese the map to print the values at same width. <key,value>= <width, list<nodes>>*/
void printVerticalOrder(Node *root, int line, int hd)
{
  if(root==NULL)
    return;
  if(line==hd)
    printf("%d ,", root->val);
  printVerticalOrder(root->left, line, hd-1);
  printVerticalOrder(root->right, line, hd+1);
}
void verticalorder(Node *root)
{
  if(root==NULL)
    return;
  int i=0, max=0, min=0;
  findMinMaxHd(root, &max, &min, 0);
  printf("\n min=%d, max=%d\n", min, max);
  for(i=min;i<=max;i++)
  {
    printVerticalOrder(root, i, 0);
    printf("\n");
  }
}
/*LCA of BT. Assume both nodes are in the tree*/
Node * LCABT(Node *root, Node *p, Node *q)
{
    if(root==NULL)
      return NULL;
    if(root->val==p->val)
      return root;
    else if(root->val==q->val)
      return root;
    Node *left = LCABT(root->left, p, q);
    Node *right =LCABT(root->right, p, q);
    if(left && right)
      return root;
    return (left!=NULL)?left:right;
}

bool matchNodes(Node *t1, Node *t2)
{
  if(t1==NULL && t2==NULL)
    return true;
  else if(t1==NULL || t2==NULL)
    return false;
  else if(t1->val!=t2->val)
    return false;
  else 
    return (matchNodes(t1->left, t2->left)&& matchNodes(t1->right,t2->right));
}
/*worst case is O(mn) where m and n are numbers of nodes in each subtree*/
bool checkSubtree(Node *t1, Node *t2)
{
  if(t1==NULL)
    return true;
  else if(t1->val ==t2->val && matchNodes(t1, t2))
    return true;
  else
    return (checkSubtree(t1->left, t2) || checkSubtree(t1->right, t2));
}

/*Print path with given sum in a binary tree. the path can start from any node and end at any node. This is O(nlogn) solutin. Brute forxe where you go through each path starting from every node. There is O(n) solution too*/

int computePath(Node *root, int target, int sum)
{
  if(root==NULL)
    return 0;
  printf("root=%d\n", root->val);
  sum=sum+root->val;
  int pathlen=0;
  if(sum==target){
    pathlen=pathlen +1;
  }
  pathlen+=computePath(root->left, target, sum);
  pathlen+=computePath(root->right, target, sum);
  return pathlen;
}

int computePathSum(Node *root, int target)
{
  if(root==NULL)
    return 0;
  int pathlen=computePath(root,target,0);
  int leftpathlen=computePathSum(root->left, target);
  int rightpathlen=computePathSum(root->right, target);
  return pathlen+leftpathlen+rightpathlen;
}

/*Diameter of binary tree*/
/*This is O(n) solution The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two leaves in the tree. */
int diameter(Node *root, int *height)
{
  int lh = 0, rh=0, ldiam=0, rdiam=0;
  if(root==NULL)
  {
    *height=0;
    return 0;
  }
  ldiam=diameter(root->left, &lh);
  rdiam=diameter(root->right, &rh);
  *height = max(lh, rh)+1;
  return max((lh+rh+1),max(ldiam,rdiam));
}

void incrementChild(Node *root, int diff)
{
  if(root==NULL)
    return;
  if(root->left!=NULL)
  {
    root->left->val=root->left->val+diff;
    incrementChild(root->left, diff);
  }
  else if(root->right!=NULL)
  {
    root->right->val=root->right->val+diff;
    incrementChild(root->right, diff);
  }
}
/*Do postorder traversal. worst case complexity O(n^2) for skewed trees and all nodes are in descending order. then for each node you have to go increment its child.*/
void childSumPropBT(Node *root)
{
  int left=0, right=0, diff=0;
  if(root==NULL || (root->left==NULL && root->right==NULL))
    return;
  childSumPropBT(root->left);
  childSumPropBT(root->right);
  if(root->left!=NULL)
    left=root->left->val;
  if(root->right!=NULL)
    right=root->right->val;
  diff=left+right-root->val;
  if(diff>0)
    root->val=root->val+diff;
  else if(diff<0)
    incrementChild(root, -diff);
}

/*Serialize Deserialize BT to and from string*/
/* Encodes a tree to a single string. */
void serializeHelper(Node *root, char arr[], int *i)
{
  if(root==NULL)
  {   arr[*i]=')';
    *i=*i+1;
    return;
  }   
  arr[*i]=root->val + '0';
  *i=*i+1;
  serializeHelper(root->left, arr, i);
  serializeHelper(root->right, arr, i);
}
char* serialize(Node* root) {
  if(!root)
    return NULL;
  char *arr = (char *)malloc(sizeof(char)*100);
  int i=0, j=0;
  serializeHelper(root,arr, &i);
  for(j=0;j<i;j++)
    printf("%d ", arr[j]-'0');
  return arr;
}

Node *createNode(char val)
{
  Node *root = (Node*)malloc(sizeof(Node));
  root->val=val-'0';
  root->left=NULL;
  root->right=NULL;
  return root;
}
void deserializeHelper(Node *root, char *data, int *i)
{
  if(root==NULL)
    return;
  if(data[*i]==')')
    return ;
  Node *node = createNode(data[*i]);
  *i=*i+1;
  deserializeHelper(root->left, data,i);
  deserializeHelper(root->right, data,i);
}
/** Decodes your encoded data to tree. */
Node* deserialize(char* data) {
  if(!data)
    return NULL;
  int i=1;
  Node *root = createNode(data[0]);
  deserializeHelper(root, data, &i);
  return root;
}

/*construct Tree from given Inorder and Preorder traversals
 * Let us consider the below traversals:
 * Inorder sequence: D B E A F C
 * Preorder sequence: A B D E C F
 */
int findIndex(int *arr, int start, int end, int elem)
{
  if(start>end)
    return -1;
  int i=0;
  for(i=start;i<=end;i++)
  {
    if(arr[i]==elem)
      return i;
  }
  return -1;
}
Node *cnstrctTreeInPre(int *in, int *pre, int in_start, int in_end, int *pre_index)
{
  if(in_start>in_end)
    return NULL;
  Node *root = newNode(pre[*pre_index]);
  (*pre_index)++;
  if(in_start==in_end)
    return root;
  int idx = findIndex(in, in_start, in_end, pre[*pre_index-1]);
  if(idx>=0){
  root->left=cnstrctTreeInPre(in,pre,in_start, idx-1, pre_index);
  root->right=cnstrctTreeInPre(in,pre,idx+1,in_end, pre_index);
  }
  return root;
}

/*Maximum width of a binary tree
 * Given a binary tree, write a function to get the maximum width of the given tree. Width of a tree is maximum of widths of all levels.width is number of nodes at any given level*/

void getMaxWidth(Node *root, int *arr, int level)
{
  if(!root)
    return;
  else{
    arr[level]++;
    getMaxWidth(root->left, arr, level+1);
    getMaxWidth(root->right, arr, level+1);
  }
}
int maxWidth(Node *root)
{
  if(!root)
    return 0;
  int h = height(root);
  int *arr = (int *)malloc(sizeof(int)*h);
  memset(arr, 0, h);
  getMaxWidth(root, arr, 0);
  int i=0, max=0;
  for(i=0;i<h;i++)
  {
    if(arr[i]>max)
      max=arr[i];
  }
  if(arr)
    free(arr);

  return max;
}
/*Convert a given tree to its Sum Tree
 * Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.
*/

int sumTree(Node *root)
{
  if(root==NULL)
    return 0;
  int old=root->val;
  root->val = sumTree(root->left)+sumTree(root->right);
  return root->val+old;
}


/*Populate Inorder Successor for all nodes
 * Given a Binary Tree where each node has following structure, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.
 *
 * struct node
 * {
 *   int data;
 *     struct node* left;
 *       struct node* right;
 *         struct node* next;
 *}*/
void populateSuccessor(Node *root, Node **prev, Node **head)
{
  if(root==NULL)
    return;
  populateSuccessor(root->left,prev, head);
  if(!*prev){
    *head=root;
    *prev=root;
  }
  else
  {
   (*prev)->next=root;
   *prev=(*prev)->next;
  }
 // root->next=*prev;
 // *prev=root;
  populateSuccessor(root->right, prev, head);
}

/*print preorder from postorder and inorder*/
int search(int *in, int val, int start, int end)
{
  int i=0;
  for(i=start;i<=end;i++)
  {
    if(in[i]==val)
      return i;
  }
  return -1;
}
void printPostOrder(int *in,int *pre,int *pos, int start, int end )
{
  if(start>end)
    return;
  int idx=search(in, pre[*pos], start, end);
  (*pos)++;
  printPostOrder(in, pre, pos, start, idx-1);
  printPostOrder(in, pre, pos, idx+1, end);
  printf("%d ,",in[idx]);
}
/*Find the maximum sum leaf to root path in a Binary Tree*/
void findMaxSumPath(Node *root, int *max_sum, int curr_sum, Node **target)
{
  if(!root)
    return;
  curr_sum=curr_sum+root->val;
  if(root->left ==NULL && root->right==NULL)
  {
    if(curr_sum>*max_sum)
    {
      *max_sum=curr_sum;
      *target=root;
    }
  }
  findMaxSumPath(root->left, max_sum, curr_sum, target);
  findMaxSumPath(root->right, max_sum, curr_sum, target);
}

bool printMaxPathSum(Node *root, Node *target)
{
  if(!root)
    return false;
  if(root==target ||printMaxPathSum(root->left,target) ||printMaxPathSum(root->right,target))
  {
    printf("%d ",root->val);
    return true;
  }
  return false;
}
/*Convert a given Binary Tree to Doubly Linked List*/
void convertBTDLLHelper(Node *root, Node **prev)
{ 
  if(!root)
    return;
  convertBTDLLHelper(root->left, prev);
  root->left=*prev;
  *prev=root;
  convertBTDLLHelper(root->right, prev);
}
void convertBTDLL(Node *root)
{
  if(!root)
    return;
  Node *prev=NULL;
  convertBTDLLHelper(root, &prev);
  Node *curr=NULL;
  printf("prev=%d\n",prev->val);
  if(prev!=NULL)
  {
    curr=prev->left;
    while(curr!=NULL)
    {
      printf("curr=%d\n",curr->val);
      curr->right=prev;
      prev=curr;
      curr=curr->left;
    }
  }
  Node *head=prev;
  while(prev!=NULL)
  {
    printf("%d ->",prev->val);
    prev=prev->right;
  }
}

/*Write a function to detect if two trees are isomorphic. Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.*/

bool isIsomorphic(Node *n1, Node *n2)
{
  if(n1==NULL && n2==NULL)
    return true;
  if(n1==NULL || n2==NULL)
    return false;
  if(n1->val !=n2->val)
    return false;
  return((isIsomorphic(n1->left, n2->left) && isIsomorphic(n1->right, n2->right))||(isIsomorphic(n1->left, n2->right)&& isIsomorphic(n1->right, n2->left)));
}

/*Maximum Path Sum in a Binary Tree
 * Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.*/
/*Idea is to keep track of 4 paths:
1. Node val
2. node+left path,
3. node+right path
4. node+left+right
Any of the above can be maximum*/

int maxSumPath(Node *root, int *max_sum)
{
  if(!root)
    return 0;
  int left=maxSumPath(root->left, max_sum);
  int right=maxSumPath(root->right, max_sum);
  int current_sum= max(root->val, max(left+root->val, right+root->val));
  *max_sum = max(*max_sum, max(current_sum, root->val+left+right));
  return current_sum;
}
/*Check whether binary tree is a complete tree or not. A complete binary tree is a binary tree whose all levels except the last level are completely filled and all the leaves in the last level are all to the left side.
 *index(root)=i, left=2*i+1, right=2*i+2, if any index>total nodes then its not a complete binary tree */

int countNodes(Node *root)
{
  if(!root)
    return 0;
  return (1+countNodes(root->left)+countNodes(root->right));
}
bool isCompleteBT(Node *root, int index, int total_nodes)
{
  if(!root)
    return true;
  if(index>=total_nodes)
    return false;
  return (isCompleteBT(root->left, 2*index+1, total_nodes) && isCompleteBT(root->right, 2*index+2, total_nodes));
}
/*Remove nodes on root to leaf paths of length < K*/
Node *removeNodes(Node *root, int len, int k)
{
  if(!root)
    return NULL;
  root->left=removeNodes(root->left, len+1, k);
  root->right=removeNodes(root->right, len+1, k);
  if(len<k && root->left==NULL && root->right==NULL)
  {
    printf("\n free root=%d len=%d",root->val, len);
    free(root);
    return NULL;
  }
  return root;
}

/*Remove all nodes which don’t lie in any path with sum>= k*/
Node *removeNodes2(Node *root, int sum)
{
  if(!root)
    return NULL;
  root->left=removeNodes2(root->left, sum-root->val);
  root->right=removeNodes2(root->right, sum-root->val);
  if(root->left==NULL && root->right==NULL)
  {
    if(root->val<sum){
    printf("\n free root=%d sum=%d",root->val, sum);
    free(root);
    return NULL;
   }
  }
  return root;
}
void TopDownSumHelper(Node *root, int *arr, int *count, int sum)
{
  if(!root)
    return;
  sum=sum*10+root->val;
  if(root->left==NULL && root->right==NULL)
  {
    *arr= *arr+sum;
    //(*count)++;
  }
  TopDownSumHelper(root->left, arr, count, sum);
  TopDownSumHelper(root->right,arr, count, sum);
}

int TopDownSum (Node* root) {
  if(!root)
    return 0;
 // int *arr = (int *)malloc(sizeof(int)*100);
  int count=0;int sum=0, arr=0;
  TopDownSumHelper(root,&arr, &count, 0);
 // for(int i=0;i<count;i++)
 // {
   // sum+=arr[i]; 
 // }
 // if(arr)
   // free(arr);
  return arr;

}
void printLevel(Node *root, int k)
{
  if(!root)
    return;
  if(k==0)
    printf("\n%d ",root->val);
  printLevel(root->left, k-1);
  printLevel(root->right, k-1);
}
void printKdistance(Node *root, int k)
{
  if(!root)
    return;
  int h = height(root);
  if(k>h)
    return;
  printLevel(root,k);
}
/*Find largest subtree having identical left and right subtrees*/
// do postorder of all the subtrees and store them in string and compare them if they are equal, if they are then update max tress size and max node
/*not working some issue with stings concat*/
int findLargestSubtree(Node *root, int *max, char *path, int curr, Node **node)
{
  if(root==NULL)
    return 0;
  static char *left = (char*)malloc(sizeof(char)*100);
  static char *right = (char*)malloc(sizeof(char)*100);
  int ls = findLargestSubtree(root->left, max, left, curr);
  char val[]={0,0};
  strcat(path,left);
  sprintf(val, "%d", root->val);
  strcat(path,val);
  int rs = findLargestSubtree(root->right, max, right, curr);
  strcat(path,left);
  sprintf(val, "%d", root->val);
  strcat(path,val);
  if(!strcmp(left, right))
  {
    if(size>*maxSize)
    {
      *maxSize=size;
      *node = root;
    }
  }
 return size;
}
/*Density of binary tree= size/height of tree. We can do 2 sparate traversals or 1 single traversal*/
int findDensityBT(Node *root, int *size)
{
  if(!root)
    return 0;
  int lh = findDensityBT(root->left, size);
  int rh = findDensityBT(root->right, size);
  *size = *size+1;
  return lh>rh?lh+1:rh+1;
}

/*Maximum difference between node and its ancestor in Binary Tree. Expected time complexity is O(n) because we are travelling tree only once*/
//Idea is to travel the tree bottom up so that we can get the least node value and max diffrence by the time we reach its parent node.

int maxDiff(Node *root, int *res)
{
  if(root==NULL)
    return INT_MAX; //not 0 because 0 can be diff value. Also we return min key node so Null won't be ever selected
  if(root->left==NULL && root->right==NULL)
    return root->val;
  int val = min(maxDiff(root->left, res), maxDiff(root->right, res));//get min key value for node to make diff max
  *res = max(*res, root->val-val);
  return min(val, root->val); /*keep track of minimum node reached so far. Diff will be max from ancestor with min child node*/
}

/*longest consecutive sequnce is increasing sequence*/
void longestConsecutiveUtil(Node* root, int *max, int pathlen, int target)
{
  if(root==NULL)
    return;
  if(root->val==target)
  {
    pathlen=pathlen+1;
    if(*max<pathlen)
      *max=pathlen;
  }
  else{
    pathlen=1;
  }
  longestConsecutiveUtil(root->left, max,pathlen, root->left->val+1);
  longestConsecutiveUtil(root->right, max,pathlen, root->right->val+1);
}
int longestConsecutive(Node* root) {
  if(root==NULL)
    return 0;
  int max=0;
  longestConsecutiveUtil(root, &max, 1, root->val+1);
  return max;
}
int main()
{
	int *arr = (int *)malloc(sizeof(int)*100);
	//Node *root = createBT();
  Node *root1 = createBT2();
  //Node *n2 = createBT3();
  int height=0;
  int max_sum=INT_MIN;
#if 0
  printPathBT(root,arr, 0);
  mirrorBT(root);
	printTree(root);
  int *column, returnSize=0;
  int **arr1 = levelOrder(root, &column, &returnSize);
	printf("\nisBST=%d", (int)isBSTUtil(root, INT_MIN, INT_MAX));
  pathSum2(root, 22);
  verticalorder(root);
  printf("%d ",checkSubtree(root, root1));
  printf("pathlen=%d\n", computePathSum(root1, 8));
  printf("\n diameter=%d\n",diameter(root1,&height)); 
  childSumPropBT(root1);
  char *data =serialize(root1);
  deserialize(data);
  if(data)
    free(data);
  printf("\n\n");
  int in[] = {2,3,4,5,6};
  int pre[] = {5,3,2,4,6};
  int idx=0;
  Node *root = cnstrctTreeInPre(in, pre, 0, 4,&idx);

  /* Let us test the built tree by printing Insorder traversal */
  printf("\nMax width of BT=%d\n", maxWidth(root1)); 
   printf("\nsum at root=%d\n", sumTree(root1)); 
  Node *tmp=NULL, *head=NULL;
  populateSuccessor(root1, &tmp, &head);
  printf("\n inorder successor\n");
  while(head!=NULL)
  {
    printf("%d ",head->val);
    head=head->next;
  }
  int in[] = {4, 2, 5, 1, 3, 6};
  int pre[] =  {1, 2, 4, 5, 3, 6};
  int n = sizeof(in)/sizeof(in[0]);
  printf("\nPostorder traversal\n");
  int pos=0;
  printPostOrder(in, pre,&pos, 0, n-1);
  int size=0;
  Node *max_leaf;
  int curr_sum=0;
  findMaxSumPath(root1, &max_sum, curr_sum, &max_leaf);
  printf("\n target=%d", max_leaf->val);
  printMaxPathSum(root1,max_leaf);
  printf("\n max_sum=%d\n",max_sum);
  convertBTDLL(root1);
  printf("Isomorphic= %d \n", isIsomorphic(root1, n2));
  maxSumPath(root1, &max_sum);
  printf("\n max sum path=%d\n", max_sum);
  int nodes=countNodes(root1);
  printf("\n Is a binary tree=%d nodes=%d\n", isCompleteBT(root1, 0, nodes), nodes);
  root1=removeNodes(root1, 1, 4);
  printf("sum=%d\n", TopDownSum(root1));
  root1 = removeNodes2(root1, 45);
  printf("\nPreorder traversal of the constructed tree is: root->val \n");
  preorder(root1);
  printKdistance(root1,2);
  int max =0;
  Node *n=NULL;
  char *str = (char*)malloc(sizeof(char)*1000);
  char *left = (char*)malloc(sizeof(char)*1000);
  char *right = (char*)malloc(sizeof(char)*1000);
  int s = findLargestSubtree(root1, &n, &max, str, left, right);
  printf("\n max=%d",max);
  int size=0;
  int h = findDensityBT(root1,&size);
  printf("\n density = %f",(double)size/h);
  int res=INT_MIN;
  maxDiff(root1, &res);
  printf("\n max diff of child node from ancestor=%d",res);
#endif
  printf("\nmaxlen=%d\n",longestConsecutive(root1));
  free(root1);
  return 0;
}
