#pragma once
#include "Vector.h"
#include "Figure.h"
#include "Rect.h"
#include "Circle.h"
#include "Line.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class MainCommands
{
public:

	//------------------Helper functions for the commands
	int StringToInt(const char* str);
	int FirstIndexSymbol(char symbol, const char * str);
	int LastIndexSymbol(char symbol, const char * str);
	char* Substr(const char* str, int firstIndex, int secondIndex);
	Vector<char *> Split(char* txt);

	//------------------Main Commands
	Vector <Figure*> Open(const char * file); //opens a file and reads from it
	void Help(); //displays help message
	void Print(Vector<Figure*>& figures); //print all the figures
	void Save(Vector <Figure*>& figures, const char * file); //saves the file in the current file
	void SaveAs(Vector <Figure*>& figures, const char* file);//saves the file as <file>
	void Erase(Vector <Figure*>& figures, int index); // erases a figure on a position

	
};

