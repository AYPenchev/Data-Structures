#pragma once
#include "Node.h"

template<typename T>
class BTree
{
public:
	BTree();
	BTree(const BTree<T>& source);
	BTree(const T&, const BTree<T>& left_tree, const BTree<T> &right_tree);
	~BTree();

	const BTree<T>& operator=(const BTree<T>& source);

	T& get_root() const;
	BTree<T> get_left() const;
	BTree<T> get_right() const;

	void inorder() const;
	void preorder() const;
	void postorder() const;

	bool empty() const;
	bool leaf() const;
	int height() const;

protected:
	Node<T>* root;

private:
	BTree(Node<T>* other);
	void copy_tree(Node<T>* &, Node<T>*);
	void delete_tree(Node<T>* &);

	int height(Node<T> *) const;

	void inorder(Node<T> *) const;
	void preorder(Node<T> *) const;
	void postorder(Node<T> *) const;
};

template <typename T>
BTree<T>::BTree()
{
	this->root = nullptr;
}

template <typename T>
BTree<T>::BTree(const BTree<T> &source)
{
	if (source.root == nullptr)
	{
		this->root = nullptr;
	}
	else
	{
		copy_tree(this->root, source.root);
	}
}

template <typename T>
BTree<T>::BTree(Node<T>* new_tree)
{
	this->root = new_tree;
}

template <typename T>
void BTree<T>::copy_tree(Node<T>* &new_tree, Node<T>* original)
{
	if (original == nullptr)
	{
		new_tree = nullptr;
	}
	else
	{
		new_tree = new Node<T>();
		new_tree->value = original->value;
		copy_tree(new_tree->left, original->left);
		copy_tree(new_tree->right, original->right);
	}
}

template <typename T>
void BTree<T>::delete_tree(Node<T>* &tree)
{
	if (tree != nullptr)
	{
		delete_tree(tree->left);
		delete_tree(tree->right);
		tree = nullptr;
	}
}

template <typename T>
BTree<T>::BTree(const T& val, const BTree<T> &left_tree, const BTree<T> &right_tree)
{
	this->root = new Node<T>(val, left_tree.root, right_tree.root);
}

template <typename T>
BTree<T>::~BTree()
{
	delete_tree(this->root);
}

template <typename T>
const BTree<T>& BTree<T>::operator=(const BTree<T>& source)
{
	if (this != &source)
	{
		if (root != nullptr)
		{
			delete_tree(root);
		}
		if (source.root == nullptr)
		{
			this->root = nullptr;
		}
		else
		{
			copy_tree(this->root, source.root);
		}
	}
	return *this;
}

template <typename T>
T& BTree<T>::get_root() const
{
	return root->value;
}

template <typename T>
BTree<T> BTree<T>::get_left() const
{
	if (this->root != nullptr)
	{
		return BTree<T>(this->root->left);
	}
	else
	{
		std::cout << "The tree is empty." << std::endl;
		exit(1);
	}
}

template <typename T>
BTree<T> BTree<T>::get_right() const
{
	if (this->root != nullptr)
	{
		return BTree<T>(this->root->right);
	}
	else
	{
		std::cout << "The tree is empty." << std::endl;
		exit(1);
	}
}

template <typename T>
void BTree<T>::inorder() const
{
	inorder(this->root);
}

template <typename T>
void BTree<T>::inorder(Node<T>* r) const
{
	if (r != nullptr)
	{
		inorder(r->left);
		process(r);
		inorder(r->right);
	}
}

template <typename T>
void BTree<T>::preorder() const
{
	preorder(this->root);
}

template <typename T>
void BTree<T>::preorder(Node<T>* r) const
{
	if (r != nullptr)
	{
		process(r);
		preorder(r->left);
		preorder(r->right);
	}
}

template <typename T>
void BTree<T>::postorder() const
{
	postorder(this->root);
}

template <typename T>
void BTree<T>::postorder(Node<T>* r) const
{
	if (r != nullptr)
	{
		postorder(r->left);
		postorder(r->left);
		process(r);
	}
}

template <typename T>
bool BTree<T>::empty() const
{
	return (this->root == nullptr);
}

template <typename T>
bool BTree<T>::leaf() const
{
	bool is_leaf = false;
	if (this->root != nullptr)
	{
		is_leaf = this->root->left == nullptr && root->right == nullptr;
	}
	return is_leaf;
}

template <typename T>
int BTree<T>::height() const
{
	return height(this->root);
}

template <typename T>
int BTree<T>::height(Node<T>* tree) const
{
	if (tree == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + max(height(tree->left), height(tree->right));
	}
}

template <typename T>
void process(Node<T> *r)
{
	std::cout << r->value << " ";
}