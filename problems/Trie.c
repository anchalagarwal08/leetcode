#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

int main()
{
  char keys[][8] = {"the", "a", "there", "answer", "any",
    "by", "bye", "their"};
  char output[][32] = {"Not present in trie", "Present in trie"};
  struct TrieNode *root = createNode();
  int i;
  for (i = 0; i < ARRAY_SIZE(keys); i++)
    insert(root, keys[i]);
 printf("%s --- %s\n", "the", output[searchKey(root, "the")] );
  printf("%s --- %s\n", "these", output[searchKey(root, "these")] );
  printf("%s --- %s\n", "their", output[searchKey(root, "their")] );
  printf("%s --- %s\n", "thaw", output[searchKey(root, "thaw")] );
  return 0;

}
