#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

enum Error_Codes {
	File_Not_Open = 1,
	Invalid_Arg = 2,
	Out_Of_Range = 3
};

bool depth_first_search(int** arr, int size, int point, bool* visited, int previous)
{
	visited[point - 1] = true;
	for (int i = 1; i <= size; ++i)
		if (arr[point - 1][i - 1])
		{
			if (!visited[i - 1]) return (depth_first_search(arr, size, i, visited, point));
			else if (i != previous) return true;
		}
	return false;
}

void search_cycles(int** arr, int size, int point)
{
	bool* visited = new bool[size]();
	int previous = -1;

	if (depth_first_search(arr, size, point, visited, previous)) std::cout << "В графе есть цикл!";
	else std::cout << "Циклов нет!";

	delete[] visited;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const std::string file_name = "input1.txt";
	//const std::string file_name = "input2.txt";

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

	int starting_point = 1; // строго от 1 до 7

	search_cycles(graph_matrix, matrix_size, starting_point);

	for (int i = 0; i < matrix_size; ++i)
		delete[] graph_matrix[i];
	delete[] graph_matrix;

	return 0;
}
