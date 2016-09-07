/*
 * avl.cpp
 *
 *  Created on: Sep 2, 2016
 *      Author: Blaine
 */

#include <iostream>
#include <cstdlib>

#include "avl.h"

using namespace std;

avl::avl()
{
	root = NULL;
}

void avl::rebalance(avlnode *ptr)
{
	setbalance(ptr);

	if(ptr->bf == -2)
	{
		if(height(ptr->left->left) >= height(ptr->left->right))
			ptr = rright(ptr);
		else
			ptr = rrleft(ptr);
	}
	else if(ptr->bf == 2)
	{
		if(height(ptr->right->right) >= height(ptr->right->left))
			ptr = rleft(ptr);
		else
			ptr = rrright(ptr);
	}

	if(ptr->parent != NULL)
	{
		rebalance(ptr->parent);
	}
	else
	{
		root = ptr;
	}
}

void avl::setbalance(avlnode *ptr)
{
	ptr->bf = height(ptr->right) - height(ptr->left);
}

bool avl::insert(int key)
{
	if(root == NULL)
	{
		root = createleaf(key, NULL);
	}
	else
	{
		avlnode *n = root, *parent;

		while(true)
		{
			if(n->data == key)
			{
				cout << "Key " << key << " has already been added to the tree";
				return false;
			}

			parent = n;

			bool goleft = n->data > key;
			n = goleft ? n->left : n->right;

			if(n == NULL)
			{
				if(goleft)
				{
					parent->left = createleaf(key, parent);
				}
				else
				{
					parent->right = createleaf(key, parent);
				}

				rebalance(parent);
				break;
			}
		}
	}

	return true;
}

avl::avlnode *avl::createleaf(int key, avlnode *p){
	avlnode *n = new avlnode();
	n->data = key;
	n->left = NULL;
	n->right = NULL;
	n->parent = p;
	n->bf = 0;
	return n;
}

// function to delete a node key
void avl::deletekey(int key)
{
	if(root == NULL)
	{
		cout << "Node cannot be deleted tree is empty" << endl;
		return;
	}

	avlnode *n = root,
    *parent = root,
	*delnode = NULL,
	*child = root;

	while(child != NULL)
	{
		parent = n;
		n = child;
		child = key >= n->data ? n->right : n->left;
		if(key == n->data)
			delnode = n;
	}

	if(delnode != NULL)
	{
		delnode->data = n->data;

		child = n->left != NULL ? n->left : n->right;

		if(root->data == key)
		{
			root = child;
		}
		else
		{
			if(parent->left == n)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}

			rebalance(parent);
		}
	}

}

//function to delete tree
void avl::deletetree(avlnode *n)
{
	if(n != NULL)
	{
		deletetree(n->left);
		deletetree(n->right);
		free(n);
	}
}

// function to get the height of the node
int avl::height(avlnode *p)
{
	if(p == NULL)
	{
		return -1;
	}
	return 1 + max(height(p->left), height(p->right));
}


// right rotation
avl::avlnode *avl::rright(avlnode *a)
{
	avlnode *b = a->left;
	b->parent = a->parent;
	a->left = b->right;

	if(a->left != NULL)
		a->left->parent = a;

	b->right = a;
	a->parent = b;

	if(b->parent != NULL)
	{
		if(b->parent->right == a)
		{
			b->parent->right = b;
		}
		else
		{
			b->parent->left = b;
		}
	}

	setbalance(a);
	setbalance(b);
	return b;
}

// rotate left
avl::avlnode *avl::rleft(avlnode *a)
{
	avlnode *b = a->right;
	b->parent = a->parent;
	a->right = b->left;

	if(a->right != NULL)
		a->right->parent = a;

	b->left = a;
	a->parent = b;

	if(b->parent != NULL)
	{
		if(b->parent->right == a)
		{
			b->parent->right = b;
		}
		else
		{
			b->parent->left = b;
		}
	}

	setbalance(a);
	setbalance(b);
	return b;
}

// rotate left then right
avl::avlnode *avl::rrleft(avlnode *p)
{
	p->left = rleft(p->left);
	return rright(p);
}

//right then left rotation
avl::avlnode *avl::rrright(avlnode *p)
{
	p->right = rright(p->right);
	return rleft(p);
}



// functions to handle traversal

void avl::printinorder()
{
	printinorderprivate(root);
}

void avl::printinorderprivate(avlnode *ptr)
{
	if(root != NULL)
	{
		if(ptr->left != NULL)
		{
			printinorderprivate(ptr->left);
		}
		cout << ptr->data << " ";
		if(ptr->right != NULL)
		{
			printinorderprivate(ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty\n";
	}
}

void avl::printpreorder()
{
	printpreorderprivate(root);
}

void avl::printpreorderprivate(avlnode *ptr)
{
	if(root != NULL)
	{
		cout << ptr->data << " ";
		if(ptr->left != NULL)
		{
			printinorderprivate(ptr->left);
		}
		if(ptr->right != NULL)
		{
			printinorderprivate(ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty\n";
	}
}

void avl::printpostorder()
{
	printpostorderprivate(root);
}

void avl::printpostorderprivate(avlnode *ptr)
{
	if(root != NULL)
	{
		if(ptr->left != NULL)
		{
			printinorderprivate(ptr->left);
		}
		if(ptr->right != NULL)
		{
			printinorderprivate(ptr->right);
		}
		cout << ptr->data << " ";
	}
	else
	{
		cout << "The tree is empty\n";
	}
}

avl::avlnode *avl::getroot()
{
	return root;
}
