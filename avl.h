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
	};

	avlnode *root;

	avlnode *getroot();
	avlnode *insertprivate(int key, avlnode *ptr);
	void printinorderprivate(avlnode *ptr);
	void printpreorderprivate(avlnode *ptr);
	void printpostorderprivate(avlnode *ptr);


public:

	avl();
	avlnode *createleaf(int key);
	avlnode *insert(int key);
	void printinorder();
	void printpreorder();
	void printpostorder();
	int height(avlnode *p);
	void fixheight(avlnode *p);
	int bfactor(avlnode *p);
	avlnode *rright(avlnode *p);
	avlnode *rleft(avlnode *p);
	avlnode *rrleft(avlnode *p);
	avlnode *rrright(avlnode *p);
	avlnode *balance(avlnode *p);
	int heighthelper();


};



#endif /* AVL_H_ */
