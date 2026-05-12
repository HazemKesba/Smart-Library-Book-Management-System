#pragma once
#include <iostream>

using namespace std;

struct Book {
	int id;
	string title;
	string author;

	Book() {}
	Book(int i, string t, string a) :id(i), title(t), author(a) {}
};

struct Node {
	Book book;
	Node* left = nullptr;
	Node* right = nullptr;
	int height = 1;
};