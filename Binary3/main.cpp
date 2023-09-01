#include <iostream>

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
			std::cout << "EConstructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class Tree;
		friend class UniqueTree;
	} *Root;
public:
	Element* gerRoot()
	{
		return Root;
	}
	Tree():Root(nullptr)
	{
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	~Tree()
	{
		std::cout << "TDestructor:\t" << this << std::endl;
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
	int minValue(Element* Root)
	{
		if (Root == nullptr)return 0;
		//if (Root->pLeft) minValue(Root->pLeft);
		//else return Root->Data;
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root)
	{
		if (Root == nullptr)return 0;
		//if (Root->pRight) maxValue(Root->pRight);
		//else return Root->Data;
		return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
	}
	int sum(Element* Root)
	{
		return Root == nullptr? 0 : Root->Data + sum(Root->pLeft) + sum(Root->pRight);
	}
	int Count(Element* Root)
	{	
		return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}
	double Avg()
	{
		return double(sum(this->Root)) / Count(this->Root);
	}
	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		std::cout << Root->Data << "\t";
		print(Root->pRight);
	}
	friend class UniqueTree;
};

class UniqueTree: public Tree
{
public: 
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

};
void main()
{
	setlocale(LC_ALL, "");
	int n;
	std::cout << "Введите размер дерева: "; std::cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.gerRoot());
	}
	tree.print(tree.gerRoot());
	std::cout << std::endl;
	std::cout << "Минимальное значение в дереве: " << tree.minValue(tree.gerRoot()) << std::endl;
	std::cout << "Минимальное значение в дереве: " << tree.maxValue(tree.gerRoot()) << std::endl;
	std::cout << "Сумма Элементов дерева:\t\t " << tree.sum(tree.gerRoot()) << std::endl;
	std::cout << "Кол-во элементов дерева :\t " << tree.Count(tree.gerRoot()) << std::endl;
	std::cout << "Средне-арифметическое элементов дерева :\t " << tree.Avg() << std::endl;

	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100, u_tree.gerRoot());
	}
	u_tree.print(u_tree.gerRoot());
	std::cout << std::endl;
	std::cout << "Минимальное значение в дереве: " << u_tree.minValue(u_tree.gerRoot()) << std::endl;
	std::cout << "Минимальное значение в дереве: " << u_tree.maxValue(u_tree.gerRoot()) << std::endl;
	std::cout << "Сумма Элементов дерева:\t\t " << u_tree.sum(u_tree.gerRoot()) << std::endl;
	std::cout << "Кол-во элементов дерева :\t " << u_tree.Count(u_tree.gerRoot()) << std::endl;
	std::cout << "Средне-арифметическое элементов дерева :\t " << u_tree.Avg() << std::endl;
}