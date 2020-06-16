#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5

typedef struct coordinats
{
	int x;
	int y;
} Point;

typedef struct list
{
	Point point;
	struct list* next;
}List;

List* head, *tail;

void AddItem(Point point)
{
	List* newitem = (List*)malloc(sizeof(List));
	static List* prev;
	newitem->point = point;
	newitem->next = NULL;
	if (head == NULL)
	{
		head = tail = newitem;
		prev = newitem;
	}
	else
	{
		prev->next = newitem;
		tail = prev = newitem;
	}
}

double GetDistance(List* This, List* Other)
{
	double distance, sum_sqr = 0;
	double x1, x2, y1, y2;
	x1 = This->point.x;
	y1 = This->point.y;
	x2 = Other->point.x;
	y2 = Other->point.y;
	sum_sqr = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	distance = sqrt(sum_sqr);
	return distance;
}
void MaxDistance()
{
	double distance = 0.0, maxdistance = 0.0;
	List* p_1 = head, * p_2 = head->next, *pmax_1 = p_1, *pmax_2 = p_2;
	for (; p_1 != NULL; p_1 = p_1->next, p_2 = p_1)
	{
		for (p_2 = p_1->next; p_2 != NULL; p_2 = p_2->next)
		{
			double sq = (p_1->point.x - p_2->point.x) * (p_1->point.x - p_2->point.x) + (p_1->point.y - p_2->point.y) * (p_1->point.y - p_2->point.y);
			distance = (double)(sqrt(sq));
			if (distance > maxdistance)
			{
				maxdistance = distance;
				pmax_1 = p_1;
				pmax_2 = p_2;
			}
		}
	}
	printf("\nМаксимальна дистанція %lf між точками з координатами (%d, %d) та (%d, %d)\n", maxdistance, pmax_1->point.x, pmax_1->point.y, pmax_2->point.x, pmax_2->point.y);



	/*double cur_distance = 0.0, max_distance = 0.0;
	List* cur_el = head, *next_el = head->next;
	List* p1_max = cur_el, *p2_max = next_el;
	while (cur_el != NULL)
	{
		while (next_el != NULL)
		{
			cur_distance = GetDistance(cur_el, next_el);
			if (cur_distance > max_distance)
			{
				max_distance = cur_distance;
				p1_max = cur_el;
				p2_max = next_el;
			}
			next_el = next_el->next;
		}
		cur_el = cur_el->next;
	}
	printf("\nМаксимальна відстань між точкою (%d, %d) та (%d, %d) = %lf", 
		p1_max->point.x, p1_max->point.y, p2_max->point.x, p2_max->point.y, max_distance);*/
}

void DeleteEl(int ndel)
{
	List* del = head, * prev = NULL;
	int k = 1;
	while (k != ndel)
	{
		if (del->next == NULL)
		{
			printf("\nТакого елемента немає!\n");
			return;
		}
		prev = del;
		del = del->next;
		k++;
	}
	if (del == head)
	{
		head = del->next;
	}
	else
	{
		prev->next = del->next;
	}
	free(del);
}

int main()
{
	system("chcp 1251");
	int arrx[N] = {1,2,3,4,5};
	int arry[N] = {2,4,6,12,10};
	Point el;
	for (int i = 0; i < N; i++)
	{
		el.x = arrx[i];
		el.y = arry[i];
		AddItem(el);
	}

	for (List* ptr = head; ptr != NULL; ptr = ptr->next)
	{
		printf("%d %d\n", ptr->point.x, ptr->point.y);
	}
	MaxDistance();
	DeleteEl(4);
	printf("\n\n");
	for (List* ptr = head; ptr != NULL; ptr = ptr->next)
	{
		printf("%d %d\n", ptr->point.x, ptr->point.y);
	}
	return 0;
}