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
	LList<T>& operator=(const LList<T>& other);

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
	Node<T> get_value();
	
	//Changes the value of node
	void set_value(Node<T> element, size_t index);

	//Search in linked list
	bool find(Node<T> element);

	//Check if linked list is empty
	bool is_empty() const;

	//Returns the number of nodes
	size_t size() const;

	//Output
	friend std::ostream& operator<< (std::ostream& output, const LList<T>& other);
	
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
	Node<T>* locate(size_t index);
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

//Overloading operator =
template<typename T>
LList<T>& LList<T>:: operator=(const LList<T>& other)
{
	if (this != &other)
	{
		this->destroy_list();
		this->copy_list(other);
	}
	return *this;
}

//Destructor
template <typename T>
LList<T>::~LList()
{
	this->destroy_list();
}

//Returns the address of the first node
template <typename T>
Node<T>* LList<T>::begin()
{
	this->current = this->first;
	return this->first;
}

//Position on the next node
template <typename T>
Node<T>* LList<T>::next()
{
	this->current = this->current->next;
	return this->current;
}

//Recognize the end of the linked list
template <typename T>
Node<T>* LList<T>::end()
{
	return NULL;
}

//Push element in front
template<typename T>
void LList<T>::push_front(Node<T> element)
{
	if (this->first != NULL)
		this->first = new Node<T>(element, this->first);
	else
	{
		this->first = new Node<T>(element, this->first);
		this->last = this->first;
	}
	this->++len;
	return;
}

template<typename T>
void LList<T>::push_back(Node<T> element)
{
	if (this->first == NULL)
	{
		this->first = new Node<T>(element);
		this->last = this->first;
		this->++len;
		return;
	}
	//Adds new node after the last one
	Node* last_node = this->last;
	last_node->next = new Node<T>(element);
	this->last = last_node->next;
	this->++len;
}

template<typename T>
void LList<T>::pop_front()
{
	if (this->first == NULL)
		return;
	else if (this->first->next == NULL)
		this->last == NULL;
	Node<T>* ptr_node = this->first;
	this->first = this->first->next;
	delete ptr_node;
	this->--len;
}

template<typename T>
void LList<T>::pop_back()
{
	if (this->first == NULL) return;
	else if (this->first->next == NULL)
	{
		delete this->first;
		this->first = NULL;
		this->last = NULL;
		this->--len;
		return;
	}
	Node* ptr_last = this->first;
	Node* ptr_prev;
	while (ptr_last->next != NULL)
	{
		ptr_prev = ptr_last;
		ptr_last = ptr_last->next;
	}
	this->last = ptr_prev;
	this->last->next = NULL;
	delete ptr_last;
	this->--len;
}

template<typename T>
void LList<T>::delete_node(Node<T> element)
{
	if (this->first == NULL) return;
	if (this->first->value == element)
	{
		Node<T>* ptr_del = this->first;
		if (this->first->next != NULL)
			this->first = this->first->next;
		else
		{
			this->first = NULL;
			this->last = NULL;
		}
		delete ptr_del;
		this->--len;
		return;
	}
	Node<T>* current = this->first;
	while (current->next != NULL && current->next->value != element)
		current = current->next;
	if (current->next != NULL)
	{
		Node<T>* ptr_del = current->next;
		current->next = current->next->next;
		delete ptr_del;
		this->--len;
		return;
	}
}

template<typename T>
Node<T> LList<T>::get_value(size_t index)
{
	Node<T>* ptr_pos = locate(index);
	assert(ptr_pos != NULL);
	return ptr_pos->value;
}

template<typename T>
Node<T> LList<T>::get_value()
{
	assert(this->current != NULL);
	return this->current->value;
}

template<typename T>
void LList<T>::set_value(Node<T> element, size_t index)
{
	Node<T>* ptr_inx = location(index);
	assert(ptr_inx != NULL);
	ptr_inx->value = element;
}

template<typename T>
bool LList<T>::find(Node<T> element)
{
	if (this->first == NULL)
		return false;
	bool found = false;
	Node<T>* ptr_node = this->first;
	while (ptr_node != NULL && !found)
		if (ptr_node->value != element)
			ptr_node = ptr_node->next;
		else
			found = true;
	return found;
}

template<typename T>
bool LList<T>::is_empty() const
{
	return this->first = NULL;
}

template<typename T>
size_t LList<T>::size() const
{
	return this->len;
}

//Helper copy
template <typename T>
void LList<T>::copy_list(const LList& other)
{
	Node<T> *ptr_new;
	Node<T> *current;

	if (this->first != NULL)
		destroy_list();
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

template<typename T>
void LList<T>::destroy_list()
{
	Node<T>* ptr_node;
	while (this->first != NULL)
	{
		ptr_node = this->first;
		this->first = this->first->next;
		delete ptr_node;
	}
	this->last = NULL;
	this->len = 0;
}

template<typename T>
Node<T>* LList<T>::locate(size_t index)
{
	Node<T>* ptr_node = this->first;
	for (size_t i = 1; (i < index && ptr_node != NULL); ++i)
		ptr_node = ptr_node->next;
	return ptr_node;
}

