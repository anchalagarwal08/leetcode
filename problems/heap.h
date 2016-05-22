
typedef struct HeapNode{
  int elem;
  int arr_idx;
  int nxt_idx;
}HeapNode;

typedef struct MaxHeap{
  int *arr;
  int size;
  int capacity;
  HeapNode **nodes;
}maxheap;

maxheap* createHeap(int capacity);
int extractMax(maxheap *h);
int extractMin(maxheap *h);
int parent(int i);
void swap(int *x, int *y);
void insertHeap(maxheap *h, int val);
void insertMinHeap(maxheap *h, int val);
void maxHeapify(maxheap *h, int i);
void minHeapify(maxheap *h, int i);
maxheap* createHeap(int capacity)
{
  maxheap *h = (maxheap*)malloc(sizeof(maxheap));
  h->arr = (int *)malloc(sizeof(int)*capacity);
  h->size=0;
  h->capacity= capacity;
  h->nodes=NULL;
  return h;
}
int parent(int i)
{
  return (i-1)/2;
}
void swap(int *x, int *y)
{
  int tmp = *x;
  *x=*y;
  *y=tmp;
}
void insertHeap(maxheap *h, int val)
{
  if(h->capacity==h->size)
    return;
  h->arr[h->size]=val;
  (h->size)++;
  int i=(h->size)-1;
  while(i!=0 && h->arr[parent(i)]<h->arr[i])
  {
    swap(&h->arr[parent(i)],&h->arr[i]);
    i=parent(i);
  }
}

void insertMinHeap(maxheap *h, int val)
{
  if(h->capacity == h->size)
    return;
  h->arr[h->size]=val;
  (h->size)++;
  int i =h->size -i;
  while(i!=0 && h->arr[parent(i)]>h->arr[i])
  {
    swap(&h->arr[parent(i)], &h->arr[i]);
    i = parent(i);
  }

}

void maxHeapify(maxheap *h, int i)
{
  int l=2*i+1;
  int r=2*i+2;
  int largest=i;
  if(l< h->size && h->arr[i]< h->arr[l])
    largest=l;
  if(r< h->size && h->arr[largest]< h->arr[r])
    largest=r;
  if(largest!=i)
  {
    swap(&h->arr[largest], &h->arr[i]);
    maxHeapify(h,largest);
  }

}

void minHeapify(maxheap *h, int i)
{
  int l = 2*i+1;
  int r = 2*i+2;
  int smallest =i;
  if(h->arr[l]<h->arr[i])
    smallest = l;
  if(h->arr[r]<h->arr[smallest])
    smallest =r;
  if(smallest!=i)
  {
    swap(&h->arr[smallest], &h->arr[i]);
    minHeapify(h, smallest);
  }


}
int extractMax(maxheap *h)
{
  int root = h->arr[0];
  h->arr[0]=h->arr[(h->size)-1];
  h->size = h->size - 1;
  maxHeapify(h,0);
  return root;
}
int extractMin(maxheap *h)
{
  int root = h->arr[0];
  h->arr[0]=h->arr[h->size-1];
  (h->size)--;
  minHeapify(h, 0);
  return root;
}
/*Complexity:
 * heap creation: O(n)
 * insert: O(log n)
 * delete: O(log n)
 * Heapify: O(log n)
 * kth largest: O(n+klogn)*/
int findKthLargest(int* nums, int numsSize, int k) {
  maxheap *h = createHeap(numsSize);
  int i=0,j=0, val=0;
  for(i=0;i<numsSize;i++)
  {
    insertHeap(h, nums[i]);
  }
  for(j=0;j<k;j++)
  {
    val = extractMax(h);
  }
  return val;
}
