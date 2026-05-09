#include <iostream>

using namespace std;


struct Node {
    Book book;
    Node* left;
    Node* right;
};

struct Book {
    int id;
    string title;
    string author;
};

class LibraryBST {};

class LibraryAVL {};

int main()
{
    cout << "Hello World!\n";
}
