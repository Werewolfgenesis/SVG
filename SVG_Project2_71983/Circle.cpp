#include "Circle.h"
#pragma warning (disable: 4996)
Circle::Circle()
{
	this->SetCoordCX(0);
	this->SetCoordCY(0);
	this->SetRadius(0);
	this->SetFill(nullptr);
}

Circle::Circle(Circle& other)
{
	this->SetCoordCX(other.coordCX);
	this->SetCoordCY(other.coordCY);
	this->SetRadius(other.radius);
	this->SetFill(other.fill);
}

Circle::Circle(int coordCX, int coordCY, int radius, const char* fill)
{
	this->SetCoordCX(coordCX);
	this->SetCoordCY(coordCY);
	this->SetRadius(radius);
	this->SetFill(fill);
}

Circle& Circle::operator=(Circle& other)
{
	if (this != &other)
	{
		this->SetCoordCX(other.coordCX);
		this->SetCoordCY(other.coordCY);
		this->SetRadius(other.radius);
		this->SetFill(other.fill);
	}
	return *this;
}

Circle::~Circle()
{
	delete[] this->fill;
}

void Circle::SetCoordCX(int coordCX)
{
	if (coordCX != NULL)
	{
		this->coordCX = coordCX;
	}
}

void Circle::SetCoordCY(int coordCY)
{
	if (coordCY != NULL)
	{
		this->coordCY = coordCY;
	}
}

void Circle::SetRadius(int radius)
{
	if (radius != NULL)
	{
		this->radius = radius;
	}
}

void Circle::SetFill(const char* fill)
{
	if (fill != NULL)
	{
		delete[] this->fill;
		this->fill = new char[strlen(fill) + 1];
		strcpy(this->fill, fill);
	}
}

int Circle::GetCoordCX() const
{
	return this->coordCX;
}

int Circle::GetCoordCY() const
{
	return this->coordCY;
}

int Circle::GetRadius() const
{
	return this->radius;
}

char* Circle::GetFill() const
{
	return this->fill;
}

void Circle::GetInfo()
{
	std::cout << "circle " << this->coordCX << " " << this->coordCY << " " << this->radius << " " << this->fill << std::endl;
}

void Circle::GenerateInfo(std::ostream& generate)
{
	generate << "<circle cx=" << this->coordCX << " cy=" << this->coordCY << " radius=" << this->radius << " " << this->fill << std::endl;
}

void Circle::Translate(int horizontal, int vertical)
{
	this->SetCoordCX(this->coordCX + horizontal);
	this->SetCoordCY(this->coordCY + vertical);
}
