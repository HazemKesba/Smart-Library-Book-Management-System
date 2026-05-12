#include "LibraryBST.h"
#include <string>

LibraryBST::LibraryBST() {
	cout << "LibraryBST constructor called" << endl;
}

LibraryBST::~LibraryBST() {
	clear(root);
	root = nullptr;
}

Node* LibraryBST::getRoot() {
	return root;
}

void LibraryBST::insertBook(Book book) {
	root = insertBook(book, root);
}

Node* LibraryBST::insertBook(Book book, Node* node) {
	if (root == nullptr) {
		root = new Node();
		root->book = book;
		return root;
	}
	else if (node == nullptr) {
		node = new Node();
		node->book = book;
		return node;
	}
	else if (book.id > node->book.id) {
		node->right = insertBook(book, node->right);
	}
	else if (book.id < node->book.id) {
		node->left = insertBook(book, node->left);
	}
	return node;
}

Node* LibraryBST::searchBook(int id, Node* node) {
	if (node == nullptr) return nullptr;
	else if (id == node->book.id) return node;
	else if (id > node->book.id) return searchBook(id, node->right);
	else if (id < node->book.id) return searchBook(id, node->left);
	return node;
}

int LibraryBST::closestID(int target, int& closest, Node* node) {
	if (node == nullptr) return -1;

	if (abs(node->book.id - target) < abs(closest - target))
		closest = node->book.id;

	if (target < node->book.id) {
		if (node->left != nullptr) return closestID(target, closest, node->left);
	}
	else if (target > node->book.id) {
		if (node->right != nullptr) return closestID(target, closest, node->right);
	}

	return closest;
}

Node* LibraryBST::getPredecessor(Node* node) {
	Node* current = node->left;
	while (current->right != nullptr) {
		current = current->right;
	}
	return current;
}

Node* LibraryBST::deleteBook(int id, Node* node) {
	if (node == nullptr) return nullptr;
	else if (node->book.id == id) {
		// No children
		if (node->right == nullptr && node->left == nullptr) {
			delete node;
			return nullptr;
		}

		// One left child
		else if (node->right == nullptr && node->left != nullptr) {
			Node* temp = node->left;
			delete node;
			return temp;
		}

		// One right child
		else if (node->right != nullptr && node->left == nullptr) {
			Node* temp = node->right;
			delete node;
			return temp;
		}

		// Two children
		else if (node->right != nullptr && node->left != nullptr) {
			Node* pred = getPredecessor(node);
			node->book = pred->book;
			node->left = deleteBook(pred->book.id, node->left);
		}
	}
	else {
		if (id > node->book.id) node->right = deleteBook(id, node->right);
		else if (id < node->book.id) node->left = deleteBook(id, node->left);
	}
	return node;
}

void LibraryBST::inorder(Node* node) {
	if (node != nullptr) {
		inorder(node->left);
		cout << "ID: " << node->book.id << ", Author: " << node->book.author << ", Title: " << node->book.title << endl;
		inorder(node->right);
	}
}

void LibraryBST::inrange(int minId, int maxId, Node* node) {
	if (node != nullptr) {
		inrange(minId, maxId, node->left);
		if (node->book.id > minId && node->book.id < maxId) {
			cout << "ID: " << node->book.id << ", Author: " << node->book.author << ", Title: " << node->book.title << endl;
		}
		inrange(minId, maxId, node->right);
	}
}

void LibraryBST::clear(Node* node) {
	if (node == nullptr) return;

	clear(node->left);
	clear(node->right);
	delete node;
}


int LibraryBST::treeHeight(Node* node)
{
	if (node == nullptr)
		return 0;

	int leftH = treeHeight(node->left);
	int rightH = treeHeight(node->right);

	return 1 + max(leftH, rightH);
}

int LibraryBST::treeHeight()
{
	return treeHeight(root);
}