#pragma once
#include "BTree.h"

template <typename T>
class BSTree : public BTree<T>
{
public:
	BSTree();
	BSTree(const T&, const BSTree<T> &left_tree, const BSTree<T> &right_tree);

	bool find(const T&) const;
	void insert(const T&);
	void delete_node(const T&);

private:
	bool find(const Node<T>*, const T&) const;
	void insert(Node<T>* &, const T&);
	void delete_node(Node<T>* &, const T&);

};

template <typename T>
BSTree<T>::BSTree() : BTree()
{}

template <typename T>
BSTree<T>::BSTree(const T &, const BSTree<T>& left_three, const BSTree<T>& right_three) : BTree(val, left_tree, right_tree)
{}

template <typename T>
bool BSTree<T>::find(const T &) const
{
	return find(root, val);
}

template <typename T>
bool BSTree<T>::find(const Node<T>* tree, const T &val) const
{
	if (tree == nullptr)
	{
		return false;
	}
	else if (val < tree->value)
	{
		return find(tree->left, val);
	}
	else if (val > tree->value)
	{
		return find(tree->right, val);
	}
	else
	{
		return true;
	}
}

template <typename T>
void BSTree<T>::insert(const T & val)
{
	insert(this->root, val);
}

template <typename T>
void BSTree<T>::insert(Node<T>* &tree, const T &val)
{
	if (tree == nullptr)
	{
		tree = new Node<T>(val);
	}
	else if(val <= tree->value)
	{
		insert(tree->left, val);
	}
	else
	{
		insert(tree->right, val);
	}
}

template <typename T>
void BSTree<T>::delete_node(const T &)
{
	delete_node(root, val);
}

template <typename T>
void BSTree<T>::delete_node(Node<T>* &tree, const T &val)
{
	if (tree == nullptr)
	{
		return;
	}
	if (val < tree->value)
	{
		delete_node(tree->left, val);
	}
	else if (val > tree->value)
	{
		delete_node(tree->right, val);
	}
	else
	{
		Node<T>* temp_ptr;
		if (tree->left == nullptr)
		{
			temp_ptr = tree->right;
			delete tree;
			tree = temp_ptr;
		}
		else if(tree->right == nullptr)
		{
			temp_ptr = tree->left;
			delete tree;
			tree = temp_ptr;
		}
		else
		{
			temp_ptr = tree->right;
			while (temp_ptr->left != nullptr)
			{
				temp_ptr = temp_ptr->left;
			}
			tree->value = temp_ptr->value;
			delete_node(tree->right, temp_ptr->value);
		}
	}
}