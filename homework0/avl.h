/*
 * avl.h
 *
 *  Created on: Sep 2, 2016
 *      Author: Blaine
 */

#ifndef AVL_H_
#define AVL_H_

class avl
{

private:

	struct avlnode
	{
		int data;
		int bf;
		avlnode *left;
		avlnode *right;
		avlnode *parent;
	};

	avlnode *root;

	void printinorderprivate(avlnode *ptr);
	void printpreorderprivate(avlnode *ptr);
	void printpostorderprivate(avlnode *ptr);
	void setbalance(avlnode *ptr);
	void rebalance(avlnode *ptr);
	avlnode *createleaf(int key, avlnode *p);
	avlnode *searchprivate(int key, avlnode *p);

public:

	avl();
	avlnode *getroot();
	void printinorder();
	void printpreorder();
	void printpostorder();
	void deletetree(avlnode* n);
	void deletekey(int key);
	int height(avlnode *p);
	bool insert(int key);
	avlnode *rright(avlnode *p);
	avlnode *rleft(avlnode *p);
	avlnode *rrleft(avlnode *p);
	avlnode *rrright(avlnode *p);
	avlnode *balance(avlnode *p);
	void search(int val);

};



#endif /* AVL_H_ */
