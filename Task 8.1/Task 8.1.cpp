#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

enum Error_Codes {
	File_Not_Open = 1,
	Invalid_Arg = 2,
	Out_Of_Range = 3
};

void print_graph(int** arr, int size)
{
	std::cout << "Текстовый вид орграфа:" << std::endl;

	for (int i = 0; i < size; ++i)
	{
		std::cout << i+1 << ": ";
		bool point = false;
		for (int j = 0; j < size; ++j)
		{
			if (1 == arr[i][j])
			{
				std::cout << j+1 << " ";
				point = true;
			}
		}
		if (!point) std::cout << "нет";
		std::cout << std::endl;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const std::string file_name = "input.txt";

	std::string str_input;
	std::ifstream file_to_use;
	file_to_use.open(file_name);
	if (!file_to_use.is_open())
	{
		std::cerr << "Невозможно открыть файл!";
		return Error_Codes::File_Not_Open;
	}

	file_to_use >> str_input;

	int matrix_size = 0;
	try
	{
		matrix_size = std::stoi(str_input);
	}
	catch (std::invalid_argument const& ex)
	{
		std::cerr << "Неправильно числовое значение размера матрицы графа." << std::endl;
		return Error_Codes::Invalid_Arg;
	}
	catch (std::out_of_range const& ex)
	{
		std::cerr << "Введенное число слишком велико." << std::endl;
		return Error_Codes::Out_Of_Range;
	}

	int** graph_matrix = new int* [matrix_size];
	for (int i = 0; i < matrix_size; ++i)
		graph_matrix[i] = new int[matrix_size]();

	for (int i = 0; i < matrix_size; ++i)
		for (int j = 0; j < matrix_size; ++j)
		{
			file_to_use >> str_input;
			graph_matrix[i][j] = std::stoi(str_input);
		}

	file_to_use.close();

	print_graph(graph_matrix, matrix_size);

	for (int i = 0; i < matrix_size; ++i)
		delete[] graph_matrix[i];
	delete[] graph_matrix;

	return 0;
}