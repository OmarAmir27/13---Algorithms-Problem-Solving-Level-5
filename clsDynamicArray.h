#pragma once
#include<iostream>
#include "clsMyStack.h"
using namespace std;

template <typename T>
class clsDynamicArray 
{
protected:
	int _Size = 0;
	T* _TempArray;

	void Swap(T& Value1, T& Value2)
	{
		T Temp = Value1;
		Value1 = Value2;
		Value2 = Temp;
	}
public:

	T* OriginalArray;
	
	clsDynamicArray (int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;
		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
		delete[] _TempArray;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size || Index < 0)
			return false;

		OriginalArray[Index] = Value;
		return true;
	}

	void Print(string Title)
	{
		cout << "\n" << Title << "\n";
		for (int i = 0 ; i < Size(); i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << "\n\n";
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
		{
			cout << "Error !!! \n\n";
			return;
		}

		_Size = NewSize;
		_TempArray = new T[NewSize];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		delete[] OriginalArray;

		OriginalArray = _TempArray;
		
	}

	T GetItem(int Index)
	{
		return OriginalArray[Index];
	}

	void Reverse()
	{
		for (int i = 0; i < (_Size / 2); i++)
		{
			Swap(OriginalArray[i], OriginalArray[_Size - 1 - i]);
		}
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int Index)
	{
		if (Index < 0 || Index > _Size - 1)
			return false;

		OriginalArray[Index] = -1;

		_Size--;
		_TempArray = new T[_Size];
		
		// Copy All before the Index.
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		for (int i = Index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(T Value)
	{
		int Index = Find(Value);
		if (Index == -1)
			return false;

		DeleteItemAt(Index);
		return true;

	}

	bool InsertAt(int Index, T Value) // 2
	{
		if (Index < 0 || Index > _Size )
			return false;


		_Size++;
		_TempArray = new T[_Size];

		// Copy Array before the Index..
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[Index] = Value;

		for (int i = Index ; i < _Size - 1; i++)
		{
			_TempArray[i + 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}
	
	void InsertAtBeginning(T Value)
	{
		InsertAt(0, Value);
	}

	void InsertBefore(int index, T value)
	{
		if (index <= 0)
			InsertAt(0, value);
		else if (index >= _Size)
			InsertAt(_Size, value);
		else
			InsertAt(index - 1, value);
	}

	void InsertAfter(int index, T value)
	{
		if (index < 0)
			InsertAt(0, value);
		else if (index >= _Size)
			InsertAt(_Size, value);
		else
			InsertAt(index + 1, value);
	}

	void InsertAtEnd(T Value)
	{
		//_Size++;
		//OriginalArray[_Size - 1] = Value;
		InsertAt(_Size, Value);
	}

};