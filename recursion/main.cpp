#include<iostream>

void elevator(int floor);
int Factorial(int n);
double Power(double a, int n);

//#define ELEVATOR_CHEK
//#define FACTORIAL_CHEK
//#define POWER_CHEK
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
#ifdef POWER_CHEK
	double a;
	int n;
	std::cout << "������� �����: "; std::cin >> a;
	std::cout << "������� ������� �����: "; std::cin >> n;
	(n < 0) ? std::cout << "��������� ���������� ������ ������������� ��������!" :
		std::cout << "����� " << a << " � ������� " << n << " ����������: " << Power(a, n);
#endif // POWER_CHEK

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

double Power(double a, int n)
{
	if (n == 0) return 1;
	return a * Power(a, n - 1);
}
