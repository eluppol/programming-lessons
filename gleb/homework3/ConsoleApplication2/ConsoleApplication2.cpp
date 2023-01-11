// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;
int main()
{
	string text;
	cout << "enter your text:";
	getline(cin, text);
	int start;
	start = text.find(" ");
	start = start + 1;
	int end;
	end = text.find(" ", start);
	end = end + 1;
	if (start == end)
	{
		cout << "only 1 word";
	}
	else
	{
		string word;
		end = end - 3;
		word = text.substr(start, end);
		cout << "your second word is " << word;
	}

	return 0;

}

