#include "Binary3.h"
#include "Binary3.cpp"
//#include "Binary3noTemplate.cpp"

#define FUNCION_TREE_CHEK
#define INITIALIZER_CHEK
//#define BALANCE_CHEK

void main()
{
	setlocale(LC_ALL, "");
#ifdef FUNCION_TREE_CHEK
	int n;
	std::cout << "Введите размер дерева: "; std::cin >> n;
	Tree<double> tree;
	filling(&tree, n);
	tree.print();
	measure("Минимальное значение в дереве: " , &tree, &Tree<double>::minValue);
	measure("Минимальное значение в дереве: " , &tree, &Tree<double>::minValue);
	measure("Максимальное значение в дереве: " , &tree, &Tree<double>::maxValue);
	measure("Сумма Элементов дерева:\t\t ", &tree, &Tree<double>::sum);
	measure("Кол-во элементов дерева :\t ", &tree, &Tree<double>::Count);
	measure("Средне-арифметическое элементов дерева :\t ", &tree, &Tree<double>::Avg);
	measure("Глубина дерева равна: \t", &tree, &Tree<double>::depth);
	tree.tree_print();
	system("PAUSE");

	double value;
	std::cout << "Введите удаляемое значение: "; std::cin >> value;
	tree.erase(value);
	tree.print();
	std::cout << std::endl << std::endl;
	std::cout << delimitr << std::endl;

	UniqueTree<double> u_tree;
	filling(&u_tree, n);
	u_tree.print();
	std::cout << std::endl;
	std::cout << "Минимальное значение в дереве: " << u_tree.minValue() << std::endl;
	std::cout << "Максимальное значение в дереве: " << u_tree.maxValue() << std::endl;
	std::cout << "Сумма Элементов дерева:\t\t " << u_tree.sum() << std::endl;
	std::cout << "Кол-во элементов дерева :\t " << u_tree.Count() << std::endl;
	std::cout << "Средне-арифметическое элементов дерева :\t " << u_tree.Avg() << std::endl;
	std::cout << "Глубина дерева равна: \t" << u_tree.depth() << std::endl;
#endif // FUNCION_TREE_CHEK
#ifdef INITIALIZER_CHEK
	Tree<int> tree2 = { 50, 25, 75, 16, 32, 64, 90, 28, 29};
	tree2.print();
	std::cout << std::endl;
	std::cout << "Глубина дерева: " << tree2.depth() << std::endl;
	tree2.tree_print();

#endif // INITIALIZER_CHEK

#ifdef BALANCE_CHEK
	setlocale(LC_ALL, "");
	Tree<int> tree2 = { 3, 5, 8, 13, 21, 34, 55, 89 };
	//Tree<int> tree2 = { 89, 55, 34, 21, 13, 8, 5, 3 };
	tree2.tree_print_my();
	tree2.balance_my();
	system("PAUSE");
	system("cls");
	tree2.tree_print_my();
#endif // BALANCE_CHEK

}