#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

enum Error_Codes {
	File_Not_Open = 1,
	Invalid_Arg = 2,
	Out_Of_Range = 3
};

void depth_first_search(int** arr, int size, int point, int* cids, int cid)
{
	cids[point - 1] = cid;
	for (int i = 1; i <= size; ++i)
		if (arr[point - 1][i - 1] && !cids[i - 1]) depth_first_search(arr, size, i, cids, cid);
}

void calc_components(int** arr, int size)
{
	int* cids = new int[size]();
	int cid = 1;

	for (int point = 1; point < size; ++point)
		if (0 == cids[point - 1])
		{
			depth_first_search(arr, size, point, cids, cid);
			++cid;
		}

	std::cout << "Принадлежность вершин компонентам связности :" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << i + 1 << " - " << cids[i] << std::endl;
	}
	std::cout << "Количество компонентов связности в графе : " << cid-1 << std::endl;

	delete[] cids;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//const std::string file_name = "input1.txt";
	const std::string file_name = "input2.txt";

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

	calc_components(graph_matrix, matrix_size);

	for (int i = 0; i < matrix_size; ++i)
		delete[] graph_matrix[i];
	delete[] graph_matrix;

	return 0;
}