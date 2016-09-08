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

#define FILENAME "plastow-A02235496.txt",ios::app

using namespace std;

int main()
{
	int option;
	int option2;
	int number;

	ofstream outfile;
	ifstream file;

	outfile.open(FILENAME);

	avl mytree;

	while(1)
	{
		cout << endl;
		cout << "Choose the option you want to perform" << endl;

		cout << "1. Create_Tree" << endl;
		cout << "2. Insertion" << endl;
		cout << "3. Deletion" << endl;
		cout << "4. Search" << endl;
		cout << "5. Traversal" << endl;
		cout << "6. Delete_Tree" << endl;
		cout << "7. Check_Balance" << endl;
		cout << "8. Exit" << endl;

		cin >> option;

		int output;

		switch(option)
		{
			case 1:
				mytree.deletetree(mytree.getroot());
				file.open("input.txt");
				if(file.is_open())
				{
					while(!file.eof())
					{
						file >> output;
						mytree.insert(output);
					}
				}
				file.close();

				cout << "Create Tree: ";

				outfile << "test";

				mytree.printpreorder();

				cout << endl;

				outfile.close();

				break;
			case 2:
				cout << "Enter number to add to tree" << endl;
				cin >> number;
				mytree.insert(number);
				cout << "Updated tree: ";
				mytree.printpreorder();
				break;
			case 3:
				cout << "Enter a number to be deleted from tree" << endl;
				cin >> number;
				mytree.deletekey(number);
				cout << "Updated tree: ";
				mytree.printpreorder();
				break;
			case 4:
				cout << "Enter a number to search for in tree" << endl;
				cin >> number;
				mytree.search(number);
				break;
			case 5:
				cout << "what type of traversal:" << endl;
				cout << "1. Pre_order" << endl;
				cout << "2. Post_order" << endl;
				cout << "3. In_order" << endl;
				cin >> option2;

				switch(option2)
				{
					case 1:
						cout << "Pre-order: ";
						mytree.printpreorder();
						cout << endl;
						break;
					case 2:
						cout << "Post-order: ";
						mytree.printpostorder();
						cout << endl;
						break;
					case 3:
						cout << "In-order: ";
						mytree.printinorder();
						cout << endl;
						break;
				}

				break;
			case 6:
				mytree.deletetree(mytree.getroot());
				cout << "Delete Tree: Tree deleted";
				break;
			case 7:
				if(mytree.getroot() == NULL)
				{
					cout << "The tree is empty" << endl;
				}
				else
				{
					cout << "Check Balance: ";
					cout << mytree.checkbalance(mytree.getroot()) << endl;
				}
				break;
			case 8:
				exit(1);
				break;
			default:
				cout << "Not a valid option try again";
				break;
		}
	}

	return 0;
}
