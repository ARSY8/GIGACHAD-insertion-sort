#pragma once
#include <stddef.h>

void run_all_tests(void);
void test_insertion_sort_int(void);
void test_insertion_sort_float(void);
void test_insertion_sort_char(void);
void test_insertion_sort_string(void);
void test_insertion_sort_struct(void);

int compare_int(void* a, void* b);
int compare_float(void* a, void* b);
int compare_char(void* a, void* b);
int compare_string_v1(void* a, void* b);
int compare_string_v2(void* a, void* b);
int compare_person_v1(void* a, void* b);
int compare_person_v2(void* a, void* b);

void swap(void* a, void* b, size_t size);
void swap_memcpy(void* a, void* b, size_t size);