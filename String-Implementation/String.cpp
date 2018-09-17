#include "stdafx.h"
#include "String.h"

//Default constructor
String::String()
{
	this->value = new char[1];
	strcpy_s(this->value, 1, "");
}

//Constructor
String::String(const char* value)
{
	size_t other_value_len = strlen(value) + 1;
	this->value = new char[other_value_len];
	strcpy_s(this->value, other_value_len, value);
}

//Copy constructor
String::String(const String& other)
{
	this->copy(other);
}

//Operator =
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		this->destroy();
		this->copy(other);
	}
	return *this;
}

//Destructor
String::~String()
{
	this->destroy();
}

//Print function
void String::print() const
{
	std::cout << this->value << std::endl;
}

//Concat strings
String String::operator+(const String other)
{
	size_t len = strlen(this->value) + strlen(other.value) + 1;
	char* new_value = new char[len];
	strcpy_s(new_value, len, this->value);
	strcat(new_value, other.value);
	return new_value;
}

//Convert string to char*
char* String::ConvertToPointer()
{
	return this->value;
}

//Get element from index
char String::operator[](size_t index)
{
	return (strlen(this->value) >= index) ? this->value[index] : '\0';
}

//Output
std::ostream& operator<<(std::ostream& output,const String& other)
{
	output << other.value << std::endl;
	return output;
}

//Input
std::istream& operator>>(std::istream& input, String& other)
{
	other.value = new char[1024];
	input.getline(other.value, 1024);
	return input;
}

//Helper copy
void String::copy(const String& other)
{
	size_t other_value_len = strlen(other.value) + 1;
	this->value = new char[other_value_len];
	strcpy_s(this->value, other_value_len, other.value);
}

//Helper destroy
void String::destroy()
{
	delete[] this->value;
}