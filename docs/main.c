#include <time.h>
#include <stdio.h>
#include "../helpers/random.c"
#include "../sort/insertion_sort.c"
#include "../sort/selection_sort.c"
#include "../sort/bubble_sort.c"
#include "../sort/quick_sort.c"
#include "../sort/shell_sort.c"
#include "../sort/heap_sort.c"

struct Result {
    long time_taken;
    int table_size;
};

char func_names[][20] = {"Insert Sort", "Selection Sort", "Bubble Sort", "Quick Sort", "Shell Sort", "Heap Sort"};
void (*sort_funcs[6])(int *, int) = {insertion_sort, selection_sort, bubble_sort, quick_sort, shell_sort, heap_sort};
int func_count = 6;

void save_result(FILE *file, struct Result *result) {
    fprintf(file, "%d;%ld\n", result->table_size, result->time_taken);
}

long diff(struct timespec start, struct timespec end) {
    long diff = (end.tv_sec - start.tv_sec) * (long) 1e9;
    diff += end.tv_nsec - start.tv_nsec;
    return diff;
}

void check_result(void (*sort_function)(int *, int), FILE *file, int *table, int size) {
    struct timespec t_start, t_end;

    clock_gettime(CLOCK_MONOTONIC, &t_start);
    sort_function(table, size);
    clock_gettime(CLOCK_MONOTONIC, &t_end);

    struct Result result;
    result.time_taken = diff(t_start, t_end);;
    result.table_size = size;
    save_result(file, &result);
}

FILE *get_file(char *file_name, char *mode){
    FILE *file = fopen(file_name, "w");
    if (!file){
        printf("Can't open file %s\n", file_name);
        exit(1);
    }
    return file;
}

void reverse_table(int *table, int size){
    for (int i = 0; i < size / 2; i++) {
        int temp = table[i];
        table[i] = table[size - i - 1];
        table[size - i - 1] = temp;
    }
}

void run_all_test(int max_size) {
    for (int i = 0; i < func_count; i++){
        printf("\n\nTest for %s\n", func_names[i]);
        char file_name_test_1[30], file_name_test_2[30], file_name_test_3[30];
        sprintf(file_name_test_1, "result/test_1-%s", func_names[i]);
        sprintf(file_name_test_2, "result/test_2-%s", func_names[i]);
        sprintf(file_name_test_3, "result/test_3-%s", func_names[i]);
        FILE *file_test_1 = get_file(file_name_test_1, "w");
        FILE *file_test_2 = get_file(file_name_test_2, "w");
        FILE *file_test_3 = get_file(file_name_test_3, "w");
        for (int j = 100; j < max_size; j += 100){
            printf("Sorting %d elements list\n", j);
            int *table = get_random_table(j);
            check_result(sort_funcs[i], file_test_1, table, j);
            reverse_table(table, j);
            check_result(sort_funcs[i], file_test_2, table, j);
            check_result(sort_funcs[i], file_test_3, table, j);
        }
        fclose(file_test_1);
        fclose(file_test_2);
        fclose(file_test_3);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please supply the max size parameter.\n");
        return 1;
    }
    int max_size = atoi(argv[1]);
    run_all_test(max_size);
    return 0;
}