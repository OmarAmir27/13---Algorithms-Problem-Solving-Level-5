#pragma once

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class clsString
{

private:
	string _Value;

	enum class enWhatToCount { SmallLetter = 0, CapitalLetters = 1, All = 3 };
	enum class enEnableCaseSenstive { NotEnable = 0, Enable = 1 };
	enum class enIsVowelLetters { NotVowel = 0, Vowel = 1 };
	static enIsVowelLetters CheckIsVowel(char Character)
	{
		Character = tolower(Character);

		return (Character == 'a' || Character == 'o' || Character == 'u' || Character == 'i' || Character == 'e') ? enIsVowelLetters::Vowel : enIsVowelLetters::NotVowel;
	}
	static bool isVowel(char Letter)
	{
		return (Letter == 'a' || Letter == 'o' || Letter == 'u' || Letter == 'i' || Letter == 'e');

	}
	static char InvertCharacterCase(char x)
	{
		return isupper(x) ? tolower(x) : toupper(x);
	}

public:
	clsString()
	{
		this->_Value = "";
	}

	clsString(string Value)
	{
		this->_Value = Value;
	}

	void SetValue(string Value)
	{
		this->_Value = Value;
	}
	string GetValue()
	{
		return this->_Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;

	// From Course 7 Algorith && Problem Solving Level 3

	static short Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return this->_Value.length();
	}

	static char GetFirstCharacterOfString(string S1)
	{
		short Index = 0;
		string Word = "";
		while (Index != -1)
		{
			Index = S1.find_first_of(' ');
			Word = S1.substr(0, Index);
			S1 = S1.erase(0, Index + 1);
		}
		return Word[0];
	}
	char GetFirstCharacterOfString()
	{
		return GetFirstCharacterOfString(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		// Ahmed Khaled
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			if (S1[Counter] != ' ' && isFirstLetter)
				S1[Counter] = toupper(S1[Counter]);

			isFirstLetter = (S1[Counter] == ' ') ? true : false;
		}

		return S1;
	}
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		// Ahmed Khaled
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			if (S1[Counter] != ' ' && isFirstLetter)
				S1[Counter] = tolower(S1[Counter]);

			isFirstLetter = (S1[Counter] == ' ') ? true : false;
		}

		return S1;
	}
	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(this->_Value);
	}

	static string UpperAllCharacterInString(string S1)
	{
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			S1[Counter] = toupper(S1[Counter]);
		}

		return S1;
	}
	void UpperAllCharacterInString()
	{
		_Value = UpperAllCharacterInString(this->_Value);
	}

	static string LowerAllCharacterInString(string S1)
	{
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{

			S1[Counter] = tolower(S1[Counter]);
		}

		return S1;
	}
	void LowerAllCharacterInString()
	{
		_Value = LowerAllCharacterInString(this->_Value);
	}

	static string InvertAllCharacterCaseOfString(string& S1)
	{
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			S1[Counter] = InvertCharacterCase(S1[Counter]);
		}

		return S1;
	}
	void InvertAllCharacterCaseOfString()
	{
		_Value = InvertAllCharacterCaseOfString(this->_Value);
	}

	static short CountCapitalLettersInString(string& S1)
	{
		short CapitalLetters = 0;
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			if (isupper(S1[Counter]))
				CapitalLetters++;
		}

		return CapitalLetters;
	}
	short CountCapitalLettersInString()
	{

		return CountCapitalLettersInString(_Value);
	}

	static short CountSmallLettersInString(string& S1)
	{
		short SmallLetters = 0;
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			if (islower(S1[Counter]))
				SmallLetters++;
		}

		return SmallLetters;
	}
	short CountSmallLettersInString()
	{
		return  CountSmallLettersInString(_Value);
	}

	static short CountLetterFrequency(const string& S1, char CharacterRepeated)
	{
		short Freq = 0;
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			if (S1[Counter] == CharacterRepeated)
				Freq++;
		}
		return Freq;
	}
	short CountLetterFrequency(char CharacterRepeated)
	{
		return CountLetterFrequency(_Value, CharacterRepeated);
	}

	static short CountLetterFrequencyMissCaseSensitive(char CharacterRepeated, const string& S1, bool AcceptSensitiveCase = true)
	{
		short Freq = 0;
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			if (AcceptSensitiveCase)
			{
				if (S1[Counter] == CharacterRepeated)
					Freq++;
			}

			else
			{
				if (tolower(S1[Counter]) == tolower(CharacterRepeated))
					Freq++;
			}
		}
		return Freq;
	}
	short CountLetterFrequencyMissCaseSensitive(char CharacterRepeated, bool AcceptSensitiveCase = true)
	{
		return CountLetterFrequencyMissCaseSensitive(CharacterRepeated, _Value, AcceptSensitiveCase);
	}

	static short CountVowelLettersInString(const string& S1)
	{
		short Freq = 0;
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			if (CheckIsVowel(S1[Counter]) == enIsVowelLetters::Vowel)
				Freq++;
		}
		return Freq;
	}
	short CountVowelLettersInString()
	{
		return CountVowelLettersInString(_Value);
	}

	static void PrintAllVowelLettersInString(const string& S1)
	{
		cout << "All Vowels Letter in String is : ";
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			if (CheckIsVowel(S1[Counter]) == enIsVowelLetters::Vowel)
				cout << S1[Counter] << "\t";
		}
		cout << "\n\n";

	}
	void PrintAllVowelLettersInString()
	{
		PrintAllVowelLettersInString(_Value);
	}

	static void PrintSeparatewordInString(string& S1)
	{
		short Index = 0;
		string Word = "";

		while (Index != -1)
		{
			Index = S1.find(' ');
			Word = S1.substr(0, Index);
			cout << Word << "\n";
			S1 = S1.erase(0, Index + 1);
		}
	}
	void PrintSeparatewordInString()
	{
		PrintSeparatewordInString(_Value);
	}

	static void PrintSeparatewordInStringAnotherWay(string& S1)
	{
		string Delimiter = " ";

		short Position = 0;
		string StringWord = "";

		while ((Position = S1.find(Delimiter)) != std::string::npos)
		{
			StringWord = S1.substr(0, Position);
			if (StringWord != "")
			{
				cout << StringWord << endl;
			}
			S1.erase(0, Position + Delimiter.length());
		}
		if (S1 != "")
			cout << S1 << "\n";
	}
	void PrintSeparatewordInStringAnotherWay()
	{
		PrintSeparatewordInStringAnotherWay(_Value);
	}

	static void PrintEachWordInString(string S1)
	{
		string delim = " "; // delimiter
		cout << "\nYour string wrords are: \n\n";
		short pos = 0;
		string sWord;

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
			cout << S1 << "\n";

	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static short CountEachWordInString(string& S1)
	{
		short Counter = 0;

		string Delimiter = " ";

		short Position = 0;
		string Word = "";

		while ((Position = S1.find(Delimiter)) != std::string::npos)
		{
			Word = S1.substr(0, Position);

			if (Word != "")
				Counter++;

			S1.erase(0, Position + Delimiter.length());
		}
		if (S1 != "")
			Counter++;

		return Counter;
	}
	short CountEachWordInString()
	{
		return CountEachWordInString(_Value);
	}

	static vector<string> Split(string& S1, const string& Delimiter)
	{
		vector<string> vWords;

		string Word = "";
		short Position = 0;

		while ((Position = S1.find(Delimiter)) != string::npos)
		{
			Word = S1.substr(0, Position);
			if (Word != "")
				vWords.push_back(Word);

			S1.erase(0, Position + Delimiter.length());
		}
		if (S1 != "")
			vWords.push_back(S1);

		return vWords;
	}
	vector<string> Split(const string& Delimiter)
	{
		return Split(_Value, Delimiter);
	}

	static string TrimLeft(string& S1)
	{
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			if (isalpha(S1[Counter]))
			{
				S1.erase(0, Counter);
				return S1;
			}
		}
		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string& S1)
	{
		for (short Counter = S1.length() - 1; Counter >= 0; Counter--)
		{
			if (isalpha(S1[Counter]))
			{
				S1.erase(Counter + 1, S1.length());
				return S1;
			}
		}
		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string& S1)
	{
		S1 = TrimLeft(S1);
		S1 = TrimRight(S1);
		return S1;
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string>& vWords, const string& Delimiter)
	{
		string S1 = "";

		for (string& Word : vWords)
		{
			S1 += Word + Delimiter;
		}

		return S1.substr(0, S1.length() - Delimiter.length());
	}

	static string ReverseWordsInString(string& S1)
	{
		string Delimiter = " ";

		vector<string>vWords = Split(S1, Delimiter);
		string S2 = "";

		vector<string>::iterator iter = vWords.end();

		while (iter != vWords.begin())
		{
			iter--;

			S2 += *iter + " ";
		}
		return S2.substr(0, S2.length() - Delimiter.length());
	}
	string ReverseWordsInString()
	{
		return ReverseWordsInString(_Value);
	}

	static string ReplaceString(string Original, string StringToReplace, string ReplaceTo)
	{
		short Position = 0;
		while ((Position = Original.find(StringToReplace)) != string::npos)
		{
			Original.replace(Position, StringToReplace.length(), ReplaceTo);
		}

		return Original;
	}
	string ReplaceString(string& StringToReplace, string& ReplaceTo)
	{
		return ReplaceString(_Value, StringToReplace, ReplaceTo);
	}

	static string LowerWord(string Word)
	{
		for (short Counter = 0; Counter < Word.length(); Counter++)
		{
			Word[Counter] = tolower(Word[Counter]);
		}

		return Word;
	}
	void LowerWord()
	{
		_Value = LowerWord(_Value);
	}

	static string ReplaceWordsInStringUsingSplitFunc(string Original, string StringToReplace, string ReplaceTo, const enEnableCaseSenstive& EnableOrNot)
	{
		short Position = 0;
		vector<string> vWords = Split(Original, " ");
		vector<string>::iterator iter = vWords.end();

		while (iter != vWords.begin())
		{
			--iter;
			if (EnableOrNot == enEnableCaseSenstive::Enable)
			{
				if (*iter == StringToReplace)
				{
					*iter = ReplaceTo;
				}
			}
			else
			{
				if (LowerWord(*iter) == LowerWord(StringToReplace))
					*iter = ReplaceTo;
			}
		}

		return JoinString(vWords, " ");
	}
	string ReplaceWordsInStringUsingSplitFunc(string StringToReplace, string ReplaceTo, const enEnableCaseSenstive& EnableOrNot)
	{

		return ReplaceWordsInStringUsingSplitFunc(_Value, StringToReplace, StringToReplace, EnableOrNot);
	}

	static string RemovePuncatuationsFromString(string S1)
	{
		string S2 = "";
		for (short Counter = 0; Counter < S1.length(); Counter++)
		{
			if (!ispunct(S1[Counter]))
				S2 += S1[Counter];
		}
		return S2;
	}
	void RemovePuncatuationsFromString()
	{
		_Value = RemovePuncatuationsFromString(_Value);
	}

};