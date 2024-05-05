void selection_sort(int table[], int size) {
    int i, j, min_index, temp;

    for (i = 0; i < size - 1; i++) {
        min_index = i;

        for (j = i + 1; j < size; j++) {
            if (table[j] < table[min_index]) {
                min_index = j;
            }
        }

        temp = table[i];
        table[i] = table[min_index];
        table[min_index] = temp;
    }
}