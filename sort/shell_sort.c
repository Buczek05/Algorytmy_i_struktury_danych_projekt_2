void shell_sort(int table[], int size) {
    int i, j, interval, temp;

    for (interval = size / 2; interval > 0; interval /= 2) {
        for (i = interval; i < size; i += 1) {
            temp = table[i];

            for (j = i; j >= interval && table[j - interval] > temp; j -= interval) {
                table[j] = table[j - interval];
            }

            table[j] = temp;
        }
    }
}