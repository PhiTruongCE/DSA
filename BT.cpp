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
class BinaryTree {
private:
        Node* root;
    
protected:
        int getHeightRec(Node *);
        int countTwoChildrenNodesRec(Node *);
        Node* maxNodeRec(Node*&);
        void printLNRRec(Node *);
        bool isBSTRec(Node *);
        void levelOrderTraverse();
public:
	BinaryTree()
	{
		this->root = NULL;
	}

        int getHeight();
        int countTwoChildrenNodes();
        Node* maxNode();
        void printLNR();
        bool isBST();
};

int BinaryTree::getHeightRec(Node *node)
{
	if(node == NULL) return 0;
    int lh = getHeightRec(node->left);
    int rh = getHeightRec(node->right);
    return (lh > rh ? lh : rh) + 1;
}

int BinaryTree::getHeight()
{
	return getHeightRec(root);
}

int BinaryTree::countTwoChildrenNodesRec(Node *node)
{
    if(node == NULL) return 0;
    if(node->left != NULL && node->right != NULL){
        return 1 + countTwoChildrenNodesRec(node->left) + countTwoChildrenNodesRec(node->right);
    }
    return countTwoChildrenNodesRec(node->left) + countTwoChildrenNodesRec(node->right);
}


int BinaryTree::countTwoChildrenNodes()
{
    return countTwoChildrenNodesRec(root);
}

Node* BinaryTree::maxNodeRec(Node *&node)
{
    if(node == NULL) return NULL;
    Node *maxNode = node;
    Node *leftMaxNode = maxNodeRec(node->left);
    if(leftMaxNode != NULL){
        if(maxNode->data < leftMaxNode->data){
            maxNode = leftMaxNode;
        }
    }
    Node *rightMaxNode = maxNodeRec(node->right);
    if(rightMaxNode != NULL){
        if(maxNode->data < rightMaxNode->data){
            maxNode = rightMaxNode;
        }
    }
    return maxNode;
}


Node* BinaryTree::maxNode()
{
    return maxNodeRec(root);   
}

void BinaryTree::printLNRRec(Node *node){
    if (node == NULL) return;
    printLNRRec(node->left);
    cout<<node->data<<" ";
    printLNRRec(node->right);
}

void BinaryTree::printLNR(){
    printLNRRec(root);
}

bool BinaryTree::isBSTRec(Node *node){
    if(node == NULL) return true;
    if(node->left != NULL && node->right != NULL){
        if (node->data > node->left->data && node->data < node->right->data){
            return true && isBSTRec(node->left) && isBSTRec(node->right);
        }
        else return false;
    }
    else if(node->left == NULL && node->right != NULL){
        if(node->data < node->right->data){
            return true && isBSTRec(node->right);
        }
        else return false;
    }
    else if(node->left != NULL && node->right == NULL){
        if(node->data > node->left->data){
            return true && isBSTRec(node->left);
        }
        else return false;
    }
    else return true;
}

void BinaryTree::levelOrderTraverse()
{
    if(root == NULL) return;
    else{
        cout<<root->data;
        
    }
}

int main(){

}