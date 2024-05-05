#pragma once
#include <stdlib.h>

int *get_random_table_for(int min, int max, int size) {
    int *table;
    table = (int *) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        table[i] = rand() % (max - min + 1) + min;
    }

    return table;
}

int *get_random_table(int size) {
    return get_random_table_for(-999999, 999999, size) ;
}