#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define N 300
#define M 30

void ChangeAndPrintInfoToFile(char* sentence, FILE* new_file);
int RoundTheNumber(double number);
char* FindEndOfNumber(char* begin);

int main(void)
{
	system("chcp 1251");
	FILE* input, * output;
	char* name = (char*)malloc(M * sizeof(char));
	char* n_name = (char*)malloc(M * sizeof(char));
	char* buffer = (char*)malloc(N * sizeof(char));
	printf("\n¬вед≥ть ≥м'€ файлу з даними: ");
	gets_s(name, M);
	input = fopen(name, "r");
	if (input == NULL)
	{
		printf("‘айл не в≥дкрито!");
		return -1;
	}
	printf("\n¬вед≥ть ≥м'€ нового файлу: ");
	gets_s(n_name, M);
	output = fopen(n_name, "w");
	while (!feof(input))
	{
		fgets(buffer, N, input);
		ChangeAndPrintInfoToFile(buffer, output);
	}
	free(name);
	free(n_name);
	free(buffer);
	_fcloseall();
	return 0;
}

void ChangeAndPrintInfoToFile(char* sentence, FILE* new_file)
{
	char* new_sentence = (char*)malloc((strlen(sentence) + 1) * sizeof(char));
	char* p_s = sentence, * p_ns = new_sentence;
	char* p_end_of_numb, * p_of_comma;
	while (*p_s)
	{
		while (!isdigit(*p_s) && *p_s != '\0')
		{
			*p_ns++ = *p_s++;
			/*p_ns++;
			p_s++;*/
		}
		if (!*p_s)
		{
			break;
		}
		p_end_of_numb = FindEndOfNumber(p_s);
		p_of_comma = strchr(p_s, ',');
		if (p_of_comma != NULL && p_of_comma > p_s && p_of_comma < p_end_of_numb)
		{
			double number;
			int round_number;
			*p_of_comma = '.';
			number = atof(p_s);
			round_number = RoundTheNumber(number);
			sprintf(p_ns, "%d", round_number);
			while (isdigit(*p_ns))
			{
				p_ns++;
			}
			p_s = p_end_of_numb;
			continue;
		}
		while (isdigit(*p_s))
		{
			*p_ns++ = *p_s++;
			/*p_ns++;
			p_s++;*/
		}
	}
	*p_ns = *p_s;
	fputs(new_sentence, new_file);
	free(new_sentence);
}

int RoundTheNumber(double number)
{
	return (int)(number + 0.5);
}

char* FindEndOfNumber(char* begin)
{
	char* ptr = begin;
	while (*ptr == ',' || *ptr >= '0' && *ptr <= '9')
	{
		ptr++;
	}
	return ptr;
}