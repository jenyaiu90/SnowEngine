     ////////////////////////////////////////
    //      SnowEngine by SnegirSoft      //
   //  Project creator                   //
  //                                    //
 //  File: Printer.cpp                 //
////////////////////////////////////////

#include "Printer.h"

vector<string> Printer::printStack;

void Printer::print(string text)
{
	cout << text;
	printStack.push_back(text);
}

void Printer::printTmp(string text)
{
	cout << text;
}

void Printer::clear()
{
	system("cls");
	for (string str : printStack)
	{
		cout << str;
	}
}