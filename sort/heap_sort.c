#include "../helpers/swap.c"

void heapify(int table[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && table[left] > table[largest])
        largest = left;

    if (right < size && table[right] > table[largest])
        largest = right;

    if (largest != i) {
        swap(&table[i], &table[largest]);
        heapify(table, size, largest);
    }
}

void heap_sort(int table[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(table, size, i);

    for (int i = size - 1; i >= 0; i--) {
        swap(&table[0], &table[i]);
        heapify(table, i, 0);
    }
}