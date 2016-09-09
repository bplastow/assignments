/*==============================================================================================
 * homework0.cpp  Main file for the assignment
 *
 *  Created on: Sep 1, 2016
 *      Author: Blaine Plastow
 *              A02235496
 *      		ECE 6460 VLSI Design and Automation
 *				Homework 0
 *
 *      		AVL Tree
 * ==============================================================================================*/

#include <iostream>
#include <cstdlib>
#include <fstream>

#include "avl.h"

#define FILENAME "plastow-A02235496.txt",ios::app  //create a filename and make so can append
                                                   //to file for output file
using namespace std;

int main()
{
	int option;                        //used for user selection of option to perform on tree
	int option2;                       //used for user selection of traversal type
	int number;                        //used to store the node for inserting and deleting

	ofstream outfile;                  //used as output file to right to
	ifstream file;                     //used for input.txt file to read in tree values to add

	outfile.open(FILENAME);            //open output file for writing

	avl mytree;                        //create an empty avl tree

	//wiat for the user to enter values and to modify the tree
	while(1)
	{
		cout << endl;
		cout << "Choose the option you want to perform" << endl;  //have the user choose an option

		//different options for the user to pick from
		cout << "1. Create_Tree" << endl;
		cout << "2. Insertion" << endl;
		cout << "3. Deletion" << endl;
		cout << "4. Search" << endl;
		cout << "5. Traversal" << endl;
		cout << "6. Delete_Tree" << endl;
		cout << "7. Check_Balance" << endl;
		cout << "8. Exit" << endl;

		cin >> option;                     //get the option form the user and save it in var option

		//if the user puts in a letter or anything that is not an int then keep asking them for
		//an integer until they give you one
		while(cin.fail())
		{
			cout << "You must enter an integer value" << endl;  //the user has to enter an integer
			cin.clear();                                        //to go on
			cin.ignore(256, '\n');
			cin >> option;
		}

		int output;                   //used to store the values read in from input.txt

		switch(option)                //used for users to select an option
		{
			case 1:
				mytree.deletetree(mytree.getroot());    //first delete tree and then create tree
				file.open("input.txt");                 //from input file
				if(file.is_open())                      //if the file is open then start reading
				{                                       //the values and storing it in the tree
					while(!file.eof())
					{
						file >> output;
						mytree.insert(output);          //insert the value in the tree
					}
				}
				file.close();                           //close the file when done reading from

				cout << "Create Tree: ";

				outfile << "Create Tree: ";                //create the tree and print out tree
				mytree.printpreorder();                    //in pre-order traversal
				mytree.writetofilepreorder(outfile, mytree.getroot());  //write to output file
				outfile << endl;                                        //the pre-order traversal
				cout << endl;                                           //of the tree

				break;
			case 2:
				cout << "Enter number to add to tree" << endl;      //get a number to be inserted
				cin >> number;                                      //in tree
				mytree.insert(number);                              //insert the number in the tree
				cout << "Updated tree after insertion of " << number << ": ";
				outfile << "Updated tree after insertion of " << number << ": ";
				mytree.printpreorder();                                  //print out updated tree
				mytree.writetofilepreorder(outfile, mytree.getroot());   //after insertion
				outfile << endl;
				break;
			case 3:
				cout << "Enter a number to be deleted from tree" << endl;
				cin >> number;                                         //get a number to be deleted
				mytree.deletekey(number);                              //from tree and delete it
				cout << "Updated tree after deletion of " << number << ": ";
				outfile << "Updated tree after deletion of " << number << ": ";
				mytree.printpreorder();
				mytree.writetofilepreorder(outfile, mytree.getroot());  //print out the new tree
				outfile << endl;                                        //in pre-order traversal
				break;
			case 4:
				cout << "Enter a number to search for in tree" << endl;
				cin >> number;                                            //get a number to search
				cout << "Search: ";                                       //for in tree
				outfile << "Search: ";
				mytree.search(outfile, number);                           //if it finds the node
		 		break;                                                    //in the tree then print height
			case 5:
				do{
					cout << "what type of traversal:" << endl;
					cout << "1. Pre_order" << endl;
					cout << "2. Post_order" << endl;
					cout << "3. In_order" << endl;
					cin >> option2;

					while(cin.fail())                                       //make sure the user
					{                                                       //enters an integer
						cout << "You must enter an integer value" << endl;
						cin.clear();
						cin.ignore(256, '\n');
						cin >> option2;
					}

					//choose which way to print out the tree
					switch(option2)
					{
						case 1:
							cout << "Pre-order: ";
							outfile << "Pre-order: ";
							mytree.printpreorder();
							mytree.writetofilepreorder(outfile, mytree.getroot());
							cout << endl;
							outfile << endl;
							break;
						case 2:
							cout << "Post-order: ";
							outfile << "Post-order: ";
							mytree.printpostorder();
							mytree.writetofilepostorder(outfile, mytree.getroot());
							cout << endl;
							outfile << endl;
							break;
						case 3:
							cout << "In-order: ";
							outfile << "In-order: ";
							mytree.printinorder();
							mytree.writetofileinorder(outfile, mytree.getroot());
							cout << endl;
							outfile << endl;
							break;
						default:
							cout << "Not a valid option, try again" << endl;
							break;
					}

				}while(option2 != 1 && option2 != 2 && option2 != 3);
				break;
			case 6:
				mytree.deletetree(mytree.getroot());                //delete the entire tree
				cout << "Delete Tree: Tree deleted" << endl;        //and print out a message
				outfile << "Delete Tree: Tree deleted"<< endl;      //that tree was deleted
				break;
			case 7:
				if(mytree.getroot() == NULL)                        //get the root and check the
				{                                                   //balance of it
					cout << "Check Balance: ";                      //the bf = rh - lh
					outfile << "Check Balance: ";
					cout << "The tree is empty" << endl;
					outfile << "The tree is empty" << endl;         //if the root is NULL the tree
				}                                                   //is empty
				else
				{
					cout << "Check Balance: ";                      //print out balance of tree
					outfile << "Check Balance: ";
					cout << mytree.checkbalance(mytree.getroot()) << endl;
					outfile << mytree.checkbalance(mytree.getroot()) << endl;
				}
				break;
			case 8:
				outfile.close();                                    //close output file before exit
				exit(1);                                            //option to be able to exit
				break;                                              //program
			default:
				cout << "Not a valid option try again";             //user did not enter a valid
				break;                                              //option
		}
	}

	return 0;
}
