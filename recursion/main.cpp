#include<iostream>

void elevator(int floor);

//#define ELEVATOR_CHEK
void main()
{
	setlocale(LC_ALL, "");
#ifdef ELEVATOR_CHEK
	int n;
	std::cout << "������� ����� �����: "; std::cin >> n;
	elevator(n);
#endif // ELEVATOR_CHEK


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