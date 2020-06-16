#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define M 5
#define SIZE_1 15
#define SIZE_2 120



typedef struct info
{
	char term[SIZE_1];
	char definition[SIZE_2];
}Info;

void OpenFile(FILE** file, char* f_name, const char* mode)
{
	*file = fopen(f_name, mode);
	if (*file == NULL)
	{
		printf("\nНе вдалось відкрити файл: %s\n", f_name);
		exit(-1);
	}
	else
	{
		printf("\nУспішно відкрито файл %s\n", f_name);
		return;
	}
}

bool AnswerIsCorrect(char* right_answer, char* answer)
{
	if (strstr(right_answer, answer) == NULL)
	{
		printf("\nВідповідь невірна!\nПравильна відповідь - %s.", right_answer);
		return false;
	}
	else
	{
		printf("\nВідповідь вірна!");
		return true;
	}
}

Info* ReadFromFile(FILE** file)
{
	Info *tmp = (Info*)malloc(sizeof(Info));
	fread(tmp, SIZE_1+SIZE_2, 1, *file);
	return tmp;
}
int RandomQuestion(Info* arr, int size)
{
	int k_right = 0, k_quest, j;
	char* answer = (char*)malloc(SIZE_1 * sizeof(char));
	for (k_quest = 0; k_quest < M; k_quest++)
	{
		j = rand() % size;
		printf("\nВведіть термін до визначення %s: ", arr[j].definition);
		gets_s(answer, SIZE_1);
		if (AnswerIsCorrect(arr[j].term, answer) == true)
		{
			k_right++;
		}
	}
	free(answer);
	return k_right;
}
int main(void)
{
	system("chcp 1251");
	srand((unsigned)time(NULL));
	FILE* file;
	Info arr[] = { {"Данієль","зе бест тічер ін зе ворлд" },{"Політех","зе бест юніверсіті ін зе ворлд" },{"Войтишин","зе бест ремонтнік ін зе ворлд" },{"Баран","хуйєсос єбаний нахуй" },{"Шрєк","демониця" } };
	int k_right;
	OpenFile(&file, (char*)"bin.su", "w+b");
	for (int i = 0; i < M; i++) 
	{
		fwrite(&arr[i], 135, 1, file);
	}
	fseek(file, 0, SEEK_SET);
	for (int i = 0; i < M; i++)
	{
		arr[i] = *ReadFromFile(&file);
	}
	k_right = RandomQuestion(arr, M);
	printf("\nКількість правильних відповідей - %d", k_right);
	_fcloseall();
	return 0;
}
