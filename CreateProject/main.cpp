     ////////////////////////////////////////
    //      SnowEngine by SnegirSoft      //
   //  Project creator                   //
  //                                    //
 //  File: main.cpp                    //
////////////////////////////////////////

#include <thread>

#include "creator.h"

int main()
{
	string enginePath, projectPath, sfmlPath, solutionName, projectName;
	
	cout << "Note: you can use Alt+Enter -> Edit -> Paste to past the text from the clipboard." <<
		endl << endl << "The path to the folder with SnowEngine project:\n\t";
	cin >> enginePath;
	cout << "The path to the folder for creating folder:\n\t";
	cin >> projectPath;
	cout << "The path to SFML:\n\t";
	cin >> sfmlPath;
	cout << "The solution name:\n\t";
	cin >> solutionName;
	cout << "The project name:\n\t";
	cin >> projectName;

	Printer::clear();
	Printer::print("Started checking engine files...\n\n");

	int checkStage = 0;
	thread checkThread(checkEngine, ref(checkStage), ref(enginePath));
	checkThread.detach();
	while (checkStage < FILES_COUNT && checkStage >= 0)
	{
		Printer::clear();
		Printer::printTmp("Checking engine files... Stage " + to_string(checkStage) + " of " + to_string(FILES_COUNT));
	}

	if (checkStage < 0)
	{
		Printer::clear();
		Printer::printTmp("Error. One of engine`s file wasn`t found.");
		_getch();
		return 0;
	}

	Printer::clear();
	Printer::print("Started project creating...\n\n");
	create(enginePath, projectPath, sfmlPath, solutionName, projectName);
}