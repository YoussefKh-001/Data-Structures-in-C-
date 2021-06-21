#pragma once
#include<string>
template<class T>
class Node
{
public:
	T value;
	Node<T>* left, *right;
	Node(T value);
	~Node();
};

template<class T>
class BST
{
private:
	Node<T>* root;
	int count;

public:
	BST();
	~BST();
	bool contain(T x);
	void insert(T x);
	/// Pre Order -> "+12"
	/// Post Order -> "12+"
	/// In Order -> "1+2"
	void Traverse(std::string order); 
	void PreOrder(Node<T>* tmp);
	void InOrder(Node<T>* tmp);
	void PostOrder(Node<T>* tmp);
};

