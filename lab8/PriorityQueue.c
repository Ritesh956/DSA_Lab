#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void initHeap(MinHeap* heap);
int isEmpty(MinHeap* heap);
int isFull(MinHeap* heap);
void insert(MinHeap* heap, int value);
int deleteMin(MinHeap* heap);
void heapifyUp(MinHeap* heap, int index);
void heapifyDown(MinHeap* heap, int index);
void printHeap(MinHeap* heap);

void initHeap(MinHeap* heap) {
    heap->size = 0;
}

int isEmpty(MinHeap* heap) {
    return heap->size == 0;
}

int isFull(MinHeap* heap) {
    return heap->size == MAX_SIZE;
}

void insert(MinHeap* heap, int value) {
    if (isFull(heap)) {
        printf("Heap is full\n");
        return;
    }

    int index = heap->size++;
    heap->data[index] = value;

    heapifyUp(heap, index);
}

void heapifyUp(MinHeap* heap, int index) {
    int parentIndex;
    while (index > 0) {
        parentIndex = (index - 1) / 2;
        if (heap->data[index] < heap->data[parentIndex]) {
            int temp = heap->data[index];
            heap->data[index] = heap->data[parentIndex];
            heap->data[parentIndex] = temp;
            index = parentIndex;
        } else {
            break;
        }
    }
}

int deleteMin(MinHeap* heap) {
    if (isEmpty(heap)) {
        printf("Heap is empty\n");
        return -1;
    }

    int minValue = heap->data[0];

    heap->data[0] = heap->data[--heap->size];

    heapifyDown(heap, 0);
    return minValue;
}

void heapifyDown(MinHeap* heap, int index) {
    int leftChild, rightChild, smallest, size = heap->size;
    while (index < size) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        smallest = index;
        
        if (leftChild < size && heap->data[leftChild] < heap->data[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && heap->data[rightChild] < heap->data[smallest]) {
            smallest = rightChild;
        }
        if (smallest != index) {

            int temp = heap->data[index];
            heap->data[index] = heap->data[smallest];
            heap->data[smallest] = temp;

            index = smallest;
        } else {
            break;
        }
    }
}

void printHeap(MinHeap* heap) {
    if (isEmpty(heap)) {
        printf("Heap is empty\n");
        return;
    }
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    MinHeap heap;
    initHeap(&heap);

    insert(&heap, 5);
    insert(&heap, 3);
    insert(&heap, 8);
    insert(&heap, 1);
    insert(&heap, 7);

    printf("Heap: ");
    printHeap(&heap);

    printf("Removed min: %d\n", deleteMin(&heap));
    printf("Heap after removing min: ");
    printHeap(&heap);

    return 0;
}
