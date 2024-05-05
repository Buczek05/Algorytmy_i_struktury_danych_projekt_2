void selection_sort(int table[], int size) {
    int i, j, minIndex, temp;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < size; j++) {
            if (table[j] < table[minIndex]) {
                minIndex = j;
            }
        }

        temp = table[i];
        table[i] = table[minIndex];
        table[minIndex] = temp;
    }
}