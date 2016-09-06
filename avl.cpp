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

avl::avlnode *avl::createleaf(int key){
	avlnode *n = new avlnode();
	n->data = key;
	n->left = NULL;
	n->right = NULL;
	n->bf = 0;
	return n;
}

// function to get the height of the node
int avl::height(avlnode *p)
{
	if(p == NULL)
	{
		return -1;
	}
	int hl = height(p->left);
	int hr = height(p->right);
	return (hl > hr ? hl : hr) + 1;
}

// function to find the balance factor
int avl::bfactor(avlnode *p)
{
	if(p == NULL)
	{
		return 0;
	}
	else
	{
		return height(p->left) - height(p->right);
	}
}

// rrrotation function to rotate right
avl::avlnode *avl::rright(avlnode *a)
{
	avlnode *b = a->left;
	a->left = b->right;
	b->right = a;
	return b;
}

// llrotation
avl::avlnode *avl::rleft(avlnode *a)
{
	avlnode *b = a->right;
	a->right = b->left;
	b->left = a;
	return b;
}

// lrrotation
avl::avlnode *avl::rrleft(avlnode *p)
{
	avlnode *t = p->left;
	p->left = rleft(t);
	return rright(p);
}

//rlrotation
avl::avlnode *avl::rrright(avlnode *p)
{
	avlnode *t = p->right;
	p->right = rright(t);
	return rleft(p);
}

// function to balance the tree
avl::avlnode *avl::balance(avlnode *p)
{
	int bf = bfactor(p);
	if(bf == 2)
	{
		if(bfactor(p->left) > 0)
			p = rright(p);
		else
			p = rrleft(p);
	}
	else if(bf == -2)
	{
		if(bfactor(p->right) < 0)
			p = rleft(p);
		else
			p = rrright(p);
	}
	return p;
}


avl::avlnode *avl::insert(int key)
{
	return insertprivate(key, root);
}

avl::avlnode *avl::insertprivate(int key, avlnode *ptr)
{
	if(root == NULL)
	{
		root = createleaf(key);
	}
	else if(key < ptr->data)
	{
		if(ptr->left != NULL)
		{
			insertprivate(key, ptr->left);
			//ptr->left = balance(ptr->left);
		}
		else
		{
			ptr->left = createleaf(key);
			//ptr->left = balance(ptr->left);
		}
	}
	else if(key > ptr->data)
	{
		if(ptr->right != NULL)
		{
			insertprivate(key, ptr->right);
			//ptr->right = balance(ptr->right);
		}
		else
		{
			ptr->right = createleaf(key);
			//ptr->right = balance(ptr->right);
		}
	}
	else
	{
		cout << "The key " << key << " has already been added to the tree\n";
	}
	//balance(ptr);
	return ptr;
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

}

void avl::printpostorder()
{
	printpostorderprivate(root);
}

void avl::printpostorderprivate(avlnode *ptr)
{

}

avl::avlnode *avl::getroot()
{
	return root;
}

int avl::heighthelper()
{
	int height1 = height(getroot());
	return height1;
}
