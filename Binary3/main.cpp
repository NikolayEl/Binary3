#include <iostream>
#include<ctime>
#define delimitr "\n------------------------------------------------------\n"

template<class T> class Tree;
template<typename T> class UniqueTree;

template<typename T>void measure(const char* message, const Tree<T>* tree, T(Tree<T>::* member_function)()const);
template<typename T> void measure(const char* message, Tree<T>* tree, T(Tree<T>::* function)());
template<typename T, class B>void measure(const char* message, const Tree<T>* tree, B(Tree<T>::* member_function)()const);
template<class T, class B> void measure(const char* message, Tree<T>* tree, B(Tree<T>::* function)());
template<typename T>void filling(Tree<T>* tree, int n);
void filling(Tree<double>* tree, int n);

template<class T> class Tree
{
protected:
	class Element
	{
		T Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(T Data, Element* pLeft = nullptr, Element* pRight = nullptr);
		~Element()
		{
			
#ifdef DEBUG
			std::cout << "EDestructor:\t" << this << std::endl;
#endif // DEBUG

		}
		friend class Tree;
		template<typename T> friend class UniqueTree;
	} *Root;
public:
	Element* getRoot();
	Tree();
	Tree(const std::initializer_list<T>& arr);
	~Tree();
	void Clear();
	void insert(T Data);
	T minValue() const;
	T maxValue() const;
	T sum();
	int Count() const;
	int depth() const;
	void to_array(T*& arr, int& count);
	void erase(T Data);
	void erase_one_element(T Data);
	void balance_my();
	void balance_no_ideal();
	double Avg();
	void print() const;
	void tree_print_my() const;
	void depth_print(int depth)const;
	void tree_print()const;
private:
	//-----------------------------------------------------------------------------------------------
	void Destructor();

	void Clear(Element* Root);
	void insert(T Data, Element* Root);
	T minValue(Element* Root) const;
	T maxValue(Element* Root) const;
	T sum(Element* Root);
	int Count(Element* Root) const;
	int depth(Element* Root) const;
	void to_array(T*& arr, int& count, Element* Root);
	void erase(T Data, Element*& Root);
	void erase_one_element(T Data, Element*& Root);
	void balance_my(Element*& Root);
	void balance_no_ideal(Element*& Root);
	void print(Element* Root) const;
	void tree_print_my(Element* Root, int depth) const;
	void depth_print(Element* Root, int depth, int width)const;
	void tree_print(Element* Root, int width, int depth = 0) const;

	template<typename T> friend class UniqueTree;
	friend class Element;
	template<typename T> friend void measure(Tree<T>* tree, T(Tree<T>::* function)());
	
};

template<class T> Tree<T>::Element::Element(T Data, Element* pLeft, Element* pRight) :Data(Data), pLeft(pLeft), pRight(pRight)
{
#ifdef DEBUG
	std::cout << "EConstructor:\t" << this << std::endl;
#endif // DEBUG
}
////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T> typename Tree<T>::Element* Tree<T>::getRoot()
{
	return Root;
}
template<typename T> Tree<T>::Tree():Root(nullptr)
{
#ifdef DEBUG
	std::cout << "TConstructor:\t" << this << std::endl;
#endif // DEBUG

}
template<typename T> Tree<T>::Tree(const std::initializer_list<T>& arr) :Tree<T>::Tree()
{
	for (T i : arr) insert(i, Root);
#ifdef DEBUG
	std::cout << "IniConstructor:\t" << this << std::endl;
#endif // DEBUG
}
template<typename T>Tree<T>::~Tree()
{
	Clear(Root);
#ifdef DEBUG
	std::cout << "TDestructor:\t" << this << std::endl;
#endif // DEBUG
}
template<typename T> void Tree<T>::Clear()
{
	Clear(Root);
	Root = nullptr;
}
template<typename T> void Tree<T>::insert(T Data)
{
	return insert(Data, Root);
}
template<typename T> T Tree<T>::minValue() const
{
	return minValue(Root);
}
template<typename T> T Tree<T>::maxValue() const
{
	return maxValue(Root);
}
template<typename T> T Tree<T>::sum()
{
	return sum(Root);
}
template<typename T> int Tree<T>::Count() const
{
	return Count(Root);
}
template<typename T> int Tree<T>::depth() const
{
	return depth(Root);
}
template<typename T> void Tree<T>::to_array(T*& arr, int& count)
{
	return to_array(arr, count, Root);
}
template<typename T> void Tree<T>::erase(T Data)
{
	erase(Data, Root);
}
template<typename T> void Tree<T>::erase_one_element(T Data)
{
	return erase_one_element(Data, Root);
}
template<typename T> void Tree<T>::balance_my()
{
	return balance_my(Root);
}
template<typename T> void Tree<T>::balance_no_ideal()
{
	return balance_no_ideal(Root);
}
template<typename T> double Tree<T>::Avg()
{
	return double(sum(this->Root)) / Count(this->Root);
}
template<typename T> void Tree<T>::print() const
{
	return print(Root);
}
template<typename T> void Tree<T>::tree_print_my() const
{
	tree_print_my(Root, 0);
}
template<typename T> void Tree<T>::depth_print(int depth)const
{
	depth_print(Root, depth, 64);
}
template<typename T> void Tree<T>::tree_print()const
{
	tree_print(Root, 64);
}

//////////////////////////////////////////////////////////////////////////////////
template<typename T> void Tree<T>::Destructor()
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
	if (Root->pLeft || Root->pRight) Destructor();
}
template<typename T> void Tree<T>::Clear(Element* Root)
{
	if (Root == nullptr) return;
	Clear(Root->pLeft);
	Clear(Root->pRight);
	delete Root;
}
template<typename T> void Tree<T>::insert(T Data, Tree<T>::Element* Root)
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
template<typename T> T Tree<T>::minValue(Element* Root) const
{
	if (this->Root == nullptr)return 0;
	return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
}
template<typename T> T Tree<T>::maxValue(Element* Root) const
{
	if (this->Root == nullptr)return 0;
	return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
}
template<typename T> T Tree<T>::sum(Element* Root)
{
	return Root == nullptr ? 0 : Root->Data + (!Root->pLeft ? 0 : sum(Root->pLeft)) + (!Root->pRight ? 0 : sum(Root->pRight));
}
template<typename T> int Tree<T>::Count(Element* Root) const
{
	return Root == nullptr ? 0 : (!Root->pLeft ? 0 : Count(Root->pLeft)) + (!Root->pRight ? 0 : Count(Root->pRight)) + 1;
}
template<typename T> int Tree<T>::depth(Element* Root) const
{
	//return Root == nullptr ? 0 : (!Root->pLeft ? 1 : asjusted_depth(Root->pLeft) + 1) > (!Root->pRight ? 1 : 
	//	asjusted_depth(Root->pRight) + 1) ? (!Root->pLeft ? 1 : asjusted_depth(Root->pLeft) + 1): 
	//	(!Root->pRight ? 1 : asjusted_depth(Root->pRight) + 1);

	if (Root == nullptr) return 0;
	int l_depth = depth(Root->pLeft) + 1;
	int R_depth = depth(Root->pRight) + 1;
	return l_depth > R_depth ? l_depth : R_depth;

}
template<typename T> void Tree<T>::to_array(T*& arr, int& count, Element* Root)
{
	if (!Root)Root = getRoot();
	if (Root == nullptr)return;
	if (Root->pLeft) to_array(arr, count, Root->pLeft);
	arr[count] = Root->Data;
	count++;
	if (Root->pRight) to_array(arr, count, Root->pRight);
}
template<typename T> void Tree<T>::erase(T Data, Element*& Root)
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
template<typename T> void Tree<T>::erase_one_element(T Data, Element*& Root)
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
template<typename T> void Tree<T>::balance_my(Element*& Root)
{
	if (Root == nullptr) return;
	balance_my(Root->pLeft);
	balance_my(Root->pRight);
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
template<typename T> void Tree<T>::balance_no_ideal(Element*& Root)
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
template<typename T> void Tree<T>::print(Element* Root) const
{
	if (Root == nullptr)return;
	if (Root->pLeft) print(Root->pLeft);
	std::cout << Root->Data << "\t";
	if (Root->pRight)print(Root->pRight);
}
template<typename T> void Tree<T>::tree_print_my(Element* Root, int depth) const
{
	if (Root)
	{
		if (Root->pRight)tree_print_my(Root->pRight, depth + 1);
		for (int i = 0; i < depth; i++) std::cout << "	";
		std::cout << Root->Data << std::endl;
		if (Root->pLeft)tree_print_my(Root->pLeft, depth + 1);
	}
}
template<typename T> void Tree<T>::depth_print(Element* Root, int depth, int width)const
{
	if (!Root)
	{
		if (depth == 0)std::cout.width(width * 2);
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
template<typename T> void Tree<T>::tree_print(Element* Root, int width, int depth) const
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

//////////////////////////////////////////////////////////////////////////////////
template<typename T> class UniqueTree: public Tree<T>
{
public:
	void insert(T Data, Tree<T>::Element* Root)
	{
		if (Root == nullptr)Root = new Tree::Element(Data);
		if (!Root)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Tree::Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Tree::Element(Data);
			else insert(Data, Root->pRight);
		}
	};
	void insert(T Data)
	{
		return insert(Data, Tree<T>::Root);
	}

};

template<typename T>void measure(const char* message, const Tree<T> *tree, T(Tree<T>::*member_function)()const) //code with OA
{
	clock_t start = clock();
	T result = (tree->*member_function)();
	clock_t end = clock();
	std::cout << message << result << " выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
}

template<typename T> void measure(const char* message, Tree<T> *tree, T (Tree<T>::*function)())
{
	clock_t start = clock();
	T result =(tree->*function)();
	clock_t end = clock();
	std::cout << message << result << ", вычеслено за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";
}

template<typename T, class B>void measure(const char* message, const Tree<T>* tree, B(Tree<T>::* member_function)()const) //code with OA
{
	clock_t start = clock();
	B result = (tree->*member_function)();
	clock_t end = clock();
	std::cout << message << result << " выполнено за " << double(end - start) / CLOCKS_PER_SEC << " секунд.\n";
}
template<class T, class B> void measure(const char* message, Tree<T>* tree, B (Tree<T>::* function)())
{
	clock_t start = clock();
	B result = (tree->*function)();
	clock_t end = clock();
	std::cout << message << result << ", вычеслено за " << double(end - start) / CLOCKS_PER_SEC << " секунд\n";
}

template<typename T>void filling(Tree<T>* tree, int n)
{
	for (int i = 0; i < n; i++) tree->insert(rand() % 100);
}
void filling(Tree<double>* tree, int n)
{
	double number;
	for (int i = 0; i < n; i++)
	{
		number = rand() % 100;
		number /= 10;
		tree->insert(number);
	}
}



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