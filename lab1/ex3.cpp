#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char a[100][100];
	char cuvant[100];
	int cuv = 0;
	int nrmax;
	printf("Introduceti nr de cuv: ");
	scanf("%d", &nrmax, 99);

	while (scanf_s("%99s", cuvant, 99))
	{
		strcpy(a[cuv], cuvant);
		//printf("%s ", a[i]);
		cuv++;
		if (cuv == nrmax - 1) break;
	}

	for (int j = 0; j < cuv; j++)
		for (int k = j + 1; k < cuv - 1; k++)
			if (strlen(a[j]) < strlen(a[k]) || (strlen(a[j]) == strlen(a[k]) && strcmp(a[j], a[k]) > 0))
				swap(a[j], a[k]);

	for (int j = 0; j < cuv; j++)
		printf("%s \n", a[j]);
	return 0;
}#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char a[100][100];
	char cuvant[100];
	int cuv = 0;
	int nrmax;
	printf("Introduceti nr de cuv: ");
	scanf("%d", &nrmax, 99);

	while (scanf_s("%99s", cuvant, 99))
	{
		strcpy(a[cuv], cuvant);
		//printf("%s ", a[i]);
		cuv++;
		if (cuv == nrmax - 1) break;
	}

	for (int j = 0; j < cuv; j++)
		for (int k = j + 1; k < cuv - 1; k++)
			if (strlen(a[j]) < strlen(a[k]) || (strlen(a[j]) == strlen(a[k]) && strcmp(a[j], a[k]) > 0))
				swap(a[j], a[k]);

	for (int j = 0; j < cuv; j++)
		printf("%s \n", a[j]);
	return 0;
}