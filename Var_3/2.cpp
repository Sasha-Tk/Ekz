#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double* Merging(double* arr_1, int size_1, double* arr_2, int size_2)
{
	double* new_arr = (double*)malloc((size_1 + size_2) * sizeof(double));
	int i = 0, j = 0, k = 0;
	while (i < size_1 && j < size_2)
	{
		if (arr_1[i] > arr_2[j])
		{
			new_arr[k] = arr_1[i];
			k++;
			i++;
		}
		else
		{
			new_arr[k] = arr_2[j];
			k++;
			j++;
		}
	}
	while (i < size_1)
	{
		new_arr[k] = arr_1[i];
		k++;
		i++;
	}
	while (j < size_2)
	{
		new_arr[k] = arr_2[j];
		k++;
		j++;
	}
	return new_arr;
}

void GetArr(double* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		scanf_s("%lf", &arr[i]);
	}
}
int main(void)
{
	system("chcp 1251");
	double* arr;
	int size_1, size_2;
	printf("\nВведіть розмір першого масиву: ");
	scanf_s("%d", &size_1);
	double* arr_1 = (double*)malloc(size_1 * sizeof(double));
	printf("\nВведіть %d елементів першого масиву: ", size_1);
	GetArr(arr_1, size_1);
	printf("\nВведіть розмір другого масиву: ");
	scanf_s("%d", &size_2);
	double* arr_2 = (double*)malloc(size_2 * sizeof(double));
	printf("\nВведіть %d елементів другого масиву: ", size_2);
	GetArr(arr_2, size_2);
	arr = Merging(arr_1, size_1, arr_2, size_2);
	printf("\nМасиви після об'єднання: ");
	for (int i = 0; i < size_1 + size_2; i++)
	{
		printf("%lf  ", arr[i]);
	}
	free(arr_1);
	free(arr_2);
	free(arr);
	return 0;
}