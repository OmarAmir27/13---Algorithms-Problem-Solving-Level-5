#pragma once
#include <iostream>

using namespace std;

template <typename T>
class MyDblLinkedList
{
protected:
	int _Size;
public:
	class clsNode
	{
	public:
		T Value;
		clsNode* Prev;
		clsNode* Next;
	};

	clsNode* Head = NULL;

	//void Swap(clsNode*& Prev_Node, clsNode*& Next_Node)
	//{
	//	clsNode* Temp = Prev_Node;
	//	Prev_Node = Next_Node;
	//	Next_Node = Temp;
	//}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void InsertAtBeginning(T Value)
	{
		clsNode* New_Node = new clsNode();
		New_Node->Value = Value;
		New_Node->Prev = NULL;
		New_Node->Next = Head;

		if (Head != NULL)
		{
			Head->Prev = New_Node;
		}
		Head = New_Node;
		_Size++;
	}

	clsNode* Find(T Value)
	{
		clsNode* Current_Node = Head;
		while (Current_Node != NULL)
		{
			if (Current_Node->Value == Value)
				return Current_Node;

			Current_Node = Current_Node->Next;
		}
		return NULL;
	}

	void InsertAfter(clsNode* Prev,T Value)
	{
		if (Prev == NULL)
			return;

		clsNode* New_Node = new clsNode();
		New_Node->Value = Value;

		New_Node->Next = Prev->Next;
		New_Node->Prev = Prev;

		if(Prev->Next != NULL)
			Prev->Next->Prev = New_Node;

		Prev->Next = New_Node;
		_Size++;
	}

	bool InsertAfter(short Index, T Value)
	{
		clsNode* Node = GetNode(Index);
		if (Node != NULL)
		{
			InsertAfter(Node, Value);
			return true;
		}
		else
			return false;
	}

	void InsertAtEnd(T Value)
	{
		clsNode* New_Node = new clsNode();
		New_Node->Value = Value;
		New_Node->Next = NULL;
		
		_Size++;

		if (Head == NULL)
		{
			New_Node->Prev = NULL;
			Head = New_Node;
			return;
		}

		clsNode* Current_Node = Head;
		
		while (Current_Node->Next != NULL)
		{
			Current_Node = Current_Node->Next;
		}

		New_Node->Prev = Current_Node;
		Current_Node->Next = New_Node;
	}

	void DeleteFirstNode()
	{
		if (Head == NULL)
			return;

		clsNode* Temp = Head;
		Head = Head->Next;
		if(Head != NULL)
			Head->Prev = NULL;
		delete Temp;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (Head == NULL)
			return;

		clsNode* Current_Node = Head;
		if (Head->Next == NULL)
		{
			Head = NULL;
			delete Current_Node;
			return;
		}

		while (Current_Node->Next->Next != NULL)
		{
			Current_Node = Current_Node->Next;
		}
		clsNode* Temp = Current_Node->Next;
		Current_Node->Next = NULL;
		delete Temp;
		_Size--;
	}

	void DeleteNode(clsNode*& NodeToBeDeleted)
	{
		if (NodeToBeDeleted == NULL)
			return;

		if (NodeToBeDeleted == Head)
		{
			Head = NodeToBeDeleted->Next;
		}

		if (NodeToBeDeleted->Next != NULL)
		{
			NodeToBeDeleted->Next->Prev = NodeToBeDeleted->Prev;
		}

		if (NodeToBeDeleted->Prev != NULL)
		{
			NodeToBeDeleted->Prev->Next = NodeToBeDeleted->Next;
		}

		delete NodeToBeDeleted;
		_Size--;
	}

	void PrintList(string Title)
	{
		clsNode* Current = Head;
		cout << Title <<"\n";
		while (Current != NULL)
		{
			cout << Current->Value << " <--> ";
			Current = Current->Next;
		}
		cout << "\n\n";
	}

	int Size()
	{
		return _Size;
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		if (Head == NULL || _Size == 1)
			return;

		clsNode* Current = Head;
		clsNode* Temp = nullptr;

		while (Current != nullptr)
		{
			// Swap between Prev & Next Nodes !....
			Temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = Temp;

			Current = Current->Prev;
		}

		if (Temp != NULL)
			Head = Temp->Prev;
	}

	clsNode* GetNode(short Index)
	{
		if (Head == NULL || Index > _Size - 1 || Index < 0)
			return NULL;

		clsNode* Current = Head;
		short Counter = 0;
		while (Current != NULL)
		{
			if (Counter == Index)
				break;
			Counter++;
			Current = Current->Next;
		}
		return Current;
	}

	T GetItem(short Index)
	{
		clsNode* Node = GetNode(Index);
		return (Node == NULL) ? NULL : Node->Value;
	}

	bool UpdateItem(short Index, T NewValue)
	{
		clsNode* Node = GetNode(Index);
		if (Node != NULL)
		{
			Node->Value = NewValue;
			return true;
		}
		else
			return false;
	}


};