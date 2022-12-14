#include <iostream>
#include <windows.h>
#include <math.h>

void print_arr(int* arr, int size)
{
	if (size <= 0)
	{
		std::cout << "Неправильный массив, размер <= 0" << std::endl;
		return;
	}
	std::cout << "Исходный массив: ";
	for(int i=0; i<size; ++i)
		std::cout << *(arr+i) << ' ';
	std::cout << std::endl;
}

void print_pyramid(int* arr, int size)
{
	if (size <= 0)
	{
		std::cout << "Неправильный массив, размер <= 0" << std::endl;
		return;
	}
	std::cout << "Пирамида: " << std::endl;
	std::cout << "0 root " << *arr << std::endl;
	for (int i = 1; i < size; ++i)
	{
		int k = static_cast<int>(log(i + 1) / log(2));

		if (0 != i % 2)
		{
			std::cout << k << " left (";
		}
		else
		{
			std::cout << k << " right (";
		}
		std::cout << *(arr + ((i - 1) / 2)) << ") " << *(arr + i) << std::endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr1[] = { 1, 3, 6, 5, 9, 8 };
	int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
	int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

	int tmp = sizeof(arr1) / sizeof(arr1[0]);
	print_arr(arr1, tmp);
	print_pyramid(arr1, tmp);

	tmp = sizeof(arr2) / sizeof(arr2[0]);
	print_arr(arr2, tmp);
	print_pyramid(arr2, tmp);

	tmp = sizeof(arr3) / sizeof(arr3[0]);
	print_arr(arr3, tmp);
	print_pyramid(arr3, tmp);

	return 0;
}