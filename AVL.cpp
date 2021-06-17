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
	//TODO Methods
	Node *insertRec(Node *&node, const int &value, bool &taller);
public:
	AVL()
	{
		this->root = NULL;
	}
	
	
	// TODO Methods
	void insert(const int &value);
	void remove(const int &value);
};

Node *AVL::rotateLeft(Node *&node)
{
    Node* tmp = node->right;
    node->right=tmp->left;
    tmp->left=node;
    return tmp;
}

Node *AVL::rotateRight(Node *&node)
{
    Node* tmp = node->left;
    node->left=tmp->right;
    tmp->right=node;
    return tmp;
}

Node *AVL::leftBalance(Node *&node, bool &taller)
{
    Node *leftTree = node->left;
    if (leftTree->balance == LH)
    {
    node->balance= EH;
    leftTree->balance=EH;
    node = rotateRight(node);
    taller=false;
    }
    else 
    {
        Node* rightTree = leftTree->right;
        if (rightTree->balance == LH)
        {
            node->balance=RH;
            leftTree->balance=EH;
        }
        else if (rightTree->balance == EH)
            leftTree->balance = EH;
        else
        {
        node->balance=EH;
        leftTree->balance=LH;
        }
        rightTree->balance=EH;
        node->left=rotateLeft(leftTree);
        node=rotateRight(node);
        taller=false;
    }
    return node;
}

Node *AVL::rightBalance(Node *&node, bool &taller)
{
    Node* rightTree = node->right;
    if (rightTree->balance == RH)
    {
        node->balance = EH;
        rightTree->balance = EH;
        node = rotateLeft(node);
        taller = false;
    }
    else 
    {
        Node* leftTree = rightTree->left;
        if (leftTree->balance == LH)
        {
            node->balance = LH;
            rightTree->balance = EH;
        }
        else if (leftTree->balance == EH)
            rightTree->balance = EH;
        else
        {
            node->balance = EH;
            rightTree->balance = RH;
        }
        leftTree->balance=EH;
        node->right=rotateRight(rightTree);
        node = rotateLeft(node);
        taller = false;
    }
    return node;
}

Node *AVL::insertRec(Node *&node, const int &value, bool &taller)
{
    if (node == NULL)
    {
        node = new Node(value);
        taller = true;
        return node;
    }
    if (value < node->data)
        {
        node->left = insertRec(node->left,value,taller);
        if (taller)
            {
            if (node->balance == LH)
            {
                node = leftBalance(node,taller);
            }
            else if (node->balance == EH)
                node->balance = LH;
            else
                {
                    node->balance = EH;
                    taller=false;
                }
            }
        }
        else 
        {
        node->right = insertRec(node->right,value,taller);
        if (taller)
            {
            if (node->balance == LH)
                {
                node->balance = EH;
                taller=false;
                
                }
            else if (node->balance == EH)
                node->balance = RH;
            else {
                node = rightBalance(node,taller);
                }
            }
        }
    return node;
}

void AVL::insert(const int &value)
{
    bool taller = false;
	root = insertRec(root, value, taller);
}
