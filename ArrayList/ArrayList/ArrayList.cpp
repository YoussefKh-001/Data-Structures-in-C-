#include "ArrayList.h"
#include <assert.h>

template<class T>
ArrayList<T>::ArrayList()
{
	capacity = 5;
	count = 0;
	arr = new T[capacity];
}

template<class T>
ArrayList<T>::~ArrayList()
{
	delete[] arr;
}

template<class T>
int ArrayList<T>::size()
{
	return count;
}

template<class T>
bool ArrayList<T>::isEmpty()
{
	return (count == 0);
}

template<class T>
void ArrayList<T>::shrinkToFit()
{
	T* tmp = new T[count];

	for (int i = 0; i < count; i++)
		tmp[i] = arr[i];

	capacity = count;
	delete[] arr;
	arr = tmp;
}

template<class T>
void ArrayList<T>::push_back(T x)
{
	if (isFull())
		expand();

	arr[count] = x;
	count++;
}

template<class T>
void ArrayList<T>::insert(int index, T x)
{

	if (isFull())
		expand();

	assert(index < count && index >= 0);

	for (int i = count; i != index; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[index] = x;
	count++;
}

template<class T>
T ArrayList<T>::remove(int index)
{
	assert(!isEmpty() && index < count && index >= 0);

	T tmp = arr[index];
	for (int i = index; i != count-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	count--;
	return tmp;
}

template<class T>
T ArrayList<T>::pop()
{
	assert(!isEmpty());

	count--;
	return arr[count];
}

template<class T>
T* ArrayList<T>::begin()
{
	return arr;
}

template<class T>
T* ArrayList<T>::rbegin()
{
	return arr + count - 1;
}

template<class T>
T* ArrayList<T>::end()
{
	return arr + count;
}

template<class T>
T* ArrayList<T>::rend()
{
	return arr - 1;
}

template<class T>
T& ArrayList<T>::operator[](int index)
{
	assert(index < count && index >= 0);
	return arr[index];
}

template<class T>
bool ArrayList<T>::isFull()
{
	return (count == capacity);
}

template<class T>
void ArrayList<T>::expand()
{
	T* tmp = new T[capacity * 2];

	for (int i = 0; i < count; i++)
		tmp[i] = arr[i];

	capacity *= 2;
	delete[] arr;
	arr = tmp;
}
