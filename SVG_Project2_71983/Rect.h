#pragma once
#include "Figure.h"
#include <iostream>
using std::cout;
using std::endl;

class Rect : public Figure
{
private:
	int coordX, coordY, width, height;
	char* color;
public:
	//--------------------------------------big 4 including useful construcrtors
	Rect();//default constructor
	Rect(Rect& other);//copy constructor
	Rect& operator=(Rect& other);//operator=
	Rect(int coordX, int coordY, int width, int height, const char * color);//useful constructor with parameters
	~Rect();//destructor

	//----------------------------------setter methods
	void SetWidth(int width); //set width as <width>
	void SetHeight(int height);//set height as <height>
	void SetCoordX(int coordX);//set coordX as <coordX>
	void SetCoordY(int coordY);//set coordY as <coordY>
	void SetColor(const char* color);//set color as <color>

	//----------------------------------getter methods
	int GetCoordX() const;//return coordX
	int GetCoordY() const;//return coordY
	int GetWidth()const;//return width
	int GetHeight()const;//return height
	const char* GetColor()const;//return color

	//--------------------------------------pure virtual methods from the parent (Figure) class
	void GetInfo() override; //cout the info of the rectangle
	void GenerateInfo(std::ostream& generate) override;//generate the info of the rectangle into the file
	void Translate(int horizontal, int vertical) override;
};

