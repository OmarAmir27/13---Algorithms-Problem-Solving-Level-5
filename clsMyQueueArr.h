#pragma once
#include<iostream>
#include "clsDynamicArray.h"
using namespace std;

template <typename T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T> _DynamicArray;
public:
	int Size()
	{
		return _DynamicArray.Size();
	}

	T Front()
	{
		return _DynamicArray.GetItem(0);
	}

	T Back()
	{
		return _DynamicArray.GetItem(Size() - 1);
	}

	void Print(string Title)
	{
		_DynamicArray.Print(Title);
	}

	void Push(T Value)
	{
		_DynamicArray.InsertAtEnd(Value);
	}

	void Pop()
	{
		_DynamicArray.DeleteFirstItem();
	}

	bool IsEmpty()
	{
		return (_DynamicArray.IsEmpty());
	}

	T GetItem(short Index)
	{
		return _DynamicArray.GetItem(Index);
	}

	void Reverse()
	{
		_DynamicArray.Reverse();
	}

	void UpdateItem(short Index, T NewValue)
	{
		_DynamicArray.SetItem(Index, NewValue);
	}

	void InsertAfter(short Index, T Value)
	{
		_DynamicArray.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		_DynamicArray.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_DynamicArray.InsertAtEnd(Value);
	}

	void Clear()
	{
		_DynamicArray.Clear();
	}
};

