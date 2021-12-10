#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#define M_PI 3.14159265358979323846

void printArrayForTask1(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != 0)
		{
			printf("%d%c",arr[i],' ');
		}
		else
		{
			continue;
		}
	}
	printf("\n");
}

int processArray(int arr[], int *leselem, int size)
{
	int a = 0;
	int b = 0;
	while (a >= 0) {
		std::cout << "a<0 a= ";
		std::cin >> a;
	}

	std::cout << "b= ";
	std::cin >> b;

	for (int i = 0; i < size; i++)
	{
		arr[i] = 1;
		if (i % 2 == 0) 
		{
			arr[i] = rand() % (a * -2 + 1) - b; //генерируем случайное число от а до b
		}

	}

	printArrayForTask1(arr, size);


	int mod = 0;

	for (int i = 0; i < size; i++) //отрицательные элементы
	{
		if (i != 0 && i != size - 1) //проверка на выход за рамки массива
		{
			if (arr[i] < 0 )
			{
				leselem[i] = arr[i];
				
			}
		}
	}

	for (int i = 0; i < size; i++) 
	{
		return arr[i];
	}

}

void initializeArray(double** arr, int n, int m)
{
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			arr[i][j] = x * sin((M_PI * x / 25));
			x++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		double num = 0;
		for (int j = 1; j < m; j++)
		{
			num = num + arr[i][j];
		}
		arr[i][0] = num;
		num=0;
	}

}

double* arrayTwoToOne(double** arr, int n, int m)
{
	int size = n * m;
	double* arr1D = new double [size];
	int count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			*(arr1D + count) = *(*(arr + i) + j); 
			count++;
		}
	}
	return arr1D;
}

void deleteArray(double** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void printArray2D(double** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << std::setw(10)<< *(*(arr + i) + j);
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}



char* reverseChar(char* s, int c)
{
	size_t len = 0; 
	char* rest_of_string = NULL; 

	while (s[len] != '\0')
	{
		// при этом если очередной символ оказался равен искомому с,
		if (s[len] == c)
		{
			rest_of_string = s + len; // то запоминаем указатель на него
			return rest_of_string;
		}

		len++;
		
	}

}

int main()
{
	/* Вариант 1
		1. Объявить массив из n=15 вещественных чисел, проинициализировать единицами.
	Функция processArray() должна домножить все элементы с четными индексами на
	случайное число из диапазона [a, b] (a и b ввести с клавиатуры, a < 0), подсчитать и
	вернуть количество отрицательных элементов массива и сформировать выходной
	массив, содержащий только отрицательные элементы входного (т.е. размерность
	уменьшится). Вывести на экран результирующие массивы. */

	printf("Task 1\n");											
	int num[15] = {1};
	int leselem[15] = {};
	const int size = sizeof(num) / sizeof(num[0]);
	int x = processArray(num, leselem, size);
	printArrayForTask1(leselem, size);


	/* Преобразование: 1D → 2D. Одномерный массив из 25 вещественных чисел необходимо
	разложить по двумерной сетке 5х5 слева направо и сверху вниз, но первый элемент на
	каждой строке должен содержать сумму остальных четырех.
	Инициализация: заполнить массив числами x[n] = n ∙ sin(πn/25), n – индекс элемента.
	Вывод на экран: на каждый элемент массива отвести 10 позиций */

	printf("Task 2\n");
	const int n = 5;
	const int m = 5;
	double** array = new double* [5]; 
	for (int i = 0; i < 5; i++)
	{
		*(array + i) = new double[5];
	}
	initializeArray(array, n, m);
	printArray2D(array, n, m);
	double* exitarray = arrayTwoToOne(array, n, m);
	deleteArray(array, n);
	delete[] exitarray;


	printf("Task 3\n");
	// тестовая строка
	char s[] = "www.some_address.and_something_else.com";

	// проверяем свою версию стандартной функции
	char* my_result = reverseChar(s, '.');
	// выводим на экран строку,

	// и  результат своей версии
	printf("Initial string:  %s\nMy version: %s\n",
		s, my_result);
	return 0;

}

