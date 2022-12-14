#include <iostream>
#include <windows.h>
#include <algorithm>
#include <string>

int simple_string_hash(std::string st)
{
	int result = 0;
	std::for_each(st.begin(), st.end(), [&result](char& n) {	result += static_cast<int>(n); });

	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string user_input;

	do
	{
		std::cout << "Введите строку: ";
		std::getline(std::cin, user_input);
		std::cout << "Наивный хэш строки \"" << user_input << "\" = " << simple_string_hash(user_input) << std::endl;
	} while (user_input != "exit");

	return 0;
}