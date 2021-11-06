#pragma once

#include <iostream>
class Figure
{
public:
	//pure virtual methods -> must be implemented in the derived class 
	virtual void GetInfo() = 0; //Gets the info of the figure
	virtual void GenerateInfo(std::ostream& out) = 0; //Generates info into the file
	virtual void Translate(int horizontal, int vertical) = 0;//translates all figures
};

