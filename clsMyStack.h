#pragma once
#include <iostream>
#include "clsMyQueue.h";
using namespace std;

template<typename T>
class clsMyStack : public clsMyQueue<T>
{
public:

	void Push(T Value)
	{
		clsMyQueue<T>::_DbList.InsertAtBeginning(Value);
	}

	T Top()
	{
		return clsMyQueue<T>::Front();
	}

	T Bottom()
	{
		return clsMyQueue<T>::Back();
	}

	void InsertAtTop(T Value)
	{
		clsMyQueue<T>::InsertAtFront(Value);
	}

	void InsertAtBottom(T Value)
	{
		clsMyQueue<T>::InsertAtBack(Value);
	}

};