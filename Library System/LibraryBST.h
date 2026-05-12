#pragma once
#include <iostream>
#include <vector>
#include "models.h"

using namespace std;

class LibraryBST {
private:
	Node* root = nullptr;
public:
    LibraryBST();
    ~LibraryBST();
	Node* getRoot();
	void insertBook(Book book);
	Node* insertBook(Book book, Node* node);
	Node* searchBook(int id, Node* node);
	int closestID(int target, int& closest, Node* node);
	Node* getPredecessor(Node* node);
	Node* deleteBook(int id, Node* node);
	void inorder(Node* node);
	void inrange(int minId, int maxId, Node* node);
	void clear(Node* root);
	int treeHeight(Node* node);
	int treeHeight();
};