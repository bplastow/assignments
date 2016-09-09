/* ===============================================================================================
 *  avl.cpp  file to implement functions for making the AVL tree
 *
 *  Created on: Sep 2, 2016
 *      Author: Blaine Plastow
 *      		A02235496
 *      		ECE 6460 VLSI Design and Automation
 *      		Homework 0
 *
 *      		AVL tree
   ===============================================================================================*/


#include <iostream>                                 //include file so you can use cout
#include <cstdlib>

#include "avl.h"                                    //include avl.h custom file for function definitions

using namespace std;                                //use namespace standard so you don't have to
                                                    //type std::cout everytime to use cout
//constructor for avl tree
avl::avl()                                          //set the root = NULL in the constructor
{
	root = NULL;
}

//function to rebalance the tree when the bf is 2 or -2
void avl::rebalance(avlnode *ptr)
{
	setbalance(ptr);                                         //set the bf for the node first

	if(ptr->bf == -2)
	{
		if(height(ptr->left->left) >= height(ptr->left->right)) //if the tree is unbalanced
			ptr = rright(ptr);                                  //then perform rotations
		else
			ptr = rrleft(ptr);                                  //double rotation
	}
	else if(ptr->bf == 2)
	{
		if(height(ptr->right->right) >= height(ptr->right->left))
			ptr = rleft(ptr);                                    //rotate left around node
		else
			ptr = rrright(ptr);                                  //double rotation
	}

	if(ptr->parent != NULL)                                      //if the parent is not NULL
	{                                                            //then see if the parent needs
		rebalance(ptr->parent);                                  //to be rebalanced
	}
	else
	{
		root = ptr;                                              //otherwise set the node as
	}                                                            //the root node
}

// function to check the balance of the root node
int avl::checkbalance(avlnode *ptr)
{
	return ptr->bf;                                             //return the balance factor of node
}

// function to set the balance of a node
void avl::setbalance(avlnode *ptr)
{
	ptr->bf = height(ptr->right) - height(ptr->left);          //bf = right height - left height
}

// function to search through the tree for a value
void avl::search(ofstream &file, int val)
{
	avlnode *n = searchprivate(val, root);                     //find the node where the value
	if(n == NULL)                                              //you are looking for is.  if the
	{														   //node is NULL and the Root is NULL
		if(root == NULL){                                      //then the tree is empty
			cout << "Tree is empty" << endl;
			file << "Tree is empty" << endl;
		}
		else
		{
			cout << "Node " << val << " was not found in the tree" << endl;  //otherwise the value
			file << "Node " << val << " was not found in the tree" << endl;  //was not found in
		}                                                                    //the tree
	}
	else
	{
		cout << "Node " << val << " was found at height " <<  height(n) << endl;  //print out the
		file << "Node " << val << " was found at height " <<  height(n) << endl;  //height where
	}                                                                             //the value
}                                                                                 //was found

//helper function to search the tree
avl::avlnode *avl::searchprivate(int key, avlnode *p)
{
	if(p == NULL || p->data == key)              //if the node is NULL or the key was found
	{                                            //return that node
		return p;
	}

	if(p->data < key)                            //otherwise recursively search through the tree
	{                                            //for the value
		return searchprivate(key, p->right);     //if the key is greater than the data then go
	}                                            //search right otherwise search left
	else{
		return searchprivate(key, p->left);
	}

}

// function to insert a node into the tree
bool avl::insert(int key)
{
	if(root == NULL)								  //if the tree is empty then create a node
	{                                                 // with the createleaf function
		root = createleaf(key, NULL);                 //set root to key and parent to NULL because
	}                                                 //the root is first value in tree
	else
	{
		avlnode *n = root, *parent;                   //create a temp node to search through tree

		while(true)
		{
			if(n->data == key)                        //if the value is already in the tree
			{                                         //then don't insert anything and print a message
				cout << "Node " << key << " has already been added to the tree" << endl;
				return false;
			}

			parent = n;                              //set the parent to the root first
                                                     //then start at the root and see if need to
			bool goleft = n->data > key;             //go left or right to insert value. if key
			n = goleft ? n->left : n->right;         //is < data then go left

			if(n == NULL)                            //if the node is NULL then the node is empty
			{                                        //so go left or right and createleaf there
				if(goleft)                           //and point parent to node
				{
					parent->left = createleaf(key, parent);
				}
				else
				{
					parent->right = createleaf(key, parent);
				}

				rebalance(parent);                    //rebalance tree if it needs it after inserting
				break;                                //node
			}
		}
	}

	return true;
}

// function to create a leaf if the node is NULL
avl::avlnode *avl::createleaf(int key, avlnode *p){
	avlnode *n = new avlnode();                          //create node
	n->data = key;                                       //initiate data to key value
	n->left = NULL;                                      //set left and right pointers
	n->right = NULL;                                     //to NULL to help traverse tree
	n->parent = p;                                       //set the parent to the node on
	n->bf = 0;                                           //set the initial balance factor to zero
	return n;                                            //return the created node
}

// function to delete a node key
void avl::deletekey(int key)
{
	if(root == NULL)                                             //if the root is NULL then the
	{                                                            //tree is empty and so nothing
		cout << "Node cannot be deleted tree is empty" << endl;  //can be deleted
		return;
	}

	avlnode *n = root,                                   //set node n to the root and also the
    *parent = root,                                      //parent to the root
	*delnode = NULL,                                     //pointer for node to delete set to NULL
	*child = root;                                       //initially until find location of node
                                                         //to delete. Set the child to root as well
	while(child != NULL)
	{
		parent = n;
		n = child;
		child = key >= n->data ? n->right : n->left;     //if the key is >= data then go right
		if(key == n->data)                               //otherwise go left
			delnode = n;								 //if value is found in tree then set
	}                                                    //delnode to node with key value

	if(delnode != NULL)
	{
		delnode->data = n->data;

		child = n->left != NULL ? n->left : n->right;    //Travel down until you find node to delete

		if(root->data == key)
		{
			root = child;                                //if it is root to delete then set it to
		}                                                //child
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

			rebalance(parent);                            //rebalance tree if needed after deletion
		}
	}
	else
		cout << "Node cannot be found. Deletion cannot be performed" << endl;  //node was not found
}

//function to delete tree
void avl::deletetree(avlnode *n)
{
	if(n != NULL)
	{
		deletetree(n->left);                        //delete the tree recursively by deleting
		deletetree(n->right);                       //the left and then right nodes then set root
		free(n);                                    //to NULL
	}
	root = NULL;
}

// function to get the height of the node
int avl::height(avlnode *p)
{
	if(p == NULL)
	{
		return -1;                                          //recursively check the height of each
	}                                                       //node if is NULL then set it to -1 and
	return 1 + max(height(p->left), height(p->right));      //it is a leaf node
}


// right rotation
avl::avlnode *avl::rright(avlnode *a)
{
	avlnode *b = a->left;
	b->parent = a->parent;                                //create a temp node and then set it to
	a->left = b->right;                                   //a then set the parent to the other parent
                                                          //a left is now b left
	if(a->left != NULL)
		a->left->parent = a;                              //if the left is not NULL then set that
                                                          //parent as a
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

	setbalance(a);                                         //after rotating update the balance
	setbalance(b);                                         //factors for nodes a and b
	return b;                                              //return the rotated tree
}

// rotate left
avl::avlnode *avl::rleft(avlnode *a)
{
	avlnode *b = a->right;                                 //similar to rotate left but now you
	b->parent = a->parent;                                 //are rotating it right
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
	p->left = rleft(p->left);                             //rotate the left node left and then
	return rright(p);                                     //rotate the p node right to balance
}

//right then left rotation
avl::avlnode *avl::rrright(avlnode *p)
{
	p->right = rright(p->right);                          //rotate the right node right and then
	return rleft(p);                                      //rotate the p node left to balance
}



// functions to handle traversal

// function to print in-order
void avl::printinorder()
{
	printinorderprivate(root);
}

// helper function for print in-order
void avl::printinorderprivate(avlnode *ptr)
{
	if(root != NULL)
	{
		if(ptr->left != NULL)                        //if the tree is not empty then first traverse
		{                                            //left and then print node data then
			printinorderprivate(ptr->left);          //then traverse right
		}
		cout << ptr->data << " ";
		if(ptr->right != NULL)
		{
			printinorderprivate(ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty" << endl;         //if the root is NULL then the tree is empty
	}
}

//function to print pre-order
void avl::printpreorder()
{
	printpreorderprivate(root);
}

// helper function for the print pre-order
void avl::printpreorderprivate(avlnode *ptr)
{
	if(root != NULL)
	{
		cout << ptr->data << " ";                   //first print the node data and then traverse
		if(ptr->left != NULL)                       // left and then right and print out the tree
		{
			printpreorderprivate(ptr->left);
		}
		if(ptr->right != NULL)
		{
			printpreorderprivate(ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty" << endl;
	}
}

// function to print post-order
void avl::printpostorder()
{
	printpostorderprivate(root);
}

// helper function to print post-order
void avl::printpostorderprivate(avlnode *ptr)
{
	if(root != NULL)
	{
		if(ptr->left != NULL)                         //if the tree is not empty then traverse
		{                                             //left and then right and then print out
			printpostorderprivate(ptr->left);         //the node data
		}
		if(ptr->right != NULL)
		{
			printpostorderprivate(ptr->right);
		}
		cout << ptr->data << " ";
	}
	else
	{
		cout << "The tree is empty" << endl;
	}
}

// Function to write the tree to a file in pre-order traversal
void avl::writetofilepreorder(ofstream &outputfile, avlnode *node)
{
	if(root != NULL)
	{
		outputfile << node->data << " ";                     //similar to traversal except it is
		if(node->left != NULL)                               //writing to a file
		{
			writetofilepreorder(outputfile, node->left);
		}
		if(node->right != NULL)
		{
			writetofilepreorder(outputfile, node->right);
		}
	}
	else
	{
		outputfile << "The tree is empty" << endl;
	}
}

// Function to write the tree to a file in in-order traversal
void avl::writetofileinorder(ofstream &outputfile, avlnode *node)
{
	if(root != NULL)
	{
		if(node->left != NULL)                                   //similar to traversal but
		{                                                        //writes to file instead of
			writetofileinorder(outputfile, node->left);          //console
		}
		outputfile << node->data << " ";
		if(node->right != NULL)
		{
			writetofileinorder(outputfile, node->right);
		}
	}
	else
	{
		outputfile << "The tree is empty" << endl;
	}
}

// Function to write the tree to a file in post-order traversal
void avl::writetofilepostorder(ofstream &outputfile, avlnode *node)
{
	if(root != NULL)
	{
		if(node->left != NULL)                                     //similar to traversal but
		{                                                          //writes tree to file instead
			writetofilepostorder(outputfile, node->left);          //of to console
		}
		if(node->right != NULL)
		{
			writetofilepostorder(outputfile, node->right);
		}
			outputfile << node->data << " ";
		}
		else
		{
			outputfile << "The tree is empty" << endl;
		}
}

// function used to get the root node
avl::avlnode *avl::getroot()
{
	return root;                                            //return the root node
}
