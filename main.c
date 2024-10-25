#include <stdio.h>
#include "insertion_sort.h"
#define compare_string compare_char

int main(void) {

	int int_arr[] = { -5, 7, -2, 10, 5, -3, 9, 8 };
	float float_arr[] = { 3.14, -1.5, 0, 2.71, -8.25, 5.5 };
	char char_arr[] = "Hello World";
	char string_arr[][25] = { "hello world", "Hello", "My name", "is Arseniy, and I", "love exploring new", "technologies." };

	INFO persons[] = {
		{"Yudintsev", "Arseniy", 'M', 18},
		{"Guseynov", "Amir", 'M', 19},
		{"Popov", "Maxim", 'M', 19},
		{"Gulyaev", "Nikolay", 'M', 19},
		{"Peshne", "Elizabeth", 'W', 19},
		{"Romanov", "Semen", 'M', 19}
	};

	char data_type = 's';

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

	return 0;
}