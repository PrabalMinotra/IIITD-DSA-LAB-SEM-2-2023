// NOTE :- It is mandatory to implement a Heap from scratch.

// There are 𝑁
//  different type of items in a store.

// Given an array 𝑛𝑢𝑚𝑠
// , where 𝑎𝑖
//  represents the number of items of 𝑖𝑡ℎ
//  type. You need to sell 𝐾
//  items in total.

// Each 𝑖𝑡ℎ
//  type item costs equal to the number of 𝑖𝑡ℎ
//  type items left at that point. You can sell the items in any order you like, The task is to maximize the amount earned by selling 𝐾
//  items.

// Note: 𝐾
//  can be more than the total items present in the store. See second sample test case.

// Input
// The first line contains the integer 𝑁
//  (1 ≤ 𝑁 ≤ 10^5) and 𝐾
//  (1 ≤ 𝐾 ≤ 5×10^5).

// The next line contains 𝑁
//  spaced integers, 𝑖𝑡ℎ
//  element denoting the number of items of 𝑖𝑡ℎ
//  type.

// (1 ≤ 𝑛𝑢𝑚𝑠[𝑖] ≤ 10^9)

// Output
// Print the maximum amount you can earn.

// Examples
// inputCopy
// 2 3
// 2 3
// outputCopy
// 7

#include <stdio.h>
#include <stdlib.h>

struct Item {
int type;
int quantity;
};

struct MaxHeap {
struct Item* items;
int capacity;
int size;
};


void swap(struct Item* a, struct Item* b);
struct MaxHeap* createMaxHeap(int capacity);
void heapify(struct MaxHeap* heap, int index);
void insert(struct MaxHeap* heap, struct Item item);
struct Item extractMax(struct MaxHeap* heap);
long long calculateMaxAmount(int N, int K, int* nums);


int main() {
int N;
int K;
scanf("%d %d", &N, &K);

int* nums = (int*)malloc(N * sizeof(int));

for (int i = 0; i < N; i++)
scanf("%d", &nums[i]);

long long earning = calculateMaxAmount(N, K, nums);
printf("%lld\n", earning);

free(nums);

return 0;
}


void swap(struct Item* a, struct Item* b) {
struct Item t = *a;
*a = *b;
*b = t;
}

struct MaxHeap* createMaxHeap(int capacity) {
struct MaxHeap* heap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
heap->capacity = capacity;
heap->size = 0;
heap->items = (struct Item*)malloc(capacity * sizeof(struct Item));
return heap;
}

void heapify(struct MaxHeap* heap, int index) {
int largest = index;
int left = 2 * index + 1;
int right = 2 * index + 2;

if (left < heap->size && heap->items[left].quantity > heap->items[largest].quantity)
largest = left;

if (right < heap->size && heap->items[right].quantity > heap->items[largest].quantity)
largest = right;

if (largest != index) {
swap(&heap->items[index], &heap->items[largest]);
heapify(heap, largest);
}
}

void insert(struct MaxHeap* heap, struct Item item) {
if (heap->size == heap->capacity)
return;

int index = heap->size;
heap->items[index] = item;

while (index > 0 && heap->items[(index - 1) / 2].quantity < heap->items[index].quantity) {
swap(&heap->items[index], &heap->items[(index - 1) / 2]);
index = (index - 1) / 2;
}

heap->size++;
}

struct Item extractMax(struct MaxHeap* heap) {
struct Item maxItem = heap->items[0];
heap->items[0] = heap->items[heap->size - 1];
heap->size--;
heapify(heap, 0);
return maxItem;
}

long long calculateMaxAmount(int N, int K, int* nums) {
struct MaxHeap* heap = createMaxHeap(N);

for (int i = 0; i < N; i++) {
struct Item item;
item.type = i + 1;
item.quantity = nums[i];
insert(heap, item);
}

long long maxAmount = 0;

for (int i = 0; i < K && heap->size > 0; i++) {
struct Item maxItem = extractMax(heap);
maxAmount += maxItem.quantity;
if (maxItem.quantity > 1) {
maxItem.quantity--;
insert(heap, maxItem);
}
}

free(heap->items);
free(heap);

return maxAmount;
}