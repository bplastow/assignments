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

	avl mytree;

	while(1)
	{
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

				cout << "\nprinting the tree in order\nafter adding numbers\n" << endl;;

				mytree.printinorder();

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
				cout << "Tree deleted";
				break;
			case 7:
				cout << "case 2";
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
