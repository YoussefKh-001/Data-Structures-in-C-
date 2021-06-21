#pragma once
template<class T>
class Stack
{
private:
	T* arr;
	int capacity;
	int count;

public:
	Stack();
	~Stack();
	void push(T x);
	T pop();
	T top();
	int size();
	bool isEmpty();
private:
	bool isFull();
	void expand();
};

