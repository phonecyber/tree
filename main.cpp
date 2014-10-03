#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "tree.h"
using namespace std;

void main()
{
	Tree<int> mytree, balancedTree, afterDelTree;
	int randNum, size, del;

	cout << "How many insertion operations: ";
	cin >> size;

	cout << "\nBST Insertion:\n\t";

	mytree.data = new int[size];

	srand((unsigned)time(0));
	for (int i = 1; i <= size; i++)
	{
		randNum = (rand() % 100) + 1;
		mytree.insert(randNum);
		cout << randNum << " ";
	}
	cout << "\n\tHeight: " << mytree.height << endl;
	mytree.inorder();
	mytree.clear();
	for (int i = 0; i < size; i++)
	{
		mytree.insert(mytree.data[i]);
		//cout << mytree.data[i] << " ";
	}
	//cout << "\n\n\t"; mytree.print();
	cout << "\nBalanced Tree:\n\t";
	balancedTree.balance(mytree.data, 0, size - 1);
	balancedTree.print();
	cout << "\n\tHeight: " << balancedTree.height;
	cout << endl;

	cout << "\nHow many deletion operations: ";
	cin >> del;

	Node<int> *delNode;
	for (int i = 1; i <= del; i++)
	{
		randNum = (rand() % 100) + 1;
		delNode = balancedTree.search(randNum);
		/*if (delNode == NULL) {
			cout << "None" << endl;
		}*/
		balancedTree.deleteNode(delNode);
		cout << "\tRandomly Delete #" << i << ": " << randNum << endl;
	}
	cout << "BEFORE:\t"; mytree.print();
	cout << "\nAFTER:\t"; balancedTree.print();

	///////////////////////////////////////////////////////////////
	/*balancedTree.data = new int[size - del];
	balancedTree.inorder();
	afterDelTree.balance(balancedTree.data, 0, size - del);
	cout << "\n\tHeight: " << afterDelTree.height;*/

	/*mytree.data = new int[size-1];
	mytree.inorder();*/

	/*mytree.data = new int[size-1];
	mytree.inorder();
	mytree.clear();
	for (int i = 0; i < size-1; i++)
	{
		mytree.insert(mytree.data[i]);
		//cout << mytree.data[i] << " ";
	}
	//mytree.print();
	/*cout << "\nBalanced Tree:\n\t";
	balancedTree.balance(mytree.data, 0, size - 1);
	balancedTree.print();
	cout << "\n\tHeight: " << balancedTree.height;
	cout << endl;*/

	//Node<int> *z = mytree.search(20);
	//Node<int> **zz = &z;
	//balancedTree.deleteNode(balancedTree.search(del));
	cout << endl;
	//balancedTree.print();

	cout << endl;
}