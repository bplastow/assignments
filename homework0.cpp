/*
 * homework0.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: Blaine Plastow
 *      		ECE6460
 *
 *      		AVL Tree
 */

#include <iostream>
#include <cstdlib>

#include "avl.h"

using namespace std;

int main()
{
	int treekeys[9] = {36, 17, 5, 30, 28, 81, 37, 76, 83};
	avl mytree;

	cout << "printing the tree in order\nbefore adding numbers\n";

	mytree.printinorder();

	for(int i = 0; i < 9; i++)
	{
		 mytree.insert(treekeys[i]);
	}

	cout << "printing the tree in order\nafter adding numbers\n";

	mytree.printinorder();

	int bob = mytree.heighthelper();

	cout << "\nThe height of the tree is " << bob << endl;

	return 0;
}
