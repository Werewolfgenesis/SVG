// SVG_71983.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Figure.h"
#include "Rect.h"
#include "Line.h"
#include "MainCommands.h"

using std::cin;
using std::cout;
using std::endl;


char currentFile[32];

int main()
{
	MainCommands mc;
	Vector<Figure*> f;
	bool Using = true;
	bool isOpened = false;

	do
	{
		char command[30];

		cout << "How can I help you? " << endl;
		cin.getline(command, 30);
		if (strcmp(command, "Help") == 0 || strcmp(command, "help") == 0)
		{
			cout << "Generating help message..." << endl;
			mc.Help();
		}
		else if (strcmp(command, "Open") == 0 || strcmp(command,"open") == 0)
		{
			if (isOpened == false)
			{
				isOpened = true;
				cout << "Please insert file name to open: ";
				cin.getline(currentFile, 32);
				cout << "Openning " << currentFile << "..." << endl;
				mc.Open(currentFile);
				cout << "File " << currentFile << " successfully opened!" << endl;
			}
		}
		else if (strcmp(command, "Print") == 0)
		{
			mc.Print(f);
		}
		else if (strcmp(command, "Save") == 0 || strcmp(command, "save") == 0)
		{
			if (isOpened == true)
			{
				cout << "Saving file..." << endl;
				mc.Save(f, currentFile);
				cout << "File " << currentFile << " successfully saved!" << endl;
			}
			else
			{
				cout << "No currently opened file" << endl;
			}
		}
		else if (strcmp(command, "SaveAs") == 0 || strcmp(command, "save as") == 0 || strcmp(command, "Save as") == 0)
		{
			if (isOpened == true)
			{
				char file[32];
				cout << "Please enter file name: ";
				cin.getline(file, 32);
				mc.Save(f, file);
			}
			else
			{
				cout << "No currently opened file" << endl;
			}
		}
		else if (strcmp(command, "Close") == 0 || strcmp(command, "close") == 0 )
		{
			if (isOpened == true)
			{
				cout << "Closing the file.." << endl;
				isOpened = false;
				cout << "The file has been closed" << endl;
			}
			else
			{
				cout << "No file opened" << endl;
			}
		}
		else if (strcmp(command, "Exit") == 0 || strcmp(command,"exit") == 0)
		{
			cout << "Exiting program.." << endl;
			Using = false;
			cout << "Program exited successfully!" << endl;
		}
		else if (strcmp(command, "Create") == 0 || strcmp(command, "create") == 0)
		{
			cout << "What type of figure do you want to create? (Circle, Line or Rectangle)" << endl;
			char figure[10];
			cin.getline(figure, 10);
			if (strcmp(figure, "Circle") == 0 || strcmp(figure, "circle") == 0)
			{
				int cx, cy, radius;
				char fill[10];
				cout << "Enter CX: ";
				cin >> cx;
				cout << "Enter CY: ";
				cin >> cy;
				cout << "Enter radius: ";
				cin >> radius;
				cout << "Enter fill: ";
				cin.ignore();
				cin.getline(fill, 10);

				Circle *circle = new Circle(cx, cy, radius, fill);
				f.pushBack(circle);
			}
			else if (strcmp(figure, "Line") == 0 || strcmp(figure, "line") == 0)
			{
				int x1, x2, y1, y2;
				cout << "Enter x1: ";
				cin >> x1;
				cout << "Enter x2: ";
				cin >> x2;
				cout << "Enter y1: ";
				cin >> y1;
				cout << "Enter y2: ";
				cin >> y2;

				Line* line = new Line(x1, x2, y1, y2);
				f.pushBack(line);
			}
			else if (strcmp(figure, "Rectangle") == 0 || strcmp(figure, "rectangle") == 0)
			{
				int coordX, coordY, width, height;
				char color[10];
				cout << "Enter x: ";
				cin >> coordX;
				cout << "Enter y: ";
				cin >> coordY;
				cout << "Enter width: ";
				cin >> width;
				cout << "Enter height: ";
				cin >> height;
				cout << "Enter color: ";
				cin.ignore();
				cin.getline(color, 10);

				Rect* rectangle = new Rect(coordX, coordY, width, height, color);
				f.pushBack(rectangle);
			}
		}
		else if (strcmp(command, "Translate") == 0 || strcmp(command, "translate") == 0)
		{
			int horizontal, vertical;
			cout << "Enter horizontal: ";
			cin >> horizontal;
			cout << "Enter vertical: ";
			cin >> vertical;
			cout << "Translating figures..." << endl;
			for (size_t i = 0; i < f.GetSize(); i++)
			{
				f[i]->Translate(horizontal, vertical);
			}
			cout << "Figures translated successfully! " << endl;
		}
		else if (strcmp(command, "Erase") == 0 || strcmp(command, "erase") == 0)
		{
			int index;
			cout << "Enter index (1...nrFigures): ";
			cin >> index;
			if (index <= 0 || index > f.GetSize())
			{
				cout << "Not a correct index given" << endl;
			}
			else
			{
				cout << "Erasing figure on index " << index << "..." << endl;
				mc.Erase(f, index-1);
				cout << "Figure on index " << index << " erased successfully" << endl;
			}
		}
		else if (strcmp(command, "Within") == 0 || strcmp(command, "within") == 0)
		{
			cout << "Yet to be done" << endl;
		}
		else
		{
			cout << "No such command. Press help to see the supported commands!" << endl;
		}
		cout << "Press enter to continue, please! " << endl;
		cin.ignore();
	} while (Using != 0);
}