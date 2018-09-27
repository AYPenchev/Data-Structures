#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class LList
{
public:
	//Default constructor
	LList();

	//Copy constructor
	LList(const LList& other);
	
	//Overloading operator =
	LList& operator=(const LList& other);

	//Destructor
	~LList();

	//Returns the address of the first node
	Node<T>* begin();

	//Position on the next node
	Node<T>* next();

	//Recognize the end of the linked list
	Node<T>* end();

	//Push element in front
	void push_front(Node<T> element);

	//Push element at the back
	void push_back(Node<T> element);

	//Pop the first element
	void pop_front();

	//Pop the last element
	void pop_back();

	//Deletes node under precise condition
	void delete_node(Node<T> element);

	//Returns element corresponding to the index
	Node<T> get_value(size_t index);

	//Returns element corresponding to the index
	//Node<T> LList::get_value();
	
	//Changes the value of node
	void set_value(Node<T> element, size_t index);

	//Search in linked list
	bool find(Node<T> element);

	//Check if linked list is empty
	bool is_empty() const;

	//Returns the number of nodes
	size_t size() const;

	//Output
	friend std::ostream& operator<< (std::ostream& output, const LList& other);
	
private:
	//Pointer to first node
	Node<T>* first;

	//Pointer to last node
	Node<T>* last;

	//Pointer to current node
	Node<T>* current;

	//Number of nodes in the linked list
	size_t len;

	//Helper copy
	void copy_list(const LList& other);

	//Helper destroy
	void destroy_list();

	//Returns the address of node by given index
	Node<T>* locate(size_t);
};

//Default constructor
template <typename T>
LList<T>::LList()
{
	this->first = NULL;
	this->last = NULL;
	this->current = NULL;
	this->len = 0;
}

//Copy constructor
template <typename T>
LList<T>::LList(const LList& other)
{
	this->first = NULL;
	this->copy_list(other);
}

//Destructor
template <typename T>
LList<T>::~LList()
{
	this->destroy_list();
}

//Helper copy
template <typename T>
void LList<T>::copy_list(const LList& other)
{
	Node<T> *ptr_new;
	Node<T> *current;

	if (this->first != NULL) : destroy_list() {}//kostaa
	if (other.first == NULL)
	{
		this->first = NULL;
		this->last = NULL;
		this->current = NULL;
		this->len = 0;
	}
	//Initialize and copy the first node
	this->current = original.first;
	this->first = new Node<T>(this->current->value);
	this->last = this->first;
	this->current = this->current->next;
	while (this->current != NULL)
	{
		//Create new node
		ptr_new = new Node<T>(this->current->value);
		//New node is inheritor of the previous one
		this->last->next = ptr_new;
		this->last = ptr_new;
		this->current = this->current->next;
	}
	this->len = other.len;
}
