#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* FindNumber(char* str)
{
	char* p = str;
	while (!isdigit(*p) && *p != '\0')
	{
		p++;
	}
	return p;
}
int FindSing(char* str)
{
	char* p = str;
	while (*p != '+' && *p != '-' && *p != '*' && *p != '/' && *p != '\0')
	{
		p++;
	}
	return *p;
}

int Calculation(char* str)
{
	int number_1, number_2;
	char* p;
	int sign;
	p = FindNumber(str);
	number_1 = atoi(p);
	sign = FindSing(p);
	p = FindNumber(p);
	number_2 = atoi(p);
	switch (sign)
	{
	case '+':
	{
		return number_1 + number_2;
	}
	case '-':
	{
		return number_1 - number_2;
	}
	case '*':
	{
		return number_1 * number_2;
	}
	case '/':
	{
		return number_1 / number_2;
	}
	default:
		exit(-1);
	}
}
int main(void)
{
	Calculation((char*)"2 ^ 2");
}