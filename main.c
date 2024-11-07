#include <stdio.h>
#include "insertion_sort.h"
#include "person_information.h"
#include "assert_insertion_sort.h"
#define compare_string compare_char


int main(void) {

	int int_arr[] = { 123481, 12412, 6453, 2274, 22782 };
	float float_arr[] = { 3.14, -1.5, 0, 2.71, -8.25, 5.5 };
	char char_arr[] = "Hello World";
	char string_arr[][25] = { "hello world", "Hello", "My name", "is Arseniy, and I", "love exploring new", "technologies." };

	INFO persons[] = {
		{"Yudintsev", "Arseniy", 'M', 18},
		{"Guseynov", "Amir", 'M', 19},
		{"Popov", "Maxim", 'M', 19},
		{"Peshne", "Elizabeth", 'W', 19},
		{"Romanov", "Semen", 'M', 19}
	};

	run_all_tests();

	char data_type = '[';

	int (*compare[])(void*, void*) = { compare_int, compare_float, compare_char, compare_string, compare_person };

	if (data_type == 'i') {
		size_t size_in_bytes = sizeof(int);
		int len = sizeof(int_arr) / sizeof(int_arr[0]);
		insertion_sort(int_arr, len, size_in_bytes, compare[0]);
		for (int i = 0; i < len; ++i) {
			printf("%d ", int_arr[i]);
		}
	}
	else if (data_type == 'f') {
		size_t size_in_bytes = sizeof(float);
		int len = sizeof(float_arr) / sizeof(float_arr[0]);
		insertion_sort(float_arr, len, size_in_bytes, compare[1]);
		for (int i = 0; i < len; ++i) {
			printf("%.2f ", float_arr[i]);
		}
	}
	else if (data_type == 'c') {
		size_t size_in_bytes = sizeof(char);
		int len = sizeof(char_arr) / sizeof(char_arr[0]);
		insertion_sort(char_arr, len, size_in_bytes, compare[2]);
		for (int i = 0; i < len; ++i) {
			printf("%c ", char_arr[i]);
		}
	}
	else if (data_type == 's') {
		size_t size_in_bytes = sizeof(string_arr[0]);
		int len = sizeof(string_arr) / sizeof(string_arr[0]);
		insertion_sort(string_arr, len, size_in_bytes, compare[3]);
		for (int i = 0; i < len; ++i) {
			printf("%s\n", string_arr[i]);
		}
	}
	else if (data_type == 'p') {
		size_t size_in_bytes = sizeof(persons[0]);
		int len = sizeof(persons) / sizeof(persons[0]);
		insertion_sort(persons, len, size_in_bytes, compare[4]);
		for (int i = 0; i < len; ++i) {
			printf("Фамилия: %s, ", persons[i].last_name);
			printf("Имя: %s, ", persons[i].first_name);
			printf("Пол: %c, ", persons[i].sex);
			printf("Возраст: %i.\n", persons[i].old);
		}
	}
	else {
	}
	return 0;
}


int compare_char(void* a, void* b) {
	return *(char*)a < *(char*)b ? -1 : 0;
}

int compare_int(void* a, void* b) {
	return *(int*)a < *(int*)b ? -1 : 0;
}

int compare_float(void* a, void* b) {
	return *(float*)a < *(float*)b ? -1 : 0;
}

int compare_person(void* a, void* b) {
	return ((INFO*)a)->last_name[0] < ((INFO*)b)->last_name[0] ? -1 : 0;
}