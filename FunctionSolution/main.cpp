#include<iostream>

void hello()
{
	std::cout << "Hello" << std::endl;
}
int sum(int a, int b)
{
	return a + b;
}
void main()
{
	void (*p_hello)() = hello; //void* - void pointer (pointer in 'void', может хранить адрес абсолютно любого типа)
	//при разыменовании void-pointer-a обязательно нужно преобразовывать его в целевой тип
	p_hello();
	int (*p_sum)(int, int) = sum;
	//std::cout << sum(2, 3) << std::endl;
	std::cout << sum << std::endl;
	std::cout << p_sum(2, 3) << std::endl;
}