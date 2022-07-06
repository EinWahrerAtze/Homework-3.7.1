#include <iostream>
#define MODE 1

#ifndef MODE
#error MODE is not defined
#endif // !MODE

#if MODE == 1

double add(double a, double b)
{
	return a + b;
}

#endif

int main()
{
	setlocale(LC_ALL, "Russian");

#if MODE == 0

	std::wcout << L"Работаю в режиме тренировки.\n";
	return -1;

#elif MODE == 1

	double a = 0.0;
	double b = 0.0;

	std::wcout << L"Работаю в боевом режиме.\n";
	std::wcout << L"Введите число 1: ";

	while (!(std::wcin >> a))
	{
		std::wcin.clear();
		while (std::wcin.get() != L'\n')
			continue;
		std::wcout << L"Пожалуйста, введите число: ";
	}
	
	std::wcout << L"Введите число 2: ";

	while (!(std::wcin >> b))
	{
		std::wcin.clear();
		while (std::wcin.get() != L'\n')
			continue;
		std::wcout << L"Пожалуйста, введите число: ";
	}

	double result = add(a, b);
	std::wcout << L"Результат сложения: " << result << L'\n';

	return 0;
#else

	std::wcout << L"Неизвестный режим. Завершение работы.\n";
	return -2;

#endif
}