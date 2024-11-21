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
	test_insertion_sort_string();
	test_insertion_sort_struct();
	printf("Все тесты были пройдены успешно.");
}

void test_insertion_sort_int(void) {

	srand(time(NULL));

	int random_size = rand() % 10 + 1;
	int* arr_int = malloc(sizeof(int) * random_size);

	if (arr_int == NULL) {
		printf("Память не была выделена для массива целых чисел.\n");
		exit(1);
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
	char* arr_char = malloc(sizeof(char) * (random_size + 1));

	if (arr_char == NULL) {
		printf("Память не была выделена.");
		abort();
	}

	for (int i = 0; i < random_size; i++) {
		arr_char[i] = 'A' + rand() % 58;
	}

	arr_char[random_size] = '\0';

	size_t len = random_size;

	insertion_sort(arr_char, len, sizeof(arr_char[0]), compare_char);

	for (int i = 0; i < random_size - 1; i++) {
		assert(arr_char[i] <= arr_char[i + 1]);
	}

	free(arr_char);
}

void test_insertion_sort_string(void) {

	size_t random_lenght = rand() % 50 + 1;
	size_t random_size = rand() % 10 + 1;

	char** arr_string = malloc(sizeof(char*) * random_size);

	if (arr_string == NULL) {
		printf("Ошибка выделения памяти");
		abort();
	}

	for (int i = 0; i < random_size; i++) {
		arr_string[i] = malloc(sizeof(char) * random_lenght);
		if (arr_string[i] == NULL) {
			printf("Ошибка выделения памяти\n");
			abort();
		}
	}


	for (int i = 0; i < random_size; ++i) {
		for (int j = 0; j < random_lenght  - 1; ++j) {
			arr_string[i][j] = 'A' + rand() % 58;
		}
		arr_string[i][random_lenght - 1] = '\0';
	}


	insertion_sort(arr_string, random_size, sizeof(arr_string[0]), compare_string_v2);

	for (int i = 0; i < random_size - 1; i++) {
		assert(arr_string[i][0] <= arr_string[i + 1][0]);
	}

	for (int i = 0; i < random_size; ++i)
		free(arr_string[i]);
	free(arr_string);
}


void test_insertion_sort_struct(void) {

	int random_quantity = rand() % 10 + 1;

	INFO* persons = malloc(sizeof(INFO) * random_quantity);

	if (persons == NULL) {
		printf("Память не была выделена.");
		abort();
	}

	for (int i = 0; i < random_quantity; ++i) {
		for (int j = 0; j < 25 - 1; ++j) {
			persons[i].last_name[j] = 'A' + rand() % 56 + 1;
			persons[i].first_name[j] = 'A' + rand() % 56 + 1;
		}
		persons[i].sex = rand() % 2 + 1 == 1 ? 'M' : 'W';
		persons[i].old = rand() % 100 + 1;
		persons[i].last_name[24] = '\0';
		persons[i].first_name[24] = '\0';
	}
	
	insertion_sort(persons, random_quantity, sizeof(persons[0]), compare_person_v2);

	for (int i = 0; i < random_quantity - 1; ++i) {
		assert(persons[i].last_name[0] <= persons[i + 1].last_name[0]);
	}

	free(persons);
}