#include "Converter.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

bool Converter::IsReady() {
	return ReadFile(filePath);
}

bool Converter::ReadFile(string _path)
{
	ifstream fin(_path);
	if (fin.fail()) {
		cout << "Can't open file";
		return false;
	}
	else {
		string _str;
		while (getline(fin,_str))
		{
			aStrings.push_back(_str);
		}
	}
	return true;
}

void Converter::Start() {
	vector<char> charsHavingDuplicates;
	vector<char> charsNonDuplicates;
	for (auto _str : aStrings) {
		CheckDuplicateSymbols(_str, charsHavingDuplicates, charsNonDuplicates);
	}
}

void Converter::CheckDuplicateSymbols(string _str, vector<char> duplicates, vector<char> nonDuplicates)
{	
	duplicates.clear();
	nonDuplicates.clear();
	for (string::iterator it1 = _str.begin(); it1 < _str.end(); it1++)
	{
		for (string::iterator it2 = it1 + 1; it2 < _str.end(); ++it2) {
			if (tolower(*it1) == *it2) {
				duplicates.push_back(*it1);
				break;
			}
			if (it2 == _str.end() - 1) {
				nonDuplicates.push_back(*it1);
				nonDuplicates.push_back(*it2);
			}
		}
	}
	for (auto ch : duplicates) {
		for (int p; (p = _str.find(ch)) >= 0;)
			_str[p] = ')';
	}
	for (auto ch : nonDuplicates) {
		for (int p; (p = _str.find(ch)) >= 0;)
			_str[p] = '(';
	}
	aResult.push_back(_str);	
}

void Converter::ShowResult()
{
	for (auto _str : aResult) {
		cout << _str << endl;
	}
}
