#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stack>

enum Error_Codes {
	File_Not_Open = 1,
	Invalid_Arg = 2,
	Out_Of_Range = 3
};

void depth_first_search(int** arr, int size, int point, bool* visited, std::stack<int> &order)
{

	visited[point - 1] = true;
	for (int i = 1; i <= size; ++i)
	{
		if (arr[point - 1][i - 1])
			{
				if (!visited[i - 1]) depth_first_search(arr, size, i, visited, order);
			}
	}
	order.push(point);
}

void graph_topologic_sort(int** arr, int size)
{
	bool* visited = new bool[size]();
	std::stack<int> graph_sort;

	for (int i = 1; i <= size; ++i)
			if (!visited[i - 1]) depth_first_search(arr, size, i, visited, graph_sort);

	while (!graph_sort.empty())
	{
		std::cout << graph_sort.top() << " ";
		graph_sort.pop();
	}

	std::cout << std::endl;
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

	graph_topologic_sort(graph_matrix, matrix_size);

	for (int i = 0; i < matrix_size; ++i)
		delete[] graph_matrix[i];
	delete[] graph_matrix;

	return 0;
}