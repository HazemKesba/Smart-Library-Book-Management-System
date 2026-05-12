#include "LibraryAVL.h"

LibraryAVL::LibraryAVL() {
	root = nullptr;
}

LibraryAVL::~LibraryAVL() {
	clear(root);
}
// clear tree
void LibraryAVL::clear(Node*& node) {
	if (node == nullptr) return;

	clear(node->left);
	clear(node->right);

	delete node;
	node = nullptr;
}

// height
int LibraryAVL::height(Node* node) {
	if (node == nullptr) return 0;
	return node->height;
}

// max
int LibraryAVL::max(int x, int y) {
	if (x >= y) return x;
	return y;
}

// balance factor
int LibraryAVL::balanceFactor(Node* node) {
	if (node == nullptr) return 0;
	return height(node->left) - height(node->right);
}

// right rotation
Node* LibraryAVL::rightRotate(Node* y) {
	Node* x = y->left;
	Node* temp = x->right;

	x->right = y;
	y->left = temp;

	y->height = 1 + max(height(y->left), height(y->right));
	x->height = 1 + max(height(x->left), height(x->right));

	return x;
}

// left rotation
Node* LibraryAVL::leftRotate(Node* x) {
	Node* y = x->right;
	Node* temp = y->left;

	y->left = x;
	x->right = temp;

	x->height = 1 + max(height(x->left), height(x->right));
	y->height = 1 + max(height(y->left), height(y->right));

	return y;
}

// insert public
void LibraryAVL::insert(Book book) {
	root = insertAVL(root, book);
}

// insert private
Node* LibraryAVL::insertAVL(Node* node, Book book) {
	if (node == nullptr) {
		Node* newNode = new Node;
		newNode->book = book;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->height = 1;
		return newNode;
	}

	if (book.id < node->book.id)
		node->left = insertAVL(node->left, book);
	else if (book.id > node->book.id)
		node->right = insertAVL(node->right, book);
	else
		return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = balanceFactor(node);

	// LL
	if (balance > 1 && book.id < node->left->book.id)
		return rightRotate(node);

	// RR
	if (balance < -1 && book.id > node->right->book.id)
		return leftRotate(node);

	// LR
	if (balance > 1 && book.id > node->left->book.id) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// RL
	if (balance < -1 && book.id < node->right->book.id) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

// search public
bool LibraryAVL::search(int id) {
	return searchRec(root, id);
}

// search private
bool LibraryAVL::searchRec(Node* node, int id) {
	if (node == nullptr) return false;

	if (node->book.id == id) return true;

	if (id < node->book.id)
		return searchRec(node->left, id);

	return searchRec(node->right, id);
}

// inorder public
void LibraryAVL::inorderTraversal() {
	inorder(root);
}

// inorder private
void LibraryAVL::inorder(Node* node) {
	if (node == nullptr) return;

	inorder(node->left);

	cout << "ID: " << node->book.id
		<< " | Title: " << node->book.title
		<< " | Author: " << node->book.author << endl;

	inorder(node->right);
}

// tree height
int LibraryAVL::treeHeight() {
	return height(root);
}

// min value node
Node* LibraryAVL::minValueNode(Node* node) {
	Node* current = node;

	while (current != nullptr && current->left != nullptr) {
		current = current->left;
	}

	return current;
}

// remove public
void LibraryAVL::remove(int id) {
	root = deleteAVL(root, id);
}

// delete private
Node* LibraryAVL::deleteAVL(Node* node, int id) {
	if (node == nullptr) return node;

	if (id < node->book.id)
		node->left = deleteAVL(node->left, id);

	else if (id > node->book.id)
		node->right = deleteAVL(node->right, id);

	else {
		// no child or one child
		if (node->left == nullptr || node->right == nullptr) {
			Node* temp = node->left ? node->left : node->right;

			if (temp == nullptr) {
				temp = node;
				node = nullptr;
			}
			else {
				*node = *temp;
			}

			delete temp;
		}
		else {
			// two children
			Node* temp = minValueNode(node->right);

			node->book = temp->book;
			node->right = deleteAVL(node->right, temp->book.id);
		}
	}

	if (node == nullptr) return node;

	node->height = 1 + max(height(node->left), height(node->right));

	int balance = balanceFactor(node);

	// LL
	if (balance > 1 && balanceFactor(node->left) >= 0)
		return rightRotate(node);

	// LR
	if (balance > 1 && balanceFactor(node->left) < 0) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// RR
	if (balance < -1 && balanceFactor(node->right) <= 0)
		return leftRotate(node);

	// RL
	if (balance < -1 && balanceFactor(node->right) > 0) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

// range search public
void LibraryAVL::rangeSearch(int low, int high) {
	rangeSearchPriv(root, low, high);
}

// range search private
void LibraryAVL::rangeSearchPriv(Node* node, int low, int high) {
	if (node == nullptr) return;

	if (low < node->book.id)
		rangeSearchPriv(node->left, low, high);

	if (node->book.id >= low && node->book.id <= high) {
		cout << node->book.id << " - " << node->book.title << endl;
	}

	if (high > node->book.id)
		rangeSearchPriv(node->right, low, high);
}

// closest id public
int LibraryAVL::closestID(int target) {
	if (root == nullptr) return -1;

	int closest = root->book.id;
	closestIDPriv(root, target, closest);
	return closest;
}

// closest id private
void LibraryAVL::closestIDPriv(Node* node, int target, int& closest) {
	if (node == nullptr) return;

	if (abs(node->book.id - target) < abs(closest - target))
		closest = node->book.id;

	if (target < node->book.id)
		closestIDPriv(node->left, target, closest);

	else if (target > node->book.id)
		closestIDPriv(node->right, target, closest);
}