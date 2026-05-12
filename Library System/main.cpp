#include <iostream>
#include "LibraryAVL.h"
#include "LibraryBST.h"


using namespace std;


int main()
{
	//LibraryAVL* libraryAVL = new LibraryAVL();
	LibraryBST* libraryBST = new LibraryBST();

	Book book1 = Book(100, "Hello boy", "Mike Max");
	libraryBST->insertBook(book1);

	Book book2 = Book(103, "Can not see light", "Sam Samuel");
	libraryBST->insertBook(book2, libraryBST->getRoot());

	Book book3 = Book(90, "Black George", "Mark Rim");
	libraryBST->insertBook(book3, libraryBST->getRoot());

	//libraryBST->deleteBook(book1.id, libraryBST->getRoot());
	//cout << "Author of ID 105: " << libraryBST->searchBook(103, libraryBST->getRoot(), true)->book.author << endl;
	//libraryBST->inorder(libraryBST->getRoot());
	libraryBST->inrange(80, 102, libraryBST->getRoot());


	//delete libraryAVL;
	delete libraryBST;
	return 0;
}
