#include <stdio.h>
#include <time.h>

#include "test_sort.c"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"


struct Time{
    int hours, minutes, seconds;
    long nanoseconds;
};

struct Time get_time(long time_taken){
    double seconds_total = (double) time_taken / 1e9;
    struct Time time;
    time.hours = (int) (seconds_total / 3600);
    seconds_total -= time.hours * 3600;
    time.minutes = (int) (seconds_total / 60);
    seconds_total -= time.minutes * 60;
    time.seconds = (int) seconds_total;
    seconds_total -= time.seconds;
    time.nanoseconds = (int) (seconds_total * 1e9);
    return time;
}

char *time_to_string(struct Time time){
    char *time_str = malloc(30 * sizeof(char));
    sprintf(time_str, "%02d:%02d:%02d.%09ld", time.hours, time.minutes, time.seconds, time.nanoseconds);
    return time_str;
}

long diff(struct timespec start, struct timespec end) {
    long diff = (end.tv_sec -start.tv_sec) * (long)1e9;
    diff += end.tv_nsec - start.tv_nsec;
    return diff;
}

void run_int_func_with_str(int (*func_to_run)(), char *test_name) {
    struct timespec t_start, t_end;
    clock_gettime(CLOCK_MONOTONIC, &t_start);
    int result = func_to_run();
    clock_gettime(CLOCK_MONOTONIC, &t_end);
    struct Time time = get_time(diff(t_start, t_end));

    if (result) {
        printf(GREEN "Test <%s> PASSED; Time taken: %s\n" RESET, test_name, time_to_string(time));
    } else {
        printf(RED "Test <%s> FAILED\n" RESET, test_name);
    }
}

int main() {
    run_int_func_with_str(test_insertion_sort, "Test Insert Sort");
    run_int_func_with_str(test_selection_sort, "Test Select Sort");
    run_int_func_with_str(test_bubble_sort, "Test Bubble Sort");
    run_int_func_with_str(test_quick_sort, "Test Quick Sort");
    run_int_func_with_str(test_shell_sort, "Test Shell Sort");
    run_int_func_with_str(test_heap_sort, "Test Heap Sort");
    return 0;
}