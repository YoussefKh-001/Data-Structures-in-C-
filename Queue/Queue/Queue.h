#pragma once
template<class T>
class Queue
{
private:
	T* arr;
	int capacity;
	int count;
	int front, back;
public:
	Queue();
	~Queue();
	void EnQueue(T x);
	T DeQueue();
	T Front();
	int size();
	bool isEmpty();
private:
	bool isFull();
	void expand();
};

