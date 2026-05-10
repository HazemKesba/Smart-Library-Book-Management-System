#include <iostream>
#include "LibraryAVL.h"
#include "LibraryBST.h"


using namespace std;


int main()
{
	LibraryAVL* libraryAVL = new LibraryAVL();
	LibraryBST* libraryBST = new LibraryBST();

	delete libraryAVL;
	delete libraryBST;
	return 0;
}
