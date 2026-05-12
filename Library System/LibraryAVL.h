#pragma once
#include <iostream>
#include <cmath>
#include "models.h"

using namespace std;

class LibraryAVL {
public:
	LibraryAVL();
	~LibraryAVL();

	void insert(Book book);
	void remove(int id);
	bool search(int id);

	void inorderTraversal();
	int treeHeight();

	void rangeSearch(int low, int high);
	int closestID(int target);

private:
	Node* root;

	void clear(Node*& node);

	int height(Node* node);
	int max(int x, int y);
	int balanceFactor(Node* node);

	Node* rightRotate(Node* y);
	Node* leftRotate(Node* x);

	Node* insertAVL(Node* node, Book book);
	Node* deleteAVL(Node* node, int id);

	Node* minValueNode(Node* node);

	bool searchRec(Node* node, int id);

	void inorder(Node* node);

	void rangeSearchPriv(Node* node, int low, int high);
	void closestIDPriv(Node* node, int target, int& closest);
};  