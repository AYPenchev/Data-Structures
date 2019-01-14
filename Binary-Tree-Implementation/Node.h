#pragma once

template<typename T>
class Node
{
public:
	T value;
	Node<T>* left;
	Node<T>* right;
	
	Node(){}
	Node(const T& val, Node<T>* left_ptr = nullptr, Node<T>* right_ptr = nullptr)
	{
		this->value = val;
		this->left = left_ptr;
		this->right = right_ptr;
	}
};
