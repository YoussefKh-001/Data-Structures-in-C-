#pragma once
template<class T>
class node {
public:	
	T value;
	node<T>* next;
	node();
	~node();
};

template<class T>
class LinkedList
{
private:
	node<T>* first;
	node<T>* last;
	int count;
public:
	LinkedList();
	~LinkedList();
	int size();
	void push(T x);
	void insertAt(int index, T x);
	T pop();
	T removeAt(int index);
	T& operator[] (int index);

};

