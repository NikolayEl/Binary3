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
	void erase(int Data)
	{
		erase(Data, Root);
	}
	int minValue() const
	{
		return minValue(Root);
	}
	int maxValue() const
	{
		return maxValue(Root);
	}
	int sum()
	{
		return sum(Root);
	}
	int Count() const
	{
		return Count(Root);
	}
	double Avg()
	{
		return double(sum(this->Root)) / Count(this->Root);
	}
	int depth() const
	{
		return depth(Root);
	}
	void to_array(int*& arr, int& count)
	{
		return to_array(arr, count, Root);
	}
	void erase_one_element(int Data)
	{
		return erase_one_element(Data, Root);
	}
	void Clear()
	{
		Clear(Root);
		Root = nullptr;
	}
	//void balance_my()
	//{
	//	return balance_my(Root);
	//}
	//void balance()
	//{
	//	return balance(Root);
	//}
	void balance_my()
	{
		return balance_my(Root);
	}
	void balance_no_ideal()
	{
		return balance_no_ideal(Root);
	}
	void tree_print_my() const
	{
		tree_print_my(Root, 0);
	}
	void print() const
	{
		return print(Root);
	}
	void depth_print(int depth)const
	{
		depth_print(Root, depth, 64);
	}
	void tree_print()const
	{
		tree_print(Root, 64);
	}
private:
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
	int Count(Element* Root) const
	{	
		return Root == nullptr ? 0 : (!Root->pLeft ? 0 : Count(Root->pLeft)) + (!Root->pRight ? 0 : Count(Root->pRight)) + 1;
	}
	int depth(Element* Root) const
	{
		//return Root == nullptr ? 0 : (!Root->pLeft ? 1 : asjusted_depth(Root->pLeft) + 1) > (!Root->pRight ? 1 : 
		//	asjusted_depth(Root->pRight) + 1) ? (!Root->pLeft ? 1 : asjusted_depth(Root->pLeft) + 1): 
		//	(!Root->pRight ? 1 : asjusted_depth(Root->pRight) + 1);

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
	void erase(int Data, Element* &Root)
	{
		if (Root == nullptr) return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->pLeft == Root->pRight)
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (Count(Root->pLeft) > Count(Root->pRight))
				{
					Root->Data = maxValue(Root->pLeft);
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
					erase(minValue(Root->pRight), Root->pRight);
				}
			}
		}
	}
	void erase_one_element(int Data, Element*& Root)
	{
		if (Root == nullptr) return;
		if (Data == Root->Data)
		{
			if (Root->pLeft == Root->pRight)
			{
				delete Root;
				Root = nullptr;
				return;
			}
			else
			{
				if (Count(Root->pLeft) > Count(Root->pRight))
				{
					Root->Data = maxValue(Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
				}
			}
		}
		erase_one_element(Data, Root->pLeft);
		erase_one_element(Data, Root->pRight);
	}
	void balance_my(Element*& Root)
	{
		if (Root == nullptr) return;
		//balance_my(Root->pLeft);
		//balance_my(Root->pRight);
		if (Count(Root) % 2 != 0 ? Count(Root->pLeft) == Count(Root->pRight) : Count(Root->pLeft) == Count(Root->pRight) + 1)
		{
			return;
		}
		else
		{
			if (Count(Root->pLeft) > Count(Root->pRight))
			{
				if (Root->pRight)insert(Root->Data, Root->pRight);
				else Root->pRight = new Element(Root->Data);
				Root->Data = maxValue(Root->pLeft);
				erase(maxValue(Root->pLeft), Root->pLeft);
			}
			else
			{
				if (Root->pLeft)insert(Root->Data, Root->pLeft);
				else Root->pLeft = new Element(Root->Data);
				Root->Data = minValue(Root->pRight);
				erase(minValue(Root->pRight), Root->pRight);
			}
			balance_my(Root);
		}
	}
	void balance_no_ideal(Element*& Root)
	{
		if (Root == nullptr) return;
		balance_no_ideal(Root->pLeft);
		balance_no_ideal(Root->pRight);
		if (Count(Root) % 2 != 0 ? Count(Root->pLeft) == Count(Root->pRight) : Count(Root->pLeft) == Count(Root->pRight) + 1)
		{
			return;
		}
		else
		{
			if (Count(Root->pLeft) > Count(Root->pRight))
			{
				if (Root->pRight)insert(Root->Data, Root->pRight);
				else Root->pRight = new Element(Root->Data);
				Root->Data = maxValue(Root->pLeft);
				erase_one_element(maxValue(Root->pLeft), Root->pLeft);
			}
			else
			{
				if (Root->pLeft)insert(Root->Data, Root->pLeft);
				else Root->pLeft = new Element(Root->Data);
				Root->Data = minValue(Root->pRight);
				erase_one_element(minValue(Root->pRight), Root->pRight);
			}
			balance_no_ideal(Root);
		}
	}
	void tree_print_my(Element* Root, int depth) const
	{
		if (Root)
		{
			if(Root->pRight)tree_print_my(Root->pRight, depth + 1);
			for (int i = 0; i < depth; i++) std::cout << "	";
			std::cout << Root->Data << std::endl;
			if(Root->pLeft)tree_print_my(Root->pLeft, depth + 1);
		}
	}
	void print(Element* Root) const
	{
		if (Root == nullptr)return;
		if(Root->pLeft) print(Root->pLeft);
		std::cout << Root->Data << "\t";
		if (Root->pRight)print(Root->pRight);
	}
	void depth_print(Element* Root, int depth, int width)const
	{
		//adjusted_depth - заданная глубина
		if (!Root)
		{
			if(depth == 0)std::cout.width(width * 2);
			std::cout << "";
			return;
		}
		if (depth == 0)
		{
			std::cout.width(width);
			std::cout << Root->Data;
			std::cout.width(width);
			std::cout << " ";
		}
		depth_print(Root->pLeft, depth - 1, width);
		depth_print(Root->pRight, depth - 1, width);
	}
	void tree_print(Element* Root, int width, int depth = 0) const
	{
		if (!Root) return;
		if (depth >= this->depth())return;
		depth_print(Root, depth, width);
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		tree_print(Root, width / 2, depth + 1);
		depth++;

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

template<typename T>void measure(const char* message, const Tree *tree, T(Tree::*member_function)()const) //code with OA
{
	clock_t start = clock();
	T result = (tree->*member_function)();
	clock_t end = clock();
	std::cout << message << " выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
}

template<typename T> void measure(const char* message, Tree *tree, T (Tree::*function)())
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

//#define FUNCION_TREE_CHEK
//#define INITIALIZER_CHEK
#define BALANCE_CHEK

void main()
{
	setlocale(LC_ALL, "");
#ifdef FUNCION_TREE_CHEK
	int n;
	std::cout << "Введите размер дерева: "; std::cin >> n;
	Tree tree;
	std::cout << "Дерево заполнено за ";
	measure(tree, n, &filling);
	tree.print();
	measure("Минимальное значение в дереве: " , &tree, &Tree::minValue);
	measure("Максимальное значение в дереве: " , &tree, &Tree::maxValue);
	measure("Сумма Элементов дерева:\t\t ", &tree, &Tree::sum);
	measure("Кол-во элементов дерева :\t ", &tree, &Tree::Count);
	measure("Средне-арифметическое элементов дерева :\t ", &tree, &Tree::Avg);
	measure("Глубина дерева равна: \t", &tree, &Tree::asjusted_depth);
	system("PAUSE");

	int value;
	std::cout << "Введите удаляемое значение: "; std::cin >> value;
	tree.erase(value);
	tree.print();
	std::cout << std::endl << std::endl;
	//tree.tree_print_my();
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
	std::cout << "Глубина дерева равна: \t" << u_tree.asjusted_depth() << std::endl;
#endif // FUNCION_TREE_CHEK
#ifdef INITIALIZER_CHEK
	Tree tree2 = { 50, 25, 75, 16, 32, 64, 90, 28, 29};
	//std::cout << std::endl << std::endl;
	//tree2.tree_print_my();	
	//system("PAUSE");
	//system("cls");
	//tree2.balance_my();
	//tree2.tree_print_my();
	tree2.print();
	std::cout << std::endl;
	std::cout << "Глубина дерева: " << tree2.depth() << std::endl;
	//int depth;
	//std::cout << "Введите глубину дерева: "; std::cin >> depth;
	tree2.tree_print();

#endif // INITIALIZER_CHEK

#ifdef BALANCE_CHEK
	setlocale(LC_ALL, "");
	//Tree tree2 = { 3, 5, 8, 13, 21, 34, 55, 89 };
	Tree tree2 = { 89, 55, 34, 21, 13, 8, 5, 3 };
	tree2.tree_print();
	tree2.balance_my();
	system("PAUSE");
	system("cls");
	tree2.tree_print();
#endif // BALANCE_CHEK

}