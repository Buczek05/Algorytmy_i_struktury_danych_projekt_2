void bubble_sort(int *table, int size) {
    int i, j, temp, was_change = 1;

    for (j = 0; j < size - 1 && was_change; j++) {
        was_change = 0;

        for (i = size - 2; i >= j; i--) {
            if (table[i] > table[i + 1]) {
                temp = table[i];
                table[i] = table[i + 1];
                table[i + 1] = temp;
                was_change = 1;
            }
        }
    }
}