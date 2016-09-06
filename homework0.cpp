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
#include <fstream>

#include "avl.h"

using namespace std;

int main()
{
	int option;
	//int treekeys[9] = {36, 17, 5, 30, 28, 81, 37, 76, 83};
	avl mytree;

	cout << "Choose the option you want to perform" << endl;

	cout << "1. Create_Tree" << endl;
	cout << "2. Insertion" << endl;
	cout << "3. Deletion" << endl;
	cout << "4. Search" << endl;
	cout << "5. Traversal" << endl;
	cout << "6. Delete_Tree" << endl;
	cout << "7. Check_Balance" << endl;

	cin >> option;

	int output;
	ifstream file;

	switch(option)
	{
		case 1:
			file.open("input.txt");
			if(file.is_open())
			{
				while(!file.eof())
				{
					file >> output;
					//cout << output << endl;
					mytree.insert(output);
				}
			}
			file.close();
			break;
		case 2:
			cout << "case 2";
			break;
		case 3:
			cout << "case 2";
			break;
		case 4:
			cout << "case 2";
			break;
		case 5:
			cout << "case 2";
			break;
		case 6:
			cout << "case 2";
			break;
		case 7:
			cout << "case 2";
			break;
		default:
			cout << "Not a valid option try again";
			break;
	}

	cout << "printing the tree in order\nafter adding numbers\n";

	mytree.printinorder();

	int bob = mytree.heighthelper();

	cout << "\nThe height of the tree is " << bob << endl;

	return 0;
}
