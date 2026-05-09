#include <iostream>

using namespace std;


struct Book {
    int id;
    string title;
    string author;
};

struct Node {
    Book book;
    Node* left;
    Node* right;
};

class LibraryBST {};

class LibraryAVL {};

int main()
{
    cout << "Hello World!\n";
}
