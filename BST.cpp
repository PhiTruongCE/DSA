#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(const int& data) { this->data = data; }
};
class BinarySearchTree {
private:
        Node* root;
    
protected:
        bool addRec(Node *&, const int &);
        bool removeRec(Node *&, const int &);
public:
	BinarySearchTree()
	{
		this->root = NULL;
	}

        bool add(const int &value);
        bool remove(const int &value);
};

bool BinarySearchTree::addRec(Node *&node, const int &value)
{
	if(node == NULL){
        node = new Node(value);
        return true;
    }
    if(value < node->data){
        return addRec(node->left,value);
    }
    else if(value > node->data){
        return addRec(node->right, value);
    }
    else return false;
}

bool BinarySearchTree::add(const int &value)
{
	return addRec(root,value);
}

bool BinarySearchTree::removeRec(Node *&node, const int &value)
{
    
}


bool BinarySearchTree::remove(const int &value)
{

}

int main(){

}