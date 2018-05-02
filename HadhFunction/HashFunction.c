#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
//Брижак Андрей ДЗ по курсу Алгоритмы и структуры данных. Задача 1.

//  1. Реализовать простейшую хеш-функцию.
const int p = 31;


long long HashFunction;



int main(int argc, char * argv[])
{
	/*char *locale = setlocale(LC_ALL, "");*/
	
	char s[10];
	int  i;
	long long hash = 0;
	long long	p_pow = 1;
	printf("Input string ( 10) : \n");
	gets(s);
	printf("String: \n");
	puts(s);      // Вывод строки
	getch();
	for ( i = 0; i < 10; ++i)
	{
		// +1, чтобы у строк "a", "aa", "aaa" был разных ненулевой хэш
		hash += (s[i] - 'a' + 1) * p_pow;
		p_pow *= p;
	}
	printf("Hash key: \n");
	printf("%lu", hash);
	getch();
	return 0;
}
