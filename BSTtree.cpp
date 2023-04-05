// BSTtree.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

void Insert(Node*& root, int data);
void Search(Node*& root, int data);

int main(){
	Node* root = NULL;
	Insert(root, 15);
	Insert(root, 10);
	Insert(root, 20);
	Insert(root, 8);
	Insert(root, 17);
	Insert(root, 25);

	cout << "Number to search in BST: " << endl;
	int data; cin >> data;
	Search(root, data);

	return 0;
}

void Insert(Node*& root, int data) {
	Node* temp = new Node(data);
	if (root == NULL)
		root = temp;
	else if (data <= root->data)
		Insert(root->left, data);
	else
		Insert(root->right, data);
}

void Search(Node*& root, int data) {
	if (root == NULL)
		cout << data << " not found!" << endl;
	else if (root->data == data)
		cout << "Found " << data << "!" << endl;
	else if (data <= root->data)
		Search(root->left, data);
	else
		Search(root->right, data);
}