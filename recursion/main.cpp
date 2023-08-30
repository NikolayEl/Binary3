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
	std::cout << "������� ����� �����: "; std::cin >> n;
	elevator(n);
#endif // ELEVATOR_CHEK
#ifdef FACTORIAL_CHEK
	int n;
	std::cout << "������� �����: "; std::cin >> n;
	(n < 0) ? std::cout << "�� ����� ������������� �����!" : std::cout << "��������� ����� " << n << " �����: " << Factorial(n);
#endif // FACTORIAL_CHEK


}
void elevator(int floor)
{
	if (floor == 0)
	{
		std::cout << "�� � �������" << std::endl;
		return;
	}
	std::cout << "�� �� " << floor << " �����\n";
	elevator(floor > 0?floor - 1: floor + 1);
	std::cout << "�� �� " << floor << " �����\n";
}
int Factorial(int n)
{
	if (n == 0) return 1;
	return n * Factorial(n - 1);
}
