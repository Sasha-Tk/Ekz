#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 30
#define N 50

void CopySpaceAndFirstLetter(char** p_1, char** p_2)
{
	for (int i = 0; i < 2; i++)
	{
		*(*p_1)++ = *(*p_2)++;
	}
	while (**p_2 != ' ')
	{
		(*p_2)++;
	}
}

char* ChangeStr(char* str)
{
	char* new_str = (char*)malloc(strlen(str) + 1);
	char* p_s = str, * p_ns = new_str;
	while (*p_s != ' ')
	{
		*p_ns++ = *p_s++;
	}
	CopySpaceAndFirstLetter(&p_ns, &p_s);
	*p_ns++ = '.';
	*p_ns = ' ';
	CopySpaceAndFirstLetter(&p_ns, &p_s);
	*p_ns++ = '.';
	*p_ns++ = '\n';
	*p_ns = '\0';
	return new_str;
}
int main(void)
{
	system("chcp 1251");
	FILE* input, * output;
	char* name = (char*)malloc(F * sizeof(char));
	char* new_name = (char*)malloc(F * sizeof(char));
	char* p;
	char sentence[N];
	char* buffer;
	printf("Введіть ім'я файлу: ");
	gets_s(name, F);
	strcpy(new_name, name);
	p = strstr(new_name, ".txt");
	sprintf(p, ".skr");
	input = fopen(name, "r");
	if (input == NULL)
	{
		printf("\nНе вдалось відкрити файл!");
		return -1;
	}
	output = fopen(new_name, "w");
	while (!feof(input))
	{
		fgets(sentence, N, input);
		buffer = ChangeStr(sentence);
		fputs(buffer, output);
		free(buffer);
	}
	free(name);
	free(new_name);
	_fcloseall();
	return 0;
}