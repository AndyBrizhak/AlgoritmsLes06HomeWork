//������ ������ �� �� ����� ��������� � ��������� ������. ������ 3.
//   *����������� ���� ������ ��������� �� ����� �����, ��������, ���������� �����
//�������� ������ � �������� ������ ������.���������� ����� �� ������ - ������ ���� ���� ������(�������, ���).
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



int main()
{
	Student [4] = {{ 1234, "Vasia", 20, 78},{ 1235, "Masha", 19, 50 },{ 1230, "Grusha", 18, 52 },{ 1220, "Perikl", 22, 78 }};
	 
	return 0;
}
