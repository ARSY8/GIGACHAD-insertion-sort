#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "insertion_sort.h"
#include "person_information.h"
#include "assert_insertion_sort.h"


int main(void) {
	run_all_tests();
	printf("Все тесты пройдены успешно.");
	return 0;
}


int compare_char(void* a, void* b) {
	return *(char*)a < *(char*)b ? 1 : 0;
}

int compare_int(void* a, void* b) {
	return *(int*)a < *(int*)b ? 1 : 0;
}

int compare_float(void* a, void* b) {
	return *(float*)a < *(float*)b ? 1 : 0;
}

int compare_string_v1(void* a, void* b) {
	char* str1 = *(char**)a;
	char* str2 = *(char**)b;

	return strcmp(str1, str2) < 0 ? 1 : 0;
}


int compare_string_v2(void* a, void* b) {
	char* str1 = *(char**)a;
	char* str2 = *(char**)b;

	int lenght = 0;

	while (str1[lenght] != '\0' && str2[lenght] != '\0') {
		if (str1[lenght] < str2[lenght]) {
			return 1;
		}
		else if(str1[lenght] > str2[lenght]){
			return 0;
		}
		lenght++;
	}
}


int compare_person_v1(void* a, void* b) {
	char* str1 = ((INFO*)a)->last_name;
	char* str2 = ((INFO*)b)->last_name;

	return strcmp(str1, str2) < 0 ? 1 : 0;
}


int compare_person_v2(void* a, void* b) {
	char* str1 = ((INFO*)a)->last_name;
	char* str2 = ((INFO*)b)->last_name;

	int lenght = 0;

	while (str1[lenght] != '\0' && str2[lenght] != '\0') {
		if (str1[lenght] < str2[lenght]) {
			return 1;
		}
		else if (str1[lenght] > str2[lenght]) {
			return 0;
		}
		lenght++;
	}
}