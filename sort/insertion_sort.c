void insertion_sort(int *table, int size) {
    int i, j, temp;

    for (i = 1; i < size; i++) {
        temp = table[i];
        j = i - 1;

        while (j >= 0 && table[j] > temp) {
            table[j + 1] = table[j];
            j--;
        }

        table[j + 1] = temp;
    }
}
