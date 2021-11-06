#include "Line.h"

Line::Line()
{
	this->coordX1 = 0;
	this->coordX2 = 0;
	this->coordY1 = 0;
	this->coordY2 = 0;
}

Line::Line(Line& l)
{
	this->SetCoordX1(l.coordX1);
	this->SetCoordX2(l.coordX2);
	this->SetCoordY1(l.coordY1);
	this->SetCoordY2(l.coordY2);
}

Line::Line(int coordX1, int coordX2, int coordY1, int coordY2)
{
	this->SetCoordX1(coordX1);
	this->SetCoordX2(coordX2);
	this->SetCoordY1(coordY1);
	this->SetCoordY2(coordY2);
}

Line& Line::operator=(Line& l)
{
	if (this != &l)
	{
		this->SetCoordX1(l.coordX1);
		this->SetCoordX2(l.coordX2);
		this->SetCoordY1(l.coordY1);
		this->SetCoordY2(l.coordY2);
	}
	return *this;
}

void Line::SetCoordX1(int coordX1)
{
	this->coordX1 = coordX1;
}

void Line::SetCoordX2(int coordX2)
{
	this->coordX2 = coordX2;
}

void Line::SetCoordY1(int coordY1)
{
	this->coordY1 = coordY1;
}

void Line::SetCoordY2(int coordY2)
{
	this->coordY2 = coordY2;
}

int Line::GetCoordX1() const
{
	return this->coordX1;
}

int Line::GetCoordX2() const
{
	return this->coordX2;
}

int Line::GetCoordY1() const
{
	return this->coordY1;
}

int Line::GetCoordY2() const
{
	return this->coordY2;
}

void Line::GetInfo()
{
	std::cout << "line " << this->coordX1 << " " << this->coordX2 << " " << this->coordY1 << " " << this->coordY2 << std::endl;
}

void Line::GenerateInfo(std::ostream& generate)
{
	generate << "<line x1=" << this->GetCoordX1() << " x2=" << this->GetCoordX2() << " y1=" << this->GetCoordY1() << " ";
	generate << "y2=" << this->GetCoordY2() << "/>" << std::endl;
}

void Line::Translate(int horizontal, int vertical)
{
	this->SetCoordX1(this->coordX1 + horizontal);
	this->SetCoordX2(this->coordX2 + horizontal);
	this->SetCoordY1(this->coordY1 + vertical);
	this->SetCoordY2(this->coordY2 + vertical);
}
