#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50
#define K 8

bool IsItGirl(const char* name)
{
	int lastlet = strlen(name);
	if (name[lastlet - 1] == '�' || name[lastlet - 1] == '�')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Swap(char** n_1, char** n_2)
{
	char* tmp = *n_1;
	*n_1 = *n_2;
	*n_2 = tmp;
}

int main()
{
	system("chcp 1251");
	char** list = (char**)malloc(K * sizeof(char*));
	for (int i = 0; i < K; i++)
	{
		list[i] = (char*)malloc(N * sizeof(char));
	}

	strcpy(list[0], "������ ���������");
	strcpy(list[1], "�������� ������");
	strcpy(list[2], "����� ������");
	strcpy(list[3], "���������� �����");
	strcpy(list[4], "��������� ��������");
	strcpy(list[5], "������ ������");
	strcpy(list[6], "������� ���������");
	strcpy(list[7], "������� ����");

	/*for (int i = 0; i < K; i++)
	{
		for (int j = i+1; j < K; j++)
		{
			if (!IsItGirl(list[i]) && IsItGirl(list[j]))
			{
				Swap(&list[i], &list[j]);
				break;
			}
		}
	}*/
	{
		/*int k = 0, g = 0;
		while (k < K)
		{
			if (IsItGirl(list[g]))
			{
				g++;
				k++;
				continue;
			}
			else
			{
				k++;
				while (!IsItGirl(list[k]))
				{
					if (k + 1 == K)
					{
						break;
					}
					k++;
				}
				Swap(&list[g], &list[k]);
			}
			if (k + 1 == K)
			{
				break;
			}
			k = g;
		}*/
	}
	printf("\n\n");
	for (int i = 0; i < K; i++)
	{
		printf("%s\n", list[i]);
	}

	for (int i = 0; i < K; i++)
	{
		free(list[i]);
	}
	/*char** p;
	for (p = list; p < list + K; p++)
	{
		free(*p);
	}*/
	//free(list);
	return 0;
}