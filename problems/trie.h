#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define ALPHA_SIZE 26
typedef struct TrieNode{
  struct TrieNode *children[ALPHA_SIZE];
  bool isLeaf;
}TrieNode;

void insert(TrieNode *root, char *key);
bool searchKey(TrieNode *root, char *key);
TrieNode *createNode(void);

TrieNode *createNode(void)
{
  TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
  int i=0;
  if(node)
  { node->isLeaf=false;
    for(i=0;i<ALPHA_SIZE;i++)
      node->children[i]=NULL;
  }
  return node;
}
void insert(TrieNode *root, char *key){

  if(!root|| !key)
    return;
  int i=0, idx=0;
  TrieNode *tmp=root;
  for(i=0;i<strlen(key);i++)
  {
    idx=(int)key[i] - (int)'a';
    if(!tmp->children[idx])
      tmp->children[idx]=createNode();
    tmp=tmp->children[idx];
  }
  tmp->isLeaf=true;
}

bool searchKey(TrieNode *root, char *key)
{
  if(!root || !key)
    return false;
  int i=0, idx=0;
  TrieNode *tmp=root;
  for(i=0;i<strlen(key);i++)
  {
    idx = (int)key[i] - (int)'a';
    if(!tmp->children[idx])
      return false;
    tmp=tmp->children[idx];
  } 
  return (tmp!=NULL && tmp->isLeaf);
}

