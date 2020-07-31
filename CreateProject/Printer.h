     ////////////////////////////////////////
    //      SnowEngine by SnegirSoft      //
   //  Project creator                   //
  //                                    //
 //  File: Printer.h                   //
////////////////////////////////////////

#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Printer
{
private:
	static vector<string> printStack;

public:
	static void print(string text);
	static void printTmp(string text);
	static void clear();
};