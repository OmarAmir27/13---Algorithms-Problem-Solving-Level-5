#pragma once
#include <iostream>
#include "clsMyQueueArr.h";
using namespace std;

template<typename T>
class clsMyStackArr : public clsMyQueueArr<T>
{
public:

	void Push(T Value)
	{
		clsMyQueueArr<T>::_DynamicArray.InsertAtBeginning(Value);
	}

	T Top()
	{
		return clsMyQueueArr<T>::Front();
	}

	T Bottom()
	{
		return clsMyQueueArr<T>::Back();
	}

	void InsertAtTop(T Value)
	{
		clsMyQueueArr<T>::InsertAtFront(Value);
	}

	void InsertAtBottom(T Value)
	{
		clsMyQueueArr<T>::InsertAtBack(Value);
	}
};

