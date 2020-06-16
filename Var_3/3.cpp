#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct cyrcle
{
	double x;
	double y;
	double R;
}Cyrcle;

typedef struct node
{
	Cyrcle cyrcle;
	struct node* left;
	struct node* right;
}Node;

void PrintToBinFile(FILE* file, Node* root)
{
	if (root == NULL)
	{
		return;
	}
	PrintToBinFile(file, root->left);
	fwrite(&(root->cyrcle), sizeof(Cyrcle),1, file);
	//printf("%lf\t", root->cyrcle.R);
	PrintToBinFile(file, root->right);
}

int CountLeaf(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		return CountLeaf(root->left) + CountLeaf(root->right);
	}
}

//Cyrcle ReadNode(void)
//{
//	Cyrcle tmp;
//	double x, y, R;
//	scanf_s("%lf%lf%lf", &x, &y, &R);
//	tmp.R = R;
//	tmp.x = x;
//	tmp.y = y;
//	return tmp;
//}
//void AddEementToTree(Node** root, Cyrcle new_el)
//{
//	Node* new_node = (Node*)malloc(sizeof(Node));
//	new_node->cyrcle = new_el;
//	if (NULL == *root)
//	{
//		new_node->left = NULL;
//		new_node->right = NULL;
//		*root = new_node;
//		return;
//	}
//	if (new_node->cyrcle.R > (*root)->cyrcle.R)
//	{
//		AddEementToTree(&((*root)->right), new_node->cyrcle);
//	}
//	if (new_node->cyrcle.R < (*root)->cyrcle.R)
//	{
//		AddEementToTree(&((*root)->left), new_node->cyrcle);
//	}
//}
int main(void)
{
	system("chcp 1251");
	FILE* output;
	output = fopen("allrings.inf", "wb");
	Node* Root = NULL;
	/*for (int i = 0; i < 7; i++)
	{
		AddEementToTree(&Root, ReadNode());
	}*/


	//заповнення дерева елементами


	printf("\n\nЛистків у дереві - %d\n\n", CountLeaf(Root));
	PrintToBinFile(output, Root);

	//мало би бути видалення дереаа


	/*Cyrcle tmp;
	fseek(output, 0, SEEK_SET);
	printf("\n");
	for (int i = 0; i < 7; i++)
	{
		fread(&tmp, sizeof(Cyrcle),1, output);
		printf("%lf\t", tmp.R);
	}
	_fcloseall();*/
}