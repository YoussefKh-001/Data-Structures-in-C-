#include "Stack.h"
#include <assert.h>
template<class T>
Stack<T>::Stack()
{
	capacity = 5;
	count = 0;
	arr = new T[capacity];
}

template<class T>
Stack<T>::~Stack()
{
	delete[] arr;
}

template<class T>
void Stack<T>::push(T x)
{
	if (isFull())
		expand();

	arr[count] = x;
	count++;
}

template<class T>
T Stack<T>::pop()
{
	assert(!isEmpty());
	count--;
	return arr[count];
}

template<class T>
T Stack<T>::top()
{
	assert(!isEmpty());
	return arr[count - 1];
}

template<class T>
int Stack<T>::size()
{
	return count;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return (count == 0);
}

template<class T>
bool Stack<T>::isFull()
{
	return (count == capacity);
}

template<class T>
void Stack<T>::expand()
{
	T* tmp = new T[capacity * 2];
	for (int i = 0; i < count; i++)
		tmp[i] = arr[i];

	delete[] arr;
	arr = tmp;
}