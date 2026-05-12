#include <iostream>
#include "LibraryAVL.h"
#include "LibraryBST.h"

using namespace std;

int main()
{
	// ================= BST TEST =================
	cout << "========== BST TEST ==========\n";

	LibraryBST* libraryBST = new LibraryBST();

	Book book1 = {100, "Hello boy", "Mike Max"};
	libraryBST->insertBook(book1);

	Book book2 = {103, "Can not see light", "Sam Samuel"};
	libraryBST->insertBook(book2, libraryBST->getRoot());

	Book book3 = {90, "Black George", "Mark Rim"};
	libraryBST->insertBook(book3, libraryBST->getRoot());

	cout << "Books in range 80 -> 102:\n";
	libraryBST->inrange(80, 102, libraryBST->getRoot());

	delete libraryBST;


	// ================= AVL TEST =================
	cout << "\n\n========== AVL TEST ==========\n";

	LibraryAVL* libraryAVL = new LibraryAVL();

	Book a1 = {30, "C++", "Bjarne"};
	Book a2 = {20, "Algorithms", "CLRS"};
	Book a3 = {40, "Python", "Guido"};
	Book a4 = {10, "Java", "James"};
	Book a5 = {25, "OS", "Tanenbaum"};
	Book a6 = {50, "DB", "Elmasri"};
	Book a7 = {5, "Networks", "Kurose"};

	libraryAVL->insert(a1);
	libraryAVL->insert(a2);
	libraryAVL->insert(a3);
	libraryAVL->insert(a4);
	libraryAVL->insert(a5);
	libraryAVL->insert(a6);
	libraryAVL->insert(a7);

	cout << "\nInorder Traversal:\n";
	libraryAVL->inorderTraversal();

	cout << "\nTree Height: " << libraryAVL->treeHeight() << endl;

	cout << "\nSearch 25:\n";
	if (libraryAVL->search(25))
		cout << "Found\n";
	else
		cout << "Not Found\n";

	cout << "\nRange Search 15 -> 35:\n";
	libraryAVL->rangeSearch(15, 35);

	cout << "\nClosest ID to 27: ";
	cout << libraryAVL->closestID(27) << endl;

	cout << "\nDelete ID 20\n";
	libraryAVL->remove(20);

	cout << "\nAfter Delete:\n";
	libraryAVL->inorderTraversal();

	delete libraryAVL;

	return 0;
}
