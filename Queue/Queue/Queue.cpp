#include "Queue.h"
#include<iostream>
template<class T>
Queue<T>::Queue()
{
	count = 0;
	capacity = 5;
	front = back = -1;
	arr = new T[capacity];
}

template<class T>
Queue<T>::~Queue()
{
	delete[] arr;
}

template<class T>
void Queue<T>::EnQueue(T x)
{
	
	if (isFull())
		expand();
	if (count == 0)
	{
		front = back = 0;
		arr[0] = x;
	}
	else {
		back = (back + 1) % capacity;
		arr[back] = x;
	}
	count++;
}

template<class T>
T Queue<T>::DeQueue()
{
	T tmp = arr[front];
	if (count == 1)
		front = back = -1;
	else
		front = (front + 1) % capacity;

	count--;
	
	return tmp;
}

template<class T>
T Queue<T>::Front()
{
	return arr[front];
}

template<class T>
int Queue<T>::size()
{
	return count;
}

template<class T>
bool Queue<T>::isEmpty()
{
	return (count == 0);
}

template<class T>
bool Queue<T>::isFull()
{
	return (count == capacity);
}

template<class T>
void Queue<T>::expand()
{
	T* tmp = new T[capacity*2];
	for (int i = 0, j = front; i < count; i++, j = (j+1)%capacity)
	{
		tmp[i] = arr[j];
		if (j == back)
			break;
	}
	front = 0; 
	back = count - 1;
	delete[] arr;
	arr = tmp;
	capacity *= 2;
}
