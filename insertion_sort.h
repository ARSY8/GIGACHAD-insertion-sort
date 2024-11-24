#pragma once
#include <stddef.h>

void insertion_sort(void* arr, int len, size_t size_in_bytes, int (*compare)(void*, void*));

