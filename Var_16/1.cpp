#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int CountOneInBinNumb(int number)
{
	int digit, k_one = 0;
	do
	{
		digit = number % 2;
		if (digit == 1)
		{
			k_one++;
		}
	} while (number /= 2);
	return k_one;
}
int main(void)
{
	system("chcp 1251");
	FILE* file;


	file = fopen("numbers.bin", "wb");
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++)
	{
		fwrite(&arr[i], 4, 1, file);
	}
	_fcloseall();


	file = fopen("numbers.bin", "rb");
	int number;
	while (!feof(file))
	{
		fread(&number, sizeof(int), 1, file);
		printf("\n×טסכמ %d, ך-סעü 1 => %d", number, CountOneInBinNumb(number));
	}
	return 0;
}