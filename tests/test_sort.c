#include <stdlib.h>
#include <time.h>
#include "../helpers/random.c"
#include "../sort/insertion_sort.c"
#include "../sort/selection_sort.c"
#include "../sort/bubble_sort.c"
#include "../sort/quick_sort.c"
#include "../sort/shell_sort.c"
#include "../sort/heap_sort.c"

int is_table_sorted(const int *table, int size){
    if (table == NULL) return 0;
    for (int i = 1; i < size; i++){
        if (table[i-1] > table[i]) return 0;
    }
    return 1;
}

int test_sorting(void (*sort_function)(int *, int)){
    for (int i = 0; i < 1000; i++){
        int size = rand() % (1000);
        int *table = get_random_table(size);
        sort_function(table, size);
        int result = is_table_sorted(table, size);
        free(table);
        if (!result) return 0;
    }
    return 1;
}

int test_insertion_sort(){
    return test_sorting(insertion_sort);
}

int test_selection_sort(){
    return test_sorting(selection_sort);
}

int test_bubble_sort(){
    return test_sorting(bubble_sort);
}

int test_quick_sort(){
    return test_sorting(quick_sort);
}

int test_shell_sort(){
    return test_sorting(shell_sort);
}

int test_heap_sort(){
    return test_sorting(heap_sort);
}