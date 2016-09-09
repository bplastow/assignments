/* ===============================================================================================
 *  avl.h  file to define functions
 *
 *  Created on: Sep 2, 2016
 *      Author: Blaine Plastow
 *      		A02235496
 *      		ECE 6460 VLSI Design and Automation
 *      		Homework 0
 *
 *      		AVL tree
   ===============================================================================================*/

#include<fstream>
#include<iostream>
using namespace std;

#ifndef AVL_H_
#define AVL_H_

class avl
{

private:

	// struct for the node for the BST AVL tree
	struct avlnode
	{
		int data;         //holds the data for the node
		int bf;           //holds the balance factor for each node so it can calculate it faster
		avlnode *left;    //pointer to left node
		avlnode *right;   //pointer to right node
		avlnode *parent;  //pointer to keep track of the parent node
	};

	avlnode *root;        //pointer to the root node

	//functions to do traversals
	void printinorderprivate(avlnode *ptr);   //helper function to print the tree in-order
	void printpreorderprivate(avlnode *ptr);  //helper function to print the tree pre-order
	void printpostorderprivate(avlnode *ptr); //helper function to print the tree post-order

	void setbalance(avlnode *ptr);  //function to set the balance factor for each node in the tree

	void rebalance(avlnode *ptr);  //function to rebalance the tree if the balance is > 2 or < -2
	avlnode *createleaf(int key, avlnode *p);    //function used to initiate a node in the tree
	avlnode *searchprivate(int key, avlnode *p); //function to search through the tree for a node

public:

	avl();                      //constructor for the avl tree
	avlnode *getroot();         //helper function to return the root of the tree

	//functions to help traverse the tree
	void printinorder();                      //function to print the tree in-order
	void printpreorder();					  //function to print the tree pre-order
	void printpostorder();					  //function to print the tree post-order
	void deletetree(avlnode* n);              //function to delete the entire tree
	void deletekey(int key);                  //function to delete a node in the tree
	int height(avlnode *p);                   //function to find the height of a certain node
	bool insert(int key);                     //function to insert a node in the tree

	//functions to help balance the tree
	avlnode *rright(avlnode *p);              //function to perform a right rotation at node
	avlnode *rleft(avlnode *p);               //function to perform a left rotation at node
	avlnode *rrleft(avlnode *p);              //function to perform a right then left rotation
	avlnode *rrright(avlnode *p);			  //function to perform a left then right rotation
	void search(ofstream &file, int val);     //function to search a node
	int checkbalance(avlnode *ptr);           //function to check the balance of a node in the tree

	//function used to write the tree traversals to a file
	void writetofilepreorder(ofstream &outputfile, avlnode *node);   //write the tree pre-order
	void writetofileinorder(ofstream &outputfile, avlnode *node);    //write the tree in-order
	void writetofilepostorder(ofstream &outputfile, avlnode *node);  //write the tree post-order
};



#endif /* AVL_H_ */
