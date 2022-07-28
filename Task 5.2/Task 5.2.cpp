#include <iostream>
#include <windows.h>
#include <math.h>

enum class pyramid_commands
{
	up, right, left, exit
};

pyramid_commands user_input()
{
	std::string usr_input;
	pyramid_commands result;
	bool correct_command = false;
	do
	{
		std::cout << "Введите команду (up, right, left, exit): ";
		std::cin >> usr_input;
		if (usr_input == "up")
		{
			correct_command = true;
			result = pyramid_commands::up;
		}
		else if (usr_input == "right")
		{
			correct_command = true;
			result = pyramid_commands::right;
		}
		else if (usr_input == "left")
		{
			correct_command = true;
			result = pyramid_commands::left;
		}
		else if (usr_input == "exit")
		{
			correct_command = true;
			result = pyramid_commands::exit;
		}
		else std::cout << "Неправильная комманда!" << std::endl;
	} while (!correct_command);

	return result;
}

void print_arr(int* arr, const int& size)
{
	if (size <= 0)
	{
		std::cout << "Неправильный массив, размер <= 0" << std::endl;
		return;
	}
	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; ++i)
		std::cout << *(arr + i) << ' ';
	std::cout << std::endl;
}

void print_current_position(int* arr, const int& size, const int& idx)
{
	if (0 == idx)
	{
		std::cout << "0 root " << *arr << std::endl;
	}
	else
	{
		int k = static_cast<int>(log(idx + 1) / log(2));

		if (0 != idx % 2)
		{
			std::cout << k << " left (";
		}
		else
		{
			std::cout << k << " right (";
		}
		std::cout << *(arr + ((idx - 1) / 2)) << ") " << *(arr + idx) << std::endl;
	}
}

void print_pyramid(int* arr, const int& size)
{
	if (size <= 0)
	{
		std::cout << "Неправильный массив, размер <= 0" << std::endl;
		return;
	}
	std::cout << "Пирамида: " << std::endl;
	for (int i = 0; i < size; ++i)
	{
		print_current_position(arr, size, i);
	}
}

void into_the_pyramid(int* arr, const int& size)
{
	int current_idx = 0;
	bool do_journey = true;
	do
	{
		std::cout << "Вы находитесь здесь: ";
		print_current_position(arr, size, current_idx);
		int tmp;
		switch (user_input())
		{
		case (pyramid_commands::up):
			if (current_idx!=0)
			{
				std::cout << "Ok" << std::endl;
				tmp = (current_idx - 1) / 2;
				current_idx = tmp;
			}
			else std::cout << "Ошибка! Отсутствует родитель" << std::endl;
			break;

		case (pyramid_commands::left):
			tmp = current_idx*2+1;
			if (tmp < size)
			{
				std::cout << "Ok" << std::endl;
				current_idx = tmp;
			}
			else std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
			break;

		case (pyramid_commands::right):
			tmp = current_idx * 2 + 2;
			if (tmp < size)
			{
				std::cout << "Ok" << std::endl;
				current_idx = tmp;
			}
			else std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
			break;

		case (pyramid_commands::exit):
			std::cout << "Ok" << std::endl;
			do_journey = false;
			break;
		}
	} while (do_journey);
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
	into_the_pyramid(arr1, tmp);

	tmp = sizeof(arr2) / sizeof(arr2[0]);
	print_arr(arr2, tmp);
	print_pyramid(arr2, tmp);
	into_the_pyramid(arr2, tmp);

	tmp = sizeof(arr3) / sizeof(arr3[0]);
	print_arr(arr3, tmp);
	print_pyramid(arr3, tmp);
	into_the_pyramid(arr3, tmp);

	return 0;
}