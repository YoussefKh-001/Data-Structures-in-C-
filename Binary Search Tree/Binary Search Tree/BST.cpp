#include "BST.h"
#include<iostream>
using namespace std;
template<class T>
Node<T>::Node(T value)
{
	this->value = value;
	left = right = nullptr;
}
template<class T>
Node<T>::~Node()
{
	delete left;
	delete right;
}

template<class T>
BST<T>::BST()
{
	root = nullptr;
	count = 0;
}

template<class T>
BST<T>::~BST()
{
	delete root;
}

template<class T>
bool BST<T>::contain(T x)
{
	Node<T> tmp = root;
	while (tmp != nullptr)
	{
		if (x > tmp->value)
		{
			tmp = tmp->right;
		}
		else if (x < tmp->value)
		{
			tmp = tmp->right;
		}
		else
		{
			return true;
		}
	}
	return false;
}

template<class T>
void BST<T>::insert(T x)
{
	Node<T>* tmp = root;
	Node<T>* newNode = new Node<T>(x);
	if (root == nullptr)
	{
		root = newNode;
		return;
	}
	while (true)
	{
		if (x > tmp->value)
		{
			if (tmp->right == nullptr)
			{
				tmp->right = newNode;
				break;
			}
			else
				tmp = tmp->right;
		}
		else if (x < tmp->value)
		{
			if (tmp->left == nullptr)
			{
				tmp->left = newNode;
				break;
			}
			else
				tmp = tmp->left;
		}
		else
		{
			throw "Value Already Exist";
		}
	}
}

template<class T>
void BST<T>::Traverse(std::string order)
{
	if (order == "1+2")
		InOrder(root);
	else if (order == "+12")
		PreOrder(root);
	else if (order == "12+")
		PostOrder(root);
	
}

template<class T>
void BST<T>::PreOrder(Node<T>* tmp)
{
	//Root Left Right
	if (tmp == nullptr)
		return;
	//Root
	cout << tmp->value << " ";
	//Left
	PreOrder(tmp->left);
	//Right
	PreOrder(tmp->right);
}

template<class T>
void BST<T>::InOrder(Node<T>* tmp)
{
	//Left Root Right
	if (tmp == nullptr)
		return;
	//Left
	InOrder(tmp->left);
	//Root
	cout << tmp->value << " ";
	//Right
	InOrder(tmp->right);
}

template<class T>
void BST<T>::PostOrder(Node<T>* tmp)
{
	//Left Right Root;
	if (tmp == nullptr)
		return;
	//Left
	PostOrder(tmp->left);
	//Right
	PostOrder(tmp->right);
	//Root
	cout << tmp->value << " ";
}
