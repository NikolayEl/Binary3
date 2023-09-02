#include <iostream>
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
	Element* getRoot()
	{
		return Root;
	}
	Tree():Root(nullptr)
	{
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	~Tree()
	{
		Destructor();
		delete Root;
		std::cout << "TDestructor:\t" << this << std::endl;
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
	void insert(int Data, Element* Root = nullptr)
	{
		if (!Root) Root = getRoot();
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
	int minValue(Element* Root = nullptr)
	{
		if(!Root)Root = getRoot();
		if (this->Root == nullptr)return 0;
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root = nullptr)
	{
		if (!Root)Root = getRoot();
		if (this->Root == nullptr)return 0;
		return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
	}
	int sum(Element* Root = nullptr)
	{
		if (!Root)Root = getRoot();
		return Root == nullptr? 0 : Root->Data + (!Root->pLeft? 0 : sum(Root->pLeft)) + (!Root->pRight ? 0 : sum(Root->pRight));
	}
	int Count(Element* Root = nullptr)
	{	
		if (!Root)Root = getRoot();
		return Root == nullptr ? 0 : (!Root->pLeft ? 0 : Count(Root->pLeft)) + (!Root->pRight ? 0 : Count(Root->pRight)) + 1;
	}
	double Avg()
	{
		return double(sum(this->Root)) / Count(this->Root);
	}
	int depth(Element* Root = nullptr)
	{
		if (!Root) Root = getRoot();
		return Root == nullptr ? 0 : (!Root->pLeft ? 1 : depth(Root->pLeft) + 1) > (!Root->pRight ? 1 : 
			depth(Root->pRight) + 1) ? (!Root->pLeft ? 1 : depth(Root->pLeft) + 1): 
			(!Root->pRight ? 1 : depth(Root->pRight) + 1);
	}
	void to_array(int*& arr, int& count, Element* Root = nullptr)
	{
		if (!Root)
		{
			Root = getRoot();
		}
		if (Root == nullptr)return;
		if (Root->pLeft) to_array(arr, count, Root->pLeft);
		arr[count] = Root->Data;
		count++;
		if (Root->pRight) to_array(arr, count, Root->pRight);
	}
	void erase(int Data, Element* Root = nullptr)
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
		//std::cout << std::endl << "������ ����� = " << Root->Data << std::endl;
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
	void print(Element* Root = nullptr)
	{
		if (!Root)Root = getRoot();
		if (Root == nullptr)return;
		if(Root->pLeft) print(Root->pLeft);
		std::cout << Root->Data << "\t";
		if (Root->pRight)print(Root->pRight);
	}
	friend class UniqueTree;
	friend class Element;
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
	std::cout << "������� ������ ������: "; std::cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();
	std::cout << std::endl;
	std::cout << "����������� �������� � ������: " << tree.minValue() << std::endl;
	std::cout << "������������ �������� � ������: " << tree.maxValue() << std::endl;
	std::cout << "����� ��������� ������:\t\t " << tree.sum() << std::endl;
	std::cout << "���-�� ��������� ������ :\t " << tree.Count() << std::endl;
	std::cout << "������-�������������� ��������� ������ :\t " << tree.Avg() << std::endl;
	std::cout << "������� ������ �����: \t" << tree.depth() << std::endl;
	std::cout << "������� ��������� ��������: "; int erase_number; std::cin >> erase_number;
	tree.erase(erase_number);
	tree.print();

	std::cout << delimitr << std::endl;

	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100, u_tree.getRoot());
	}
	u_tree.print();
	std::cout << std::endl;
	std::cout << "����������� �������� � ������: " << u_tree.minValue() << std::endl;
	std::cout << "������������ �������� � ������: " << u_tree.maxValue() << std::endl;
	std::cout << "����� ��������� ������:\t\t " << u_tree.sum() << std::endl;
	std::cout << "���-�� ��������� ������ :\t " << u_tree.Count() << std::endl;
	std::cout << "������-�������������� ��������� ������ :\t " << u_tree.Avg() << std::endl;
}