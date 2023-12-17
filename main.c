#include <stdio.h>
#include <stdlib.h>

struct BinHeap {
    int size;
    // If priority is 0 that means it's a min heap, other values indicate max heap
    int priority;
    int elements[25];
};

typedef struct BinHeap BinHeap;

void build_heap (BinHeap *heap, int index) {
    if (index > heap->size || index < 2) {
        return;
    }
    else {
        if (heap->priority == 0) {
            if (heap->elements[index] < heap->elements[index / 2]) {
                int temp = heap->elements[index / 2];
                heap->elements[index / 2] = heap->elements[index];
                heap->elements[index] = temp;

                build_heap(heap, index*2);
            }
            if (heap->elements[index - 1] < heap->elements[index / 2]) {
                int temp = heap->elements[index / 2];
                heap->elements[index / 2] = heap->elements[index - 1];
                heap->elements[index - 1] = temp;
                build_heap(heap, index*2);
            }
            build_heap(heap, index - 2);
        }
        else {
            if (heap->elements[index] > heap->elements[index / 2]) {
                int temp = heap->elements[index / 2];
                heap->elements[index / 2] = heap->elements[index];
                heap->elements[index] = temp;

                build_heap(heap, index*2);
            }
            if (heap->elements[index - 1] > heap->elements[index / 2]) {
                int temp = heap->elements[index / 2];
                heap->elements[index / 2] = heap->elements[index - 1];
                heap->elements[index - 1] = temp;
                build_heap(heap, index*2);
            }
            build_heap(heap, index - 2);
        }

    }
}

void delete_root(BinHeap *heap) {

    if (heap->size == 1) {
        heap->size--;
        heap->elements[1] = 0;
        return;
    }

    int last_key = heap->elements[heap->size];

    if (heap->priority == 0) {
        int i;

        for (i = 1; i * 2 <= heap->size; ) {
            if (heap->elements[i * 2] < heap->elements[i * 2 + 1]) {
                heap->elements[i] = heap->elements[i * 2];
                i = i * 2;
            }
            else {
                heap->elements[i] = heap->elements[i * 2 + 1];
                i = i * 2 + 1;
            }
        }

        heap->elements[i] = last_key;
        heap->size--;
    }
    else {
        int i;

        for (i = 1; i * 2 <= heap->size; ) {
            if (heap->elements[i * 2] > heap->elements[i * 2 + 1]) {
                heap->elements[i] = heap->elements[i * 2];
                i = i * 2;
            }
            else {
                heap->elements[i] = heap->elements[i * 2 + 1];
                i = i * 2 + 1;
            }
        }

        heap->elements[i] = last_key;
        heap->size--;
    }
}

void insert (BinHeap *heap, int key) {
    if (heap->size == 0) {
        heap->elements[1] = key;
        heap->size++;
    }
    else {
        heap->size++;
        heap->elements[heap->size] = key;

        int i;
        int last = heap->size;

        for (i = last / 2; i >= 0; i = i / 2) {
            if (heap->priority == 0) {
                if (heap->elements[i] > heap->elements[last]) {
                    int temp = heap->elements[i];
                    heap->elements[i] = heap->elements[last];
                    heap->elements[last] = temp;
                    last = last / 2;
                }
                else {
                    break;
                }
            }
            else {
                if (heap->elements[i] < heap->elements[last]) {
                    int temp = heap->elements[i];
                    heap->elements[i] = heap->elements[last];
                    heap->elements[last] = temp;
                }
                else {
                    break;
                }
            }
        }
    }
}
void print_tree(BinHeap *heap) {
    int i;

    for(i = 1; i <= heap->size; i++) {
        printf("%d ", heap->elements[i]);
    }

}

int main() {

    BinHeap *heap = malloc(sizeof(BinHeap));
    // You can use arbitrary heap sizes but don't forget to change the int elements[<size>] statement
    // in the struct BinHeap at first part of the code
    heap->size = 19;
    heap->priority = 0;
    heap->elements[0] = 0;

    int i;

    // Also you can change the iteration time as you want to scan how many elements through console
    for (i = 1; i <= 19; i++) {
        int key;
        scanf("%d", &key);
        heap->elements[i] = key;
    }

    // You can change the function used
    build_heap(heap, 19);
    // This will remain as it is because it will print the heap->elements property
    print_tree(heap);
    return 0;
}
