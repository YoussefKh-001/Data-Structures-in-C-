#pragma once
template<class T>
class ArrayList
{
private:
	T* arr;
	int count;
	int capacity;

public:
	ArrayList();
	~ArrayList();
	int size();
	bool isEmpty();
	void shrinkToFit();
	void push_back(T x);
	void insert(int index, T x);
	T remove(int index);
	T pop();
	T* begin();
	T* rbegin();
	T* end();
	T* rend();
	T operator [](int index);
private:
	bool isFull();
	void expand();
};


