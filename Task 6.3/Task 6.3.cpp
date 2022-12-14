#include <iostream>
#include <windows.h>
#include <algorithm>
#include <string>

int hash(std::string st)
{
	int result = 0;
	std::for_each(st.begin(), st.end(), [&result](char& n) {	result += static_cast<int>(n); });

	return result;
}

int find_substring_light_rabin_karp(std::string st1, std::string st2)
{
	int result = -1;
	int st1_hash = 0;
	int st2_hash = hash(st2);
	int st1l = st1.length();
	int st2l = st2.length();

	for (int i = 0; i <= st1l - st2l; ++i)
	{
		if (0 == i)
		{
			std::string tmp = st2;
			for (int i = 0; i < st2l; ++i)
				tmp[i] = st1[i];
			st1_hash = hash(tmp);
		}
		else
		{
			st1_hash -= static_cast<int>(st1[i - 1]);
			st1_hash += static_cast<int>(st1[i + st2l - 1]);
		}

		if (st1_hash == st2_hash)
		{
		bool correct = true;
		for (int j = 0; j < st2l; ++j)
			if (st1[i + j] != st2[j])
			{
				correct = false;
				break;
			}
		 if (correct) return i;
		}
		else continue;
	}

	return result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string user_input;

	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::getline(std::cin, user_input);
	std::string total_string = user_input;

	do
	{
		std::cout << "Введите подстроку, которую нужно найти: ";
		std::getline(std::cin, user_input);
		int tmp = find_substring_light_rabin_karp(total_string, user_input);
		if (tmp != -1)
			std::cout << "Подстрока \"" << user_input << "\" найдена по индексу " << tmp << std::endl;
		else std::cout << "Подстрока \"" << user_input << "\" не найдена" << std::endl;
	} while (user_input != "exit");

	return 0;
}