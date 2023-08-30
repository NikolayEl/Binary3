#include<iostream>

void elevator(int floor);
int Factorial(int n);

//#define ELEVATOR_CHEK
//#define FACTORIAL_CHEK
void main()
{
	setlocale(LC_ALL, "");
#ifdef ELEVATOR_CHEK
	int n;
	std::cout << "Введите номер этажа: "; std::cin >> n;
	elevator(n);
#endif // ELEVATOR_CHEK
#ifdef FACTORIAL_CHEK
	int n;
	std::cout << "Введите число: "; std::cin >> n;
	(n < 0) ? std::cout << "Вы ввели отрицательное число!" : std::cout << "Факториал числа " << n << " будет: " << Factorial(n);
#endif // FACTORIAL_CHEK


}
void elevator(int floor)
{
	if (floor == 0)
	{
		std::cout << "Вы в подвале" << std::endl;
		return;
	}
	std::cout << "Вы на " << floor << " этаже\n";
	elevator(floor > 0?floor - 1: floor + 1);
	std::cout << "Вы на " << floor << " этаже\n";
}
int Factorial(int n)
{
	if (n == 0) return 1;
	return n * Factorial(n - 1);
}
