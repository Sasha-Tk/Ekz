#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
	char* name;
	double rating;
}Info;

typedef struct list
{
	Info VNZ;
	struct list* next;
	struct list* prev;
}List;

void AddElement(List** Top, Info new_info)
{
	List* new_el = (List*)malloc(sizeof(List));
	List* p = *Top;
	if (*Top == NULL)
	{
		new_el->VNZ = new_info;
		new_el->next = new_el;
		new_el->prev = new_el;
		*Top = new_el;
	}
	else
	{
		while (p->next != *Top) p = p->next;
		new_el->next = *Top;
		new_el->next->prev = new_el;
		p->next = new_el;
		*Top = new_el;
		new_el->VNZ = new_info;
	}
}

void DeleteList(List* Top)
{
	List* p = Top;
	List* p_next;
	while (p->next != Top)
	{
		p_next = p->next;
		free(p);
		p = p_next;
	}
	free(p);
	Top = NULL;
}
int main(void)
{
	system("chcp 1251");
	List* list = NULL;
	Info arr[3] = { (char*)"” ”", 10.5, (char*)"ÀÕ”", 7.77, (char*)"Politeh", 0 };
	for (int i = 0; i < 3; i++)
	{
		AddElement(&list, arr[i]);
	}
	List* p = list;
	while (p->next != list) 
	{
		printf("%s %lf\n", p->VNZ.name, p->VNZ.rating);
		p = p->next;
	}
	printf("%s %lf\n", p->VNZ.name, p->VNZ.rating);
	DeleteList(list);
}