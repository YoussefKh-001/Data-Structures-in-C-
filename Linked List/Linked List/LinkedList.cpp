#include "LinkedList.h"
#include <assert.h>
template<class T>
node<T>::node()
{
	next = nullptr;
}
template<class T>
node<T>::~node()
{
	delete next;
}


template<class T>
LinkedList<T>::LinkedList()
{
	first = last = nullptr;
	count = 0;
}
template<class T>
LinkedList<T>::~LinkedList()
{
	delete first;
}

template<class T>
int LinkedList<T>::size()
{
	return count;
}
template<class T>
void LinkedList<T>::push(T x)
{
	node<T>* newNode = new node<T>();
	newNode->value = x;
	if (count == 0)
	{
		first = last = newNode;
	}
	else {
		last->next = newNode;
		last = last->next;
	}

	count++;
}
template<class T>
void LinkedList<T>::insertAt(int index, T x)
{
	assert(index >= 0 && index < count);

	node<T>* newNode = new node<T>();
	newNode->value = x;

	if (index == 0)
	{
		newNode->next = first;
		first = newNode;
	}
	else
	{
		node<T>* tmp = first;
		for (int i = 0; i < index - 1; i++)
			tmp = tmp->next;

		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	count++;
	
}
template<class T>
T LinkedList<T>::pop()
{
	return removeAt(count - 1);
}

template<class T>
T LinkedList<T>::removeAt(int index)
{
	T returnValue;
	assert(index >= 0 && index < count);
	if (index == 0)
	{
		node<T>* del = first;
		first = first->next;
		if (count == 1)
			last = first;
		del->next = nullptr;
		returnValue = del->value;
		delete del;
	}
	else {
		node<T>* tmp = first;
		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->next;
		}
		node<T>* del = tmp->next;
		tmp->next = tmp->next->next;
		del->next = nullptr;
		returnValue = del->value;
		delete del;
	}
	count--;
	return returnValue;
}

template<class T>
T& LinkedList<T>::operator[](int index)
{
	assert(index >= 0 && index < count);
	node<T>* tmp = first;
	for (int i = 0; i < index; i++)
	{
		tmp = tmp->next;
	}
	return tmp->value;
}