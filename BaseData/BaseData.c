//Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 3.
//   *Разработать базу данных студентов из полей «Имя», «Возраст», «Табельный номер»
//Считайте данные в двоичное дерево поиска.Реализуйте поиск по какому - нибудь полю базы данных(возраст, вес).
#include <stdio.h>
#include <string.h>

typedef struct student {
	int number[4];
	char firstname[20];
	int age[3];
	
	int weight[4]; 
	} Student;

typedef Student T;

typedef struct Node {
	T data;
	struct Node * left;
	struct Node * right;
	struct Node * parent;
} Node;

// Создание нового узла
Node * getFreeNode(T current, Node * parent) {
	Node * tmp = (Node *)malloc(sizeof(Node));
	tmp->left = tmp->right = NULL;
	tmp->data = current;
	tmp->parent = parent;
	return tmp;
}

// Вставка узла
void insert(Node ** head, Student current) {
	Student * tmpStudent = (Student *)malloc(sizeof(Student));
	Node * tmp = NULL;
	if (*head == NULL)
	{
		*head = getFreeNode(current, NULL);
		return;
	}
	tmp = *head;
	while (tmp)
	{
		Student tmpStudent = tmp->data;
		/*int tmpNumber = tmpStudent->number;*/
		if (current.number > tmpStudent.number)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = getFreeNode(current, tmp);
				return;
			}
		}
		else if (current.number < tmpStudent.number)
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				tmp->left = getFreeNode(current, tmp);
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


int main()
{
	Student list [4] = {{ 1234, "Vasia", 20, 78},{ 1235, "Masha", 19, 50 },{ 1230, "Grusha", 18, 52 },{ 1220, "Perikl", 22, 78 }};
	Node * Tree = NULL;
	int i;
	for (i = 0; i < 4; i++)
	{
	
		insert(&Tree, list[i]);
	}
	 
	return 0;
}
