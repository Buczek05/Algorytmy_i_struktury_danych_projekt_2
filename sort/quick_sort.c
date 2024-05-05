#include "../helpers/swap.c"

int partition(int table[], int low, int high)
{
    int pivot = table[high];

    int i = (low - 1);

    for (int j = low; j <= high; j++) {
        if (table[j] < pivot) {
            i++;
            swap(&table[i], &table[j]);
        }
    }
    swap(&table[i + 1], &table[high]);
    return (i + 1);
}

void quick_sort_with_indices(int table[], int low, int high)
{
    if (low < high) {
        int pi = partition(table, low, high);
        quick_sort_with_indices(table, low, pi - 1);
        quick_sort_with_indices(table, pi + 1, high);
    }
}

void quick_sort(int table[], int size){
    quick_sort_with_indices(table, 0, size - 1);
}
