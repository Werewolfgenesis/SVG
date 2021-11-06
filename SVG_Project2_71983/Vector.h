#pragma once
#include <iostream>
template <class  T>
class Vector
{
	T* cont;
	size_t size;

public:
	Vector()
	{
		cont = nullptr;
		size = 0;
	}
	Vector(const Vector& other)
	{
		this->cont = new T[other.size];
		this->size = other.size;
		for (size_t i = 0; i < this->size; i++)
		{
			this->cont[i] = other.cont[i];
		}
	}
	Vector& operator=(const Vector& other)
	{
		if (this != &other)
		{
			delete[]cont;
			this->cont = new T[other.size];
			this->size = other.size;
			for (size_t i = 0; i < this->size; i++)
			{
				this->cont[i] = other.cont[i];
			}
		}
	}
	~Vector()
	{
		delete[] this->cont;
	}

	void pushBack(T v)
	{
		T* newBuffer = new T[this->size + 1];
		for (size_t i = 0; i < this->size; i++)
		{
			newBuffer[i] = this->cont[i];
		}
		newBuffer[this->size] = v;
		delete[]cont;
		cont = newBuffer;
		size++;
	}
	void push(T& v)
	{
		T* newBuffer = new T[this->size + 1];
		for (size_t i = 0; i < this->size; i++)
		{
			newBuffer[i + 1] = this->cont[i];
		}
		newBuffer[0] = v;
		delete[]cont;
		cont = newBuffer;
		size++;
	}
	size_t GetSize()const
	{
		return this->size;
	}
	T& operator[] (size_t i)
	{
		return cont[i];
	}
	void Swap(int index1, int index2)
	{
		T temp = cont[index1];
		cont[index1] = cont[index2];
		cont[index2] = temp;
	}
	void RemoveElem(int index)
	{
		Swap(index, size - 1);
		cont[size - 1] = nullptr;
		size--;
	}
	friend std::ostream& operator<<(std::ostream& out, const Vector<T>& v)
	{
		for (size_t i = 0; i < this->size; i++)
		{
			out << v[i];
		}
		return out;
	}
};

