#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100
#define MAX_LETTERS 52



bool AlreadyInArr(char* arr, int n, char let)
{
	for (int i = 0; i < n && arr[i] != '\0'; i++)
	{
		if (arr[i] == let)
		{
			return true;
		}
	}
	return false;
}

void CountLetters(char** arr, int n)
{
	char* letters = (char*)calloc(MAX_LETTERS + 1, sizeof(char));
	int k_letters = 0, k_povt, cur_let, was_in_sentence = 0;
	int size_of_first_sent = strlen(arr[0]);
	int size_of_curr_sent;
	for (int i = 0; i < size_of_first_sent; i++)
	{
		cur_let = arr[0][i];
		k_povt = 0;
		if (!isalpha(cur_let))
		{
			continue;
		}
		else if (strchr(letters, cur_let)!=NULL)
		{
			k_povt++;
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			was_in_sentence = 0;
			size_of_curr_sent = strlen(arr[j]);
			for (int k = 0; k < size_of_curr_sent; k++)
			{
				if (arr[j][k] == cur_let)
				{
					was_in_sentence = 1;
					if (strchr(letters, cur_let)!=NULL)
					{
						k_povt++;
						continue;
					}
					k_povt++;
					letters[k_letters++] = cur_let;
				}
			}
			if (was_in_sentence == 0)
			{
				k_povt = 0;
				letters[k_letters--] = '\0';
				break;
			}
		}
		if (k_povt != 0)
		{
			printf("\nЛітера %c повторюється %d разів.", cur_let, k_povt);
		}
	}
	if (k_letters == 0)
	{
		printf("\nТаких літер не знайдено!");
	}
	free(letters);
}
int PrintRepeatedLetters(char** arr, int n)
{
	char passed_letters[N];
	int passed_num_let = 0, repeat;
	char letter;
	for (int i = 0; i < strlen(arr[0]); i++)
	{
		letter = arr[0][i];
		repeat = 0;
		if (letter < 'A' || letter > 'z')
		{
			continue;
		}
		if (AlreadyInArr(passed_letters, N, letter) == true)
		{
			repeat++;
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < strlen(arr[j]); k++)
			{
				if (arr[j][k] == letter)
				{
					if (AlreadyInArr(passed_letters, N, letter) == true)
					{
						repeat++;
						continue;
					}
					*(passed_letters + passed_num_let) = letter;
					passed_num_let++;
					repeat++;
				}
			}
		}
		if (repeat)
		{
			printf("\nЛітера %c повторюється %d разів.", letter, repeat);
		}
	}
	return passed_num_let;
}



int main(void)
{
	system("chcp 1251");
	int n;
	printf("\nВведіть кількість речень: ");
	scanf_s("%d", &n);
	rewind(stdin);
	char** arr = (char**)malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (char*)malloc(N * sizeof(char));
		gets_s(arr[i], N);
	}
	CountLetters(arr, n);
	if (!PrintRepeatedLetters(arr, n))
	{
		printf("\nНе знайдено літер, які повторюються!");
	}
	for (int i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
}