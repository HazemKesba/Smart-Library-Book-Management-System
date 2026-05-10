#pragma once
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

class LibraryAVL {
public:
    LibraryAVL();
    ~LibraryAVL();
};  