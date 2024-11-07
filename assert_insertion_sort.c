#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "insertion_sort.h"
#include "person_information.h"
#include "assert_insertion_sort.h"


void run_all_tests(void) {
	test_insertion_sort_int();
	test_insertion_sort_float();
	test_insertion_sort_char();

}

void test_insertion_sort_int(void) {

	srand(time(NULL));

	int random_size = rand() % 10 + 1;
	int* arr_int = malloc(sizeof(int) * random_size);

	if (arr_int == NULL) {
		printf("Память не была выделена.");
		abort();
	}

	for (int i = 0; i < random_size; i++) {
		arr_int[i] = rand() % 50;
	}
	
	size_t len = random_size;

	insertion_sort(arr_int, len, sizeof(arr_int[0]), compare_int);

	for (int i = 0; i < random_size - 1; i++) {
		assert(arr_int[i] <= arr_int[i + 1]);
	}
	
	free(arr_int);
}

void test_insertion_sort_float(void) {
	int random_size = rand() % 10 + 1;
	float* arr_float = malloc(sizeof(float) * random_size);

	if (arr_float == NULL) {
		printf("Память не была выделена.");
		abort();
	}

	for (int i = 0; i < random_size; i++) {
		arr_float[i] = (rand() % 50 - 50) / (rand() % 70 - 70);
	}

	size_t len = random_size;

	insertion_sort(arr_float, len, sizeof(arr_float[0]), compare_float);

	for (int i = 0; i < random_size - 1; i++) {
		assert(arr_float[i] <= arr_float[i + 1]);
	}

	free(arr_float);
}

void test_insertion_sort_char(void) {
	int random_size = rand() % 50 + 1;
	char* arr_float = malloc(sizeof(float) * random_size);

	if (arr_float == NULL) {
		printf("Память не была выделена.");
		abort();
	}

	for (int i = 0; i < random_size; i++) {
		arr_float[i] = ;
	}
}