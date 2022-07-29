#include <iostream>
#include <windows.h>
#include <algorithm>
#include <string>

bool is_prime(int n)
{
	bool result = true;

	if (n <= 1) result = false;

	int i = 2;
	double sqi = sqrt(n);
	while ((result) && ( i <= sqi))
		{
			if (n % i == 0) result = false;
			++i;
		}

	if (!result) std::cout << "Введенное число не является простым. Повторите ввод." << std::endl;

	return result;
}

int real_string_hash(std::string st, int prime, int modulo)
{
	int result = 0;
	int multipl = 1;
	std::for_each(st.begin(), st.end(), [&result, &prime, &multipl](char& n) {	result += static_cast<int>(n) * multipl; multipl *= prime; });

	result %= modulo;
	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string user_input;
	int p = 0;
	int n = 0;

	do
	{
		std::cout << "Введите p: ";
		std::cin >> user_input;
		try
		{
			p = std::stoi(user_input);
		}
		catch (std::invalid_argument const& ex)
		{
			std::cout << "Неправильно введеное числовое значение." << std::endl;
		}
		catch (std::out_of_range const& ex)
		{
			std::cout << "Введенное число слишком велико." << std::endl;
		}
	} while (!is_prime(p));

	std::cout << "Введите n: ";
	std::cin >> user_input;
	try
	{
		n = std::stoi(user_input);
	}
	catch (std::invalid_argument const& ex)
	{
		std::cout << "Неправильно введеное числовое значение." << std::endl;
	}
	catch (std::out_of_range const& ex)
	{
		std::cout << "Введенное число слишком велико." << std::endl;
	}
	std::cin.ignore();

	do
	{
		std::cout << "Введите строку: ";
		std::getline(std::cin, user_input);
		std::cout << "Хэш строки \"" << user_input << "\" = " << real_string_hash(user_input, p, n) << std::endl;
	} while (user_input != "exit");

	return 0;
}