#include "LibraryBST.h"

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

Node* LibraryBST::searchBook(int id, Node* node, bool mustEqual) {
	if (id == node->book.id) return node;
	else if (id > node->book.id) {
		if (node->right == nullptr && !mustEqual) {
			return node;
		}
		searchBook(id, node->right);
	}
	else if (id < node->book.id) {
		if (node->left == nullptr && !mustEqual) { 
			return node;
		}
		searchBook(id, node->left);
	}
}

Node* LibraryBST::getPredecessor(int id, Node* result) {
	if (result == nullptr) {
		Node* target = searchBook(id, getRoot(), true);
		if (target->left != nullptr) result = getPredecessor(id, target->left);
		else return nullptr;
	}
	else {
		if (result->right != nullptr) result = getPredecessor(id, result->right);
		else return result;
	}
	return result;
}

Node* LibraryBST::getParent(int id, Node* node) {
	if (node->right->book.id == id || node->left->book.id == id) return node;
	else if (id > node->book.id) getParent(id, node->right);
	else if (id < node->book.id) getParent(id, node->left);
	return node;
}

void LibraryBST::deleteBook(int id, Node* node) {
	if (node->book.id == id) {
		// No children
		if (node->right == nullptr && node->left == nullptr) {
			Node* parent = getParent(node->book.id, getRoot());
			if (node->book.id > parent->book.id) parent->right = nullptr;
			else parent->left = nullptr;
			delete node;
		}

		// One left child
		else if (node->right == nullptr && node->left != nullptr) {
			Node* parent = getParent(node->book.id, getRoot());
			if (node->book.id > parent->book.id) parent->right = node->left;
			else parent->left = node->left;
			delete node;
		}

		// One right child
		else if (node->right != nullptr && node->left == nullptr) {
			Node* parent = getParent(node->book.id, getRoot());
			if (node->book.id > parent->book.id) parent->right = node->right;
			else parent->left = node->right;
			delete node;
		}

		// Two children
		else if (node->right != nullptr && node->left != nullptr) {
			Node* pred = getPredecessor(id);
			Node* predParent = getParent(pred->book.id, getRoot());
			node->book = pred->book;
			deleteBook(pred->book.id, node->left);
		}
		return;
	}
	else {
		if (id > node->book.id) deleteBook(id, node->right);
		else if (id < node->book.id) deleteBook(id, node->left);
	}
	return;
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