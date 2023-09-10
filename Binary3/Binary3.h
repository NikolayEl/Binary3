#pragma once
#include <iostream>
#include<ctime>
using namespace std;

#define delimitr "\n------------------------------------------------------\n"

template<class T> class Tree;
template<typename T> class UniqueTree;

template<typename T>void measure(const char* message, const Tree<T>* tree, T(Tree<T>::* member_function)()const);
template<typename T> void measure(const char* message, Tree<T>* tree, T(Tree<T>::* function)());
template<class T, class B>void measure(const char* message, const Tree<T>* tree, B(Tree<T>::* member_function)()const);
template<class T, class B> void measure(const char* message, Tree<T>* tree, B(Tree<T>::* function)());
template<typename T> void filling(Tree<T>* tree, int n);

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
		~Element();
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

