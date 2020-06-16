#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 3
#define M 50

typedef struct info
{
	char* date;
	char* event;
}Info;

void FreeMem(Info** arr)
{
	for (int i = 0; i < N; i++)
	{
		free(arr[i]->date);
		free(arr[i]->event);
		free(arr[i]);
	}
	free(arr);
}
char* function(char* old_date)
{
	const char* arr[] = { "січня", "лютого", "березня", "квітня","травня","червня","липня","серпня","вересня","жовтня","листопада","грудня" };
	char* new_date = (char*)malloc(M * sizeof(char));
	char* p_o = old_date;
	int day, month, year;
	day = atoi(p_o);
	p_o += 3;
	month = atoi(p_o);
	p_o += 3;
	year = atoi(p_o);
	sprintf(new_date, "%d %s %d р.", day, arr[month - 1], year);
	return new_date;
}
int main(void)
{
	system("chcp 1251");
	Info** arr = (Info**)(malloc(N * sizeof(Info*)));
	for (int i = 0; i < N; i++)
	{
		arr[i] = (info*)malloc(sizeof(Info));
		arr[i]->date = (char*)malloc(M*sizeof(char));
		arr[i]->event = (char*)malloc(M*sizeof(char));
	}
	printf("\nВведіть %d структур:\n",N);
	for (int i = 0; i < N; i++)
	{
		gets_s(arr[i]->date, M);
		gets_s(arr[i]->event, M);
		arr[i]->date = function(arr[i]->date);
	}
	printf("\nДата - подія");
	for (int i = 0; i < N; i++)
	{
		printf("\n%s - %s", arr[i]->date, arr[i]->event);
	}
	FreeMem(arr);
}