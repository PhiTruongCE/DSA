#include <iostream>
#include <fstream>
#include <math.h>
#include <queue>
#include <string>

using namespace std;

enum BalanceValue
{
	LH = -1,
	EH = 0,
	RH = 1
};
void printNSpace(int n)
{
	for (int i = 0; i < n - 1; i++)
		cout << " ";
}
void printInteger(int &n)
{
	cout << n << " ";
}

class Node
{
public:
	int data;
	Node *left;
	Node *right;
	BalanceValue balance;
	Node(const int &val)
	{
		data = val;
		left = right = NULL;
		balance = EH;
	}
	int getBalance(){return this->balance;}
};

class AVL
{
private:
	Node *root;
protected:
	Node *rotateRight(Node *&node);
	Node *rotateLeft(Node *&node);
	Node *leftBalance(Node *&node, bool &taller);
	Node *rightBalance(Node *&node, bool &taller);
	Node *removeLeftBalance(Node *&node, bool &shorter);
	Node *removeRightBalance(Node *&node, bool &shorter);
	//TODO Methods
	Node *insertRec(Node *&node, const int &value, bool &taller);
	Node *removeRec(Node *&node, const int &value, bool &shorter, bool &success);
public:
	AVL()
	{
		this->root = NULL;
	}
	
	
	// TODO Methods
	void insert(const int &value);
	void remove(const int &value);
	Node* getRoot(){return this->root;}
	void printInorder(Node* node);
	void printPreorder(Node* node);
};

void AVL::printInorder(Node* node){
	if (node == nullptr)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}

void AVL::printPreorder(Node* node){
	if (node == nullptr)
        return;
 
    /* first print data of node */
    cout << node->data << " ";
 
    /* then recur on left sutree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}

Node* AVL::rotateRight(Node *&node)
{
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}

Node*AVL::rotateLeft(Node *&node)
{
	Node* temp = node->right;
	node->right = temp->left;	
	temp->left = node;
	return temp;
}

Node* AVL::insertRec(Node* &node, const int &value, bool &taller)
{
	if (node == NULL)
	{
		node = new Node(value);
		taller = true;
		return node;
	}
	if (value < node->data)
	{
		node->left = insertRec(node->left, value, taller);
		if (taller)
		{
			if (node->balance == LH)
			{
				node = leftBalance(node,taller);
				//taller = false;
			}
			else if (node->balance == EH)
				node->balance = LH;
			else
			{
				node->balance = EH;
				taller = false;
			}
		}
	}
	else
	{
		node->right = insertRec(node->right, value, taller);
		if (taller)
		{
			if (node->balance == LH)
			{
				node->balance = EH;
				taller = false;
			}
			else if (node->balance == EH)
				node->balance = RH;
			else
			{
				node = rightBalance(node,taller);
				//taller = false;
			}
		}
	}
	return node;
}

void AVL::insert(const int &value)
{
	bool taller = false;
	this->root = this->insertRec(root, value, taller);
}

Node* AVL::rightBalance(Node *&node, bool &taller)
{
	Node* rightTree = node->right;
	if (rightTree->balance == RH) {
		node = rotateLeft(node);
		node->balance = EH;
		rightTree->balance = EH;
		node->left->balance = EH;
		taller = false;
	}
	else {
		Node* leftTree = rightTree->left;
		if (leftTree->balance == RH) {
			node->balance = LH;
			rightTree->balance = EH;
		}
		else if (leftTree->balance == EH) {
			node->balance = EH;
			rightTree->balance = EH;
		}
		else {
			node->balance = EH;
			rightTree->balance = RH;
		}
		leftTree->balance = EH;
		node->right = rotateRight(rightTree);
		node = rotateLeft(node);
		taller = false;
	}
	return node;
}

Node* AVL::leftBalance(Node *&node, bool &taller)
{
	Node* leftTree = node->left;
	if (leftTree->balance == LH) {
		node = rotateRight(node);
		node->balance = EH;
		leftTree->balance = EH;
		node->right->balance = EH;
		taller = false;
	}
	else {
		Node* rightTree = leftTree->right;
		if (rightTree != NULL) {
			if (rightTree->balance == LH) {
				node->balance = RH;
				leftTree->balance = EH;
			}
			else if (rightTree->balance == EH) {
				leftTree->balance = EH;
				node->balance = EH;
			}
			else {
				node->balance = LH;
				leftTree->balance = LH;
			}
			rightTree->balance = EH;
			node->left = rotateLeft(leftTree);
			node = rotateRight(node);
			taller = false;
		}
	}
	return node;
}

Node* AVL::removeRec(Node *&node, const int &value, bool &shorter, bool &success)
{
	if (node == NULL) {
		shorter = false;
		success = false;
		return NULL;
	}
	if (value < node->data) {
		node->left = removeRec(node->left, value, shorter, success);
		if (shorter) {
			node = removeRightBalance(node, shorter);
		}
	}
	else if (value > node->data) {
		node->right = removeRec(node->right, value, shorter, success);
		if (shorter) {
			node = removeLeftBalance(node, shorter);
		}
	}
	else {
		Node* deleteNode = node;
		if (node->right == NULL) {
			Node* newNode = node->left;
			success = true;
			shorter = true;
			delete deleteNode;
			return newNode;
		}
		else if (node->left == NULL) {
			Node* newNode = node->right;
			success = true;
			shorter = true;
			delete deleteNode;
			return newNode;
		}
		else {
			Node* exchPtr = node->left;
			while (exchPtr->right != NULL) {
				exchPtr = exchPtr->right;
			}
			node->data = exchPtr->data;
			node->left = removeRec(node->left, exchPtr->data, shorter, success);
			if (shorter) {
				node = removeRightBalance(node, shorter);
			}
		}
	}
	return node;
}

void AVL::remove(const int &value)
{
	bool shorter = false;
	bool success = false;
	this->root = removeRec(this->root, value, shorter,success);
}

Node* AVL::removeRightBalance(Node *&node, bool &shorter)
{
		if (node->balance == LH) {
			node->balance = EH;
		}
		else if (node->balance == EH) {
			node->balance = RH;
			shorter = false;
		}
		else {
			Node* rightTree = node->right;
			if (rightTree->balance == LH) {
				Node* leftTree = rightTree->left;
				if (leftTree->balance == LH) {
					rightTree->balance = RH;
					node->balance = EH;
				}
				else if (leftTree->balance == EH) {
					node->balance = LH;
					rightTree->balance = EH;
				}
				else {
					node->balance = LH;
					rightTree->balance = EH;
				}
				leftTree->balance = EH;
				node->right = rotateRight(rightTree);
				node->right = rotateRight(rightTree);
				node = rotateLeft(node);
			}
			else {
				if (rightTree->balance != EH) {
					node->balance = EH;
					rightTree->balance = EH;
				}
				else {
					node->balance = RH;
					rightTree->balance = LH;
					shorter = false;
				}
				node = rotateLeft(node);
			}
		}
		return node;
}

Node *AVL::removeLeftBalance(Node* &node, bool &shorter)
{
	if (node->balance == RH) {
		node->balance = EH;
	}
	else if (node->balance == EH) {
		node->balance = LH;
		shorter = false;
	}
	else {
		Node* leftTree = node->left;
		if (leftTree->balance == RH) {
			Node* rightTree = leftTree->right;
			if (rightTree->balance == RH) {
				leftTree->balance = LH;
				node->balance = EH;
			}
			else if (rightTree->balance == EH) {
				node->balance = EH;
				leftTree->balance = EH;
			}
			else {
				node->balance = RH;
				leftTree->balance = EH;
			}
			rightTree->balance = EH;
			node->left = rotateLeft(leftTree);
			node = rotateRight(node);
		}
		else {
			if (leftTree->balance != EH) {
				node->balance = EH;
				leftTree->balance = EH;
			}
			else {
				node->balance = LH;
				leftTree->balance = RH;
				shorter = false;
			}
			node = rotateRight(node);
		}
	}
	return node;
}

int main(){


	AVL vl;
	Node* root;
	vl.insert(0);
	vl.insert(1);
	vl.insert(3);
	vl.insert(11);
	vl.insert(9);
	vl.insert(2);
	vl.insert(4);
	vl.insert(10);
	vl.insert(5);
	vl.insert(7);
	vl.insert(8);
	vl.insert(6);
	root = vl.getRoot();
	vl.printInorder(root);
	cout<<endl;
	vl.printPreorder(root);
	

	// cout << "root: " << root->data << endl;
	// cout << "root balance: " << root->balance << endl;
	// cout << "left: " << root->left->data << endl;
	// cout << "left balance: " << root->left->balance << endl;
	// cout << "right: " << root->right->data << endl;
	// cout << "right balance: " << root->right->balance << endl;
	// cout << "right->right: " << root->right->right->data << endl;
	// cout << "right->right balance: " << root->right->right->balance << endl;
	// cout << "right->left: " << root->right->left->data << endl;
	// cout << "right->left balance: " << root->right->left->balance << endl;
	// cout << "right->left-left: " << root->right->left->left->data << endl;
	// cout << "right->left-left balance: " << root->right->left->left->balance << endl;
	// cout << "right->left-right: " << root->right->left->right->data << endl;
	// cout << "right->left-right balance: " << root->right->left->right->balance << endl;
	// cout << "right->right-left: " << root->right->right->left->data << endl;
	// cout << "right->right->left balance: " << root->right->right->left	->balance << endl;
	// cout << "left->left: " << root->left->left->data << endl;
	// cout << "left->left balance: " << root->left->left->balance << endl;
	// cout << "left->right: " << root->left->right->data << endl;
	// cout << "left->right balance: " << root->left->right->balance << endl;
	// cout << "left->right->right: " << root->left->right->right->data << endl;
	// cout << "left->right-right balance: " << root->left->right->right->balance << endl;
    return 0;
}