#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int stringToInt(const char* str) {
	int num = 0;
	int i = 0;

	while (str[i] != '\0' && str[i] != '\n') {
		num = num * 10 + (str[i] - '0');
		i++;
	}

	return num;
}


int sum = 0;
int main()
{
	FILE* file;
	char line[100];
	int sum = 0;

	if (fopen_s(&file, "in.txt", "r")) {
		printf("Failed to open the file.\n");
		return 1;
	}

	while (fgets(line, sizeof(line), file) != NULL) {
		int num = stringToInt(line);
		sum += num;
	}


	fclose(file);
	printf("Total sum: %d\n", sum);

	return 0;
}