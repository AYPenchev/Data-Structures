#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T value;
	Node<T>* next;

	Node(const T& value, Node* next = NULL) : value(value), next(next) {}
};