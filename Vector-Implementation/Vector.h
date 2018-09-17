#pragma once
#include "stdafx.h"
#include <iostream>

template <typename T>
class Vector
{
public:
	//Default constructor
	Vector();

	//Copy constructor
	Vector(const Vector<T>& other);

	//Operator = 
	Vector<T>& operator=(const Vector<T>& other);

	//Destructor
	~Vector();

	//Push element in front
	void push_front(T element);

	//Push element at the back
	void push_back(T element);

	//Push element at any position
	void push(T element, size_t index);

	//Pop the first element
	void pop_front();

	//Pop the last element
	void pop_back();

	//Pop element from any position
	void pop(size_t index);

	//Operator +=
	Vector<T>& operator+= (const Vector<T>& other);

	//Returns element corresponding to the index
	T operator[](size_t index) const;

	//Returns index correspondig to the element
	size_t operator[](T element) const;

	//Prints the vector
	void print() const;

	//Gets the current size of the vector
	void get_size() const;

	//Gets the capacity of the vector
	void get_capacity() const;

	//operator << for output
	friend std::ostream& operator<< (std::ostream& output, const Vector<T>& other);

private:
	//Data members
	T* value;
	size_t size;
	size_t capacity;

	//Helper copy
	void copy(const Vector<T>& other);

	//Helper destroy
	void destroy();

	//Resize vector
	void resize();
};

//Default constructor
template <typename T>
Vector<T>::Vector()
{
	this->size = 0;
	this->capacity = 8;
	this->value = new T[this->capacity];
}

//Copy constructor
template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->copy(other);
}

//Operator = 
template <typename T> 
Vector<T>::Vector<T>& operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		this->destroy();
		this->copy(other);
	}
	return this*;
}

//Destructor
template <typename T>
Vector<T>::~Vector()
{
	this->destroy();
}

//Push element in front
template <typename T>
void Vector<T>::push_front(T element)
{
	++this->size;
	if (this->size > this->capacity)
	{
		this->resize();
	}
	for (size_t i = size; i > 0; i--)
	{
		this->value[i] = this->value[i - 1];
	}
	this->value[0] = element;
}

//Push element at the back
template <typename T>
void Vector<T>::push_back(T element)
{
	++this->size;
	if (this->size > this->capacity)
	{
		this->resize();
	}
	this->value[this->size] = element;
}

//Push element at any position
template <typename T>
void Vector<T>::push(T element, size_t index)
{
	++this->size;
	if (this->size > capacity)
	{
		this->resize();
	}
	for (size_t i = this->size; i > index; i--)
	{
		this->value[i] = this->value[i - 1];
	}
	this->value[index] = element;
}

//Pop the first element
template <typename T>
void Vector<T>::pop_front()
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->value[i] = this->value[i + 1];
	}
	this->size--;
}

//Pop the last element
template <typename T>
void Vector<T>::pop_back()
{
	this->size--;
}

//Pop element from any position
template <typename T>
void Vector<T>::pop(size_t index)
{
	if (index > size) { return; }
	for (size_t i = index; i < this->size; i++)
	{
		this->value[i] = this->value[i + 1];
	}
	this->size--;
}

//Operator +=
template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other)
{
	T* temp = new T[this->size + other.size];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->value[i];
	}
	for (size_t i = this->size; , j = 0; i < this->size + other.size; i++, j++)
	{
		temp[i] = other.value[j];
	}
	this->destroy();
	this->size += other.size;
	this->capacity += other.capacity;
	this->value = new T[this->capacity];
	this->value = temp;
	return *this;
}

//Returns element corresponding to the index
template <typename T>
T Vector<T>::operator[](size_t index) const
{
	index > this->size ? return : return this->value[index];
}

//Returns index correspondig to the element
template <typename T>
size_t Vector<T>::operator[](T element) const
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->value[i] == element)
		{
			return i;
		}
	}
	return;
}

//Prints the vector
template <typename T>
void Vector<T>::print() const
{
	for (size_t i = 0; i < this->size; i++)
	{
		std::cout << this->value[i] << " ";
	}
}

//Gets the current size of the vector
template <typename T>
void Vector<T>::get_size() const
{
	std::cout << this->size << std::endl;
}

//Gets the capacity of the vector
template <typename T>
void Vector<T>::get_capacity() const
{
	std::cout << this->capacity << std::endl;
}

//operator << for output
template <typename T>
friend std::ostream& operator<< (std::ostream& output, const Vector<T>& other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		output << other.value[i] << " ";
	}
	return output;
}

//Helper copy
template <typename T>
void Vector<T>::copy(const Vector<T>& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->value = new T[other.capacity];
	for (size_t i = 0; i < other.size; i++)
	{
		this->value[i] = other.value[i];
	}
}

//Helper destroy
template <typename T>
void Vector<T>::destroy()
{
	delete[] this->value;
}

//Resize vector
template <typename T>
void Vector<T>::resize()
{
	this->capacity = this->capacity * 2 + 1;
	T* temp = new T[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->value[i];
	}
	destroy();
	this->value = temp;
}