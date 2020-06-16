#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* ChangeStr(char* str)
{
	char* new_str = (char*)malloc(255 * sizeof(char));
	char* p_s = str, * p_ns = new_str;
	int smb, k_smb;
	while (p_s != NULL)
	{
		k_smb = atoi(p_s);
		if (k_smb == 0)
		{
			return new_str;
		}
		smb = *++p_s;
		for (int i = 0; i < k_smb; i++)
		{
			sprintf(p_ns, "%c", smb);
			p_ns++;
		}
		p_s++;
	}
	return new_str;
}


int main(void)
{
	printf("%s", ChangeStr((char*)"2S4E3X"));
}