#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	system("chcp 1251");
	FILE* input, * output;
	input = fopen("input.bin", "wb+");
	output = fopen("output.bin", "wb+");
	double first_number, current_number;
	double arr[] = { 5.41,141.255,524.12,41.4,652.42,5412.1231,623.41,4.52,5.41,1.41 };
	for (int i = 0; i < 10; i++)
	{
		fwrite(&arr[i], sizeof(double), 1, input);
		printf("%lf\n", arr[i]);
	}
	fseek(input, 0, SEEK_SET);
	fread(&first_number, sizeof(double), 1, input);
	fwrite(&first_number, 8, 1, output);
	while (!feof(input))
	{
		fread(&current_number, 8, 1, input);
		if (current_number > first_number)
		{
			current_number /= 1.5;
		}
		fwrite(&current_number, 8, 1, output);
	}
	


	/*fseek(input, 0, SEEK_SET);  фор мі
	fread(&first_number, sizeof(double), 1, input);
	while (!feof(input)) 
	{
		fread(&current_number, 8, 1, input);
		if (current_number > first_number)
		{

			fseek(input, -8, SEEK_CUR);
			current_number /= 1.5;
			fwrite(&current_number, 8, 1, input);
		}
	}
	printf("\nПісля заміни:\n");
	fseek(input, 0, SEEK_SET);
	for (int i = 0; i < 10; i++)
	{
		fread(&arr[i], sizeof(double), 1, input);
		printf("%lf\n", arr[i]);
	}*/
	printf("\nПісля заміни:\n");
	fseek(output, 0, SEEK_SET);
	for (int i = 0; i < 10; i++)
	{
		fread(&arr[i], sizeof(double), 1, output);
		printf("%lf\n", arr[i]);
	}
	_fcloseall();
	remove("input.bin");
	rename("output.bin", "input.bin");
	return 0;
}