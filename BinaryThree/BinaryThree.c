//Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 2.
//2. Переписать программу, реализующую двоичное дерево поиска.
//а) Добавить в него обход дерева различными способами;
//б) Реализовать поиск в двоичном дереве поиска;
//в) *Добавить в программу обработку командной строки, с помощью которой можно указывать, 
//из какого файла считывать данные, каким образом обходить дерево.
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int T;
typedef struct Node {
	T data;
	struct Node * left;
	struct Node * right;
	struct Node * parent;
} Node;

// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node * root) {
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");
			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");
			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

// Создание нового узла
Node * getFreeNode(T value, Node * parent) {
	Node * tmp = (Node *)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// Вставка узла
void insert(Node ** head, int value) {
	Node * tmp = NULL;
	if (*head == NULL)
	{
		*head = getFreeNode(value, NULL);
		return;
	}
	tmp = *head;
	while (tmp)
	{
		if (value > tmp->data)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (value < tmp->data)
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		else
		{
			exit(2); // дерево построено неправильно
		}
	}
}

void preOrderTravers(Node * root) {
	if (root) {
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}

void inOrderTravers(Node * root) {
	if (root) {
		
		inOrderTravers(root->left);
		printf("%d ", root->data);
		inOrderTravers(root->right);
	}
}

void postOrderTravers(Node * root) {
	if (root) {

		postOrderTravers(root->left);
		postOrderTravers(root->right);
		printf("%d ", root->data);
	}
}

int main()
{
	Node * Tree = NULL;
	FILE * file = fopen("data.txt", "r");
	if (file == NULL)
	{
		puts("Can't open file!");
		getch();
		exit(1);
	}
	int count;
	fscanf(file, "%d", &count); // Считываем количество записей
	int i;
	for (i = 0; i < count; i++)
	{
		int value;
		fscanf(file, "%d", &value);
		insert(&Tree, value);
	}
	fclose(file);
	printTree(Tree);
	getch();
	printf("\n PreOrderTravers:");
	preOrderTravers(Tree);
	getch();
	printf("\n InOrderTravers:");
	inOrderTravers(Tree);
	getch();
	printf("\n PostOrderTravers:");
	postOrderTravers(Tree);
	getch();
	return 0;
}

