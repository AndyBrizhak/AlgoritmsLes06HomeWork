//Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 3.
//   *Разработать базу данных студентов из полей «Имя», «Возраст», «Табельный номер»
//Считайте данные в двоичное дерево поиска.Реализуйте поиск по какому - нибудь полю базы данных(возраст, вес).
#include <stdio.h>
#include <string.h>

typedef struct student {
	int number;
	char firstname[10];
	int age;
	int weight; 
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
	free(tmpStudent);
}

void preOrderTravers(Node * root) {
	if (root) {
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}

void findAge(Node * root, int age)
{
	Student * tmpStudent = (Student *)malloc(sizeof(Student));
	if (root) 
	{
		Student Student = root->data;
		if (Student.age == age)
		{
			printf("\n Number student %d ", Student.number);
			printf("\n Name student %s ", Student.firstname);
			printf("\n Age student %d ", Student.age);
			printf("\n Weight student %d ", Student.weight);
		}
		findAge(root->left, age);
		findAge(root->right, age);
	}
	free(tmpStudent);
}
//
//Student * InpStud();
//{
//	int age;
//
//	Student *tmpStudent = (Student *)malloc(sizeof(Student));
//	printf("\n Number student %d ");
//	scanf_s("%d ", &number);
//
//	return tmpStudent;
//}


int main()
{
	Student list [4] = { 1234, "Vasia", 20, 78, 1235, "Masha", 19, 50 , 1230, "Grusha", 18, 52, 1220, "Perikl", 22, 78 };

	Node * Tree = NULL;
	int i;
	for (i = 0; i < 4; i++)
	{
	
		insert(&Tree, list[i]);
	}
	int age;
	printf("\n Input age student: ");
	scanf_s("%d", &age);
	findAge(Tree, age);
	getch();
	return 0;
}
