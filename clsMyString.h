#pragma once
#include <iostream>
#include <stack>
using namespace std;

class clsMyString
{
private:
	string _Value = "";
	stack<string> _Undo;
	stack<string> _Redo;
public:
	void SetValue(string Value)
	{
		_Value = Value;
		_Undo.push(Value);
		_Redo.push(Value);
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


	void Undo()
	{
		if(!_Undo.empty())
		{
			_Redo.push(_Value);
			_Undo.pop();
			_Value = _Undo.top();
		}
	}

	void Redo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}
	}
};

