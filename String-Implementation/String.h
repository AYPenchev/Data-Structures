#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#pragma warning(disable : 4996)

class String
{
public:
	//Default constructor
	String();

	//Constructor
	String(const char* value);

	//Copy constructor
	String(const String& other);

	//Operator =
	String& operator=(const String& other);
	
	//Destructor
	~String();

	//Print function
	void print() const;

	//Concat strings
	String operator+(const String other);

	//Convert string to char*
	char* ConvertToPointer();

	//Get element from index
	char operator[] (size_t index);

	//Output
	friend std::ostream& operator<< (std::ostream& output,const String& other);

	//Input
	friend std::istream& operator>> (std::istream& input, String& other);
private:
	//Data member
	char* value;

	//Helper copy
	void copy(const String& other);
	
	//Helper destroy
	void destroy();
};