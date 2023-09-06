#include <iostream>
#include<ctime>
#define delimitr "\n------------------------------------------------------\n"

class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			std::cout << "EConstructor:\t" << this << std::endl;
#endif // DEBUG

		}
		~Element()
		{
			
#ifdef DEBUG
			std::cout << "EDestructor:\t" << this << std::endl;
#endif // DEBUG

		}
		friend class Tree;
		friend class UniqueTree;
	} *Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree():Root(nullptr)
	{
#ifdef DEBUG
		std::cout << "TConstructor:\t" << this << std::endl;
#endif // DEBUG

	}
	Tree(const std::initializer_list<int>& arr) :Tree()
	{
		for (int i : arr) insert(i, Root);
#ifdef DEBUG
		std::cout << "IniConstructor:\t" << this << std::endl;
#endif // DEBUG

	}
	~Tree()
	{
		Clear(Root);
#ifdef DEBUG
		std::cout << "TDestructor:\t" << this << std::endl;
#endif // DEBUG

	}
	void insert(int Data)
	{
		return insert(Data, Root);
	}
	int minValue()
	{
		return minValue(Root);
	}
	int maxValue()
	{
		return maxValue(Root);
	}
	int sum()
	{
		return sum(Root);
	}
	int result()
	{
		return Root->Data;
	}
	int Count()
	{
		return Count(Root);
	}
	double Avg()
	{
		return double(sum(this->Root)) / Count(this->Root);
	}
	int depth()
	{
		return depth(Root);
	}
	void to_array(int*& arr, int& count)
	{
		return to_array(arr, count, Root);
	}
	void erase(int Data)
	{
		return erase(Data, Root);
	}
	void Clear()
	{
		Clear(Root);
		Root = nullptr;
	}
	void balance()
	{
		return balance(Root);
	}
	void tree_print() const
	{
		tree_print(Root, 0);
	}
	void print() const
	{
		return print(Root);
	}
//private:
	//-----------------------------------------------------------------------------------------------
	void Clear(Element* Root)
	{
		if (Root == nullptr) return;
		Clear(Root->pLeft);
		Clear(Root->pRight);
		delete Root;
	}

	void Destructor()
	{
		if (Root->pLeft)
		{
			Element* temp = Root->pLeft;
			Root->pLeft = Root->pLeft->pLeft;
			delete temp;
		}
		if (Root->pRight)
		{
			Element* temp = Root->pRight;
			Root->pRight = Root->pRight->pRight;
			delete temp;
		}
		if(Root->pLeft || Root->pRight) Destructor();
	}


	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (!Root)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	int minValue(Element* Root) const
	{
		if (this->Root == nullptr)return 0;
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root) const
	{
		if (this->Root == nullptr)return 0;
		return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
	}
	int sum(Element* Root)
	{
		return Root == nullptr? 0 : Root->Data + (!Root->pLeft? 0 : sum(Root->pLeft)) + (!Root->pRight ? 0 : sum(Root->pRight));
	}
	int Count(Element* Root)
	{	
		return Root == nullptr ? 0 : (!Root->pLeft ? 0 : Count(Root->pLeft)) + (!Root->pRight ? 0 : Count(Root->pRight)) + 1;
	}
	int depth(Element* Root) const
	{
		//return Root == nullptr ? 0 : (!Root->pLeft ? 1 : depth(Root->pLeft) + 1) > (!Root->pRight ? 1 : 
		//	depth(Root->pRight) + 1) ? (!Root->pLeft ? 1 : depth(Root->pLeft) + 1): 
		//	(!Root->pRight ? 1 : depth(Root->pRight) + 1);

		if (Root == nullptr) return 0;
		int l_depth = depth(Root->pLeft) + 1;
		int R_depth = depth(Root->pRight) + 1;
		return l_depth > R_depth ? l_depth : R_depth;
			
	}
	void to_array(int*& arr, int& count, Element* Root)
	{
		if (!Root)Root = getRoot();
		if (Root == nullptr)return;
		if (Root->pLeft) to_array(arr, count, Root->pLeft);
		arr[count] = Root->Data;
		count++;
		if (Root->pRight) to_array(arr, count, Root->pRight);
	}
	void erase(int Data, Element* Root)
	{
		if (!Root) Root = getRoot();
		int count = 0;
		int* array = new int[Count()];
		to_array(array, count);
		print();
		Destructor();
		print();
		int average = (count % 2 == 0? (count / 2): (count / 2 + 1));
		Root->Data = array[average];
		for (int i = average - 1; i > -1; i--)
		{
			if (array[i] == Data) continue;
			insert(array[i]);
		}
		for (int i = average + 1; i < count; i++) 
		{
			if (array[i] == Data) continue;
			insert(array[i]);
		}
		delete[] array;
		//std::cout << std::endl << "Корень равен = " << Root->Data << std::endl;
		//if (!Root) Root = getRoot();
		//if (Root->pLeft->Data == Data && Root->pRight->Data == Data)
		//{
		//	Element* temp;
		//	if (Root->pLeft?Root->pLeft->Data == Data: 0) 
		//	{
		//		temp = Root->pLeft;
		//		if (Root->pLeft->pRight)
		//		{
		//			Root->pLeft = Root->pLeft->pRight;
		//			Root->pLeft->pLeft = temp->pLeft;
		//			delete temp;
		//		}
		//		else if (Root->pLeft->pLeft)
		//		{

		//		}
		//	}
		//	else if (Root->pRight ? Root->pRight->Data == Data : 0)
		//	{
		//		temp = Root->pRight;
		//		if (Root->pRight->pLeft)
		//		{
		//			Root->pRight = Root->pRight->pLeft;
		//			Root->pRight->pRight = temp->pRight;
		//			delete temp;
		//		}
		//	}
		//}
		//if (Root->pLeft) erase(Data, Root->pLeft);
		//else return;
		//if (Root->pRight) erase(Data, Root->pRight);
		//else return;
	}
	void balance(Element* Root)
	{
		if (!Root) Root = getRoot();
		int count = 0;
		int* array = new int[Count()];
		to_array(array, count);
		print();
		Destructor();
		print();
		int average = (count % 2 == 0 ? (count / 2) : (count / 2 + 1)) + 1;
		Root->Data = array[average];
		for (int i = average - 1; i > -1; i--)
		{
			if (i % 4 != 0) continue;
			insert(array[i]);
		}
		for (int i = average - 1; i > -1; i--)
		{
			if (i % 4 == 0) continue;
			insert(array[i]);
		}
		for (int i = average + 1; i < count; i++)
		{
			if (i % 4 != 0) continue;
			insert(array[i]);
		}	
		for (int i = average + 1; i < count; i++)
		{
			if (i % 4 == 0) continue;
			insert(array[i]);
		}
		delete[] array;
	}
	void tree_print(Element* Root, int depth) const
	{
		if (Root)
		{
			if(Root->pRight)tree_print(Root->pRight, depth + 1);
			for (int i = 0; i < depth; i++) std::cout << "	";
			std::cout << Root->Data << std::endl;
			if(Root->pLeft)tree_print(Root->pLeft, depth + 1);
		}
	}
	void print(Element* Root) const
	{
		if (Root == nullptr)return;
		if(Root->pLeft) print(Root->pLeft);
		std::cout << Root->Data << "\t";
		if (Root->pRight)print(Root->pRight);
	}
	friend class UniqueTree;
	friend class Element;
	template<typename T> friend void measure(Tree* tree, T(Tree::* function)());
	
};

class UniqueTree: public Tree
{
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (!Root)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
public: 
	void insert(int Data)
	{
		return insert(Data, Root);
	}

};
template<typename T> void measure(Tree* tree, T (Tree::*function)())
{
	clock_t start = clock();
	T result =(tree->*function)();
	clock_t end = clock();
	std::cout << result << ", вычеслено за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";
}
typedef void (*func)(Tree& tree, int n);
void measure(Tree& tree, int n, func function)
{
	clock_t start = clock();
	function(tree, n);
	clock_t end = clock();
	std::cout << " " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";
}
void filling(Tree& tree, int n)
{
	for (int i = 0; i < n; i++) tree.insert(rand() % 100);
}

#define FUNCION_TREE_CHEK
//#define INITIALIZER_CHEK
//#define BALANCE_CHEK

void main()
{
	setlocale(LC_ALL, "");
#ifdef FUNCION_TREE_CHEK
	int n;
	std::cout << "Введите размер дерева: "; std::cin >> n;
	Tree tree;
	std::cout << "Дерево заполнено за ";
	measure(tree, n, &filling);

	std::cout << "Минимальное значение в дереве: ";
	measure(&tree, &Tree::minValue);

	std::cout << "Максимальное значение в дереве: ";
	measure(&tree, &Tree::maxValue);
	
	std::cout << "Сумма Элементов дерева:\t\t ";
	measure(&tree, &Tree::sum);

	std::cout << "Кол-во элементов дерева :\t ";
	measure(&tree, &Tree::Count);

	std::cout << "Средне-арифметическое элементов дерева :\t ";
	measure(&tree, &Tree::Avg);

	std::cout << "Глубина дерева равна: \t";
	measure(&tree, &Tree::depth);
	system("PAUSE");

	std::cout << delimitr << std::endl;

	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100);
	}
	//u_tree.print();
	std::cout << std::endl;
	std::cout << "Минимальное значение в дереве: " << u_tree.minValue() << std::endl;
	std::cout << "Максимальное значение в дереве: " << u_tree.maxValue() << std::endl;
	std::cout << "Сумма Элементов дерева:\t\t " << u_tree.sum() << std::endl;
	std::cout << "Кол-во элементов дерева :\t " << u_tree.Count() << std::endl;
	std::cout << "Средне-арифметическое элементов дерева :\t " << u_tree.Avg() << std::endl;
	std::cout << "Глубина дерева равна: \t" << u_tree.depth() << std::endl;
#endif // FUNCION_TREE_CHEK
#ifdef INITIALIZER_CHEK
	Tree tree2 = { 50, 25, 75, 16, 32, 64, 90, 28 };
	tree2.print();
	std::cout << "Глубина дерева: " << tree2.depth() << std::endl;
	//std::cout << std::endl << std::endl;
	//tree2.tree_print();
#endif // INITIALIZER_CHEK

#ifdef BALANCE_CHEK
	setlocale(LC_ALL, "");
	int n;
	std::cout << "Введите размер дерева: "; std::cin >> n;
	Tree tree2 = { 3, 5, 8, 13, 21, 34, 55, 89 };
	//for (int i = 0; i < n; i++) tree2.insert(rand() % 100);
	//tree2.print();
	system("PAUSE");
	system("cls");
	tree2.tree_print();
	tree2.balance();
	system("PAUSE");
	system("cls");
	tree2.tree_print();
#endif // BALANCE_CHEK

}