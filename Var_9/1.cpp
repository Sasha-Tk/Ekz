#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void GetArray(double* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lf", &arr[i]);
	}
}

void Swap(double* el_1, double* el_2)
{
	double tmp = *el_1;
	*el_1 = *el_2;
	*el_2 = tmp;
}

void Sort(double* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[i])
			{
				Swap(&arr[j], &arr[i]);
			}
		}
	}
}

int FindEl(double* arr_1, int n_1, double* arr_2, int n_2)
{
	int InArr;
	for (int i = 0; i < n_1; i++)
	{
		InArr = 0;
		for (int j = 0; j < n_2; j++)
		{
			if (arr_1[i] == arr_2[j])
			{
				InArr = 0;
				break;
			}
		}
		if (InArr == 0)
		{
			return i;
		}
	}
	return -1;
}
int main(void)
{
	system("chcp 1251");
	double* arr_1, * arr_2;
	int n_1, n_2;
	printf("\nВведіть кількість елементів першого масиву: ");
	scanf_s("%d", &n_1);
	arr_1 = (double*)malloc(n_1 * sizeof(double));
	printf("\nВведіть елементи першого масиву: ");
	GetArray(arr_1, n_1);
	printf("\nВведіть кількість елементів другого масиву: ");
	scanf_s("%d", &n_2);
	arr_2 = (double*)malloc(n_2 * sizeof(double));
	printf("\nВведіть елементи другого масиву: ");
	GetArray(arr_2, n_2);
	Sort(arr_1, n_1);
	int index = FindEl(arr_1, n_1, arr_2, n_2);
	if (index == -1)
	{
		printf("\nТакого елемента не знайдено!");
	}
	else
	{
		printf("\nТакий елемент є, його значення = %lf", arr_1[index]);
	}
	free(arr_1);
	free(arr_2);
	return 0;
}