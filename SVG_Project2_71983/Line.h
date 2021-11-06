#pragma once
#include "Figure.h"
class Line : public Figure
{
private:
	int coordX1, coordX2, coordY1, coordY2;

public:
	//------------------------------Constructors & operator=
	Line();
	Line(Line& l);
	Line(int coordX1, int coordX2, int coordY1, int coordY2);
	Line& operator=(Line& l);

	//------------------------------Setter methods
	void SetCoordX1(int coordX1);
	void SetCoordX2(int coordX2);
	void SetCoordY1(int coordY1);
	void SetCoordY2(int coordY2);

	//------------------------------Getter metods
	int GetCoordX1() const;
	int GetCoordX2() const;
	int GetCoordY1() const;
	int GetCoordY2() const;
	
	//--------------------------------------pure virtual methods from the parent (Figure) class
	void GetInfo() override;
	void GenerateInfo(std::ostream& generate) override;
	void Translate(int horizontal, int vertical);
	
};

