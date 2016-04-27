#ifndef __HASHMAP_H__
#define __HASHMAP_H__

typedef struct map
{
	int key;
	int value;
}Map;
typedef struct HashMap{
	Map *table;
	int size;
	int count;
}hashmap;

hashmap *create_map(int size)
{
	hashmap *hm = (hashmap *)malloc(sizeof(hashmap));
	hm->size = size;
	hm->count=0;
	hm->table = (Map *)malloc(sizeof(Map)*size);
	return hm;
}
void map_put(hashmap *hm, int key, int value)
{
	Map *m = (Map *)malloc(sizeof(Map));
	m->key = key;
	m->value= value;
	hm->table[count++]=m;
}
/*This is O(n) need to implement it using hashcode*/
bool map_containsKey(hashmap *hm, int key)
{
	if(count==0 || size==0)
	  return false;
	int i=0;
	for(i=0;i<hm->count; i++)
	{
		if(hm->table[i]->key == key)
		   return true;
	}	
	return false;
}
#endif
