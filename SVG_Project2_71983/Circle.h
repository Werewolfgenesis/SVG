#pragma once
#include "Figure.h"
class Circle : public Figure
{
	int coordCX, coordCY, radius;
	char* fill;
public:
	//----------------------Big 4 and constructor with parameters
	Circle();//default constructor
	Circle(Circle& other);//copy constructor
	Circle(int coordCX, int coordCY, int radius, const char* fill);//constructor with parameters
	Circle& operator= (Circle& other);//operator=
	~Circle();//destrutor

	//----------------------Setter methods
	void SetCoordCX(int coordCX);//set coordCX as <coordCX>
	void SetCoordCY(int coordCY);//set coordCY as <coordCY>
	void SetRadius(int radius);//set radius as <radius>
	void SetFill(const char* fill);//set fill as <fill>

	//----------------------Getter methods
	int GetCoordCX() const;//return coordCX
	int GetCoordCY() const;//return coordCY
	int GetRadius() const;//return radius
	char* GetFill() const;//return fill

	//--------------------------------------pure virtual methods from the parent (Figure) class
	void GetInfo() override; //cout the info of the circle
	void GenerateInfo(std::ostream& generate) override;//generate the info of the circle into the file
	void Translate(int horizontal, int vertical) override; // translates the figure
};

