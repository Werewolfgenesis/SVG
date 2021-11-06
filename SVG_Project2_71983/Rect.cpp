#include "Rect.h"
#pragma warning(disable:4996)
Rect::Rect()
{
	SetCoordX(0);
	SetCoordY(0);
	SetHeight(0);
	SetWidth(0);
	SetColor(nullptr);
}

Rect::Rect(Rect& other)
{
	SetCoordX(other.coordX);
	SetCoordY(other.coordY);
	SetHeight(other.height);
	SetWidth(other.width);
	SetColor(other.color);
}

Rect& Rect::operator=(Rect& other)
{
	if (this != &other)
	{
		SetCoordX(other.coordX);
		SetCoordY(other.coordY);
		SetHeight(other.height);
		SetWidth(other.width);
		SetColor(other.color);
	}
	return *this;
}

Rect::Rect(int coordX, int coordY, int width, int height, const char* color) 
{
	SetCoordX(coordX);
	SetCoordY(coordY);
	SetHeight(height);
	SetWidth(width);
	SetColor(color);
}

Rect::~Rect()
{
	delete[]this->color;
}

void Rect::SetWidth(int width)
{
	if (width != NULL)
	{
		this->width = width;
	}
}

void Rect::SetHeight(int height)
{
	if (height != NULL)
	{
		this->height = height;
	}
}

void Rect::SetCoordX(int coordX)
{
	if (coordX != NULL)
	{
		this->coordX = coordX;
	}
}

void Rect::SetCoordY(int coordY)
{
	if (coordY != NULL)
	{
		this->coordY = coordY;
	}
}

void Rect::SetColor(const char* color)
{
	if (color != NULL)
	{
		delete[]this->color;
		this->color = new char[strlen(color) + 1];
		strcpy(this->color, color);
	}
}

int Rect::GetCoordX() const
{
	return this->coordX;
}

int Rect::GetCoordY() const
{
	return this->coordY;
}

int Rect::GetWidth() const
{
	return this->width;
}

int Rect::GetHeight() const
{
	return this->height;
}

const char* Rect::GetColor() const
{
	return this->color;
}


void Rect::GetInfo()
{
	cout << "rectangle " << this->coordX << " " << this->coordY << " " << this->width << " " << this->height << " " << this->color << endl;
}

void Rect::GenerateInfo(std::ostream& generate)
{
	generate << "<rect x=" << this->GetCoordX() << " y=" << this->GetCoordY() << " width=" << this->GetWidth() << " ";
	generate << "height=" << this->GetHeight() << " fill=" << this->GetColor() << "/>" << endl;

}

void Rect::Translate(int horizontal, int vertical)
{
	this->SetCoordX(this->coordX + horizontal);
	this->SetCoordY(this->coordY + vertical);
}

