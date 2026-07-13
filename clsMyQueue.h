#pragma once
#include <iostream>
#include "MyDblLinkedList.h";
using namespace std;

template <typename T>
class clsMyQueue
{
protected:
	MyDblLinkedList<T> _DbList; // Composition Principle.
public:

	int Size()
	{
		return _DbList.Size();
	}

	T Front()
	{
		return _DbList.GetItem(0);
	}

	T Back()
	{
		return _DbList.GetItem(Size() - 1);
	}

	void Print(string Title)
	{
		_DbList.PrintList(Title);
	}

	void Push(T Value)
	{
		_DbList.InsertAtEnd(Value);
	}

	void Pop()
	{
		_DbList.DeleteFirstNode();
	}

	bool IsEmpty()
	{
		return (_DbList.IsEmpty());
	}

	T GetItem(short Index)
	{
		return _DbList.GetItem(Index);
	}

	void Reverse()
	{
		_DbList.Reverse();
	}

	void UpdateItem(short Index,T NewValue)
	{
		_DbList.UpdateItem(Index, NewValue);
	}

	void InsertAfter(short Index,T Value)
	{
		_DbList.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value)
	{
		_DbList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_DbList.InsertAtEnd(Value);
	}

	void Clear()
	{
		_DbList.Clear();
	}
};