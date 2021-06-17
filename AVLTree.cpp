#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

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

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    Node* insertRec(Node* &node, const T &value, bool &taller){
	    if (node == NULL){
		    node = new Node(value);
		    taller = true;
		    return node;
	    }
	    if (value < node->data){
		    node->pLeft = insertRec(node->pLeft, value, taller);
		    if (taller){
			    if (node->balance == LH){
				    node = leftBalance(node,taller);
			    }
			    else if (node->balance == EH) node->balance = LH;
			    else{
				    node->balance = EH;
				    taller = false;
			    }
		    }
	    }
	    else{
		    node->pRight = insertRec(node->pRight, value, taller);
		    if (taller){
			    if (node->balance == LH){
				    node->balance = EH;
				    taller = false;
			    }
			    else if (node->balance == EH) node->balance = RH;
			    else{
				    node = rightBalance(node,taller);
			    }
		    }
	    }
	    return node;
    }

    void insert(const T &value){
        bool taller = false;
	    root = insertRec(root, value, taller);
    }
    Node* rotateLeft(Node *&node){
        Node* temp = node->pRight;
        node->pRight = temp->pLeft;
        temp->pLeft = node;
        return temp;
    }
    Node* rotateRight(Node *&node){
        Node* temp = node->pLeft;
        node->pLeft = temp->pRight;
        temp->pRight = node;
        return temp;
    }
    Node* leftBalance(Node *&node, bool &taller){
        Node* leftTree = node->pLeft;
        if(leftTree->balance == LH){
            node->balance = EH;
            leftTree->balance = EH;
            node = rotateRight(node);
            node->pRight->balance = EH;
            taller = false;
        }
        else{
            Node* rightTree = leftTree->pRight;
                if(rightTree->balance == LH){
                    node->balance = RH;
                    leftTree->balance = EH;
                }
                else if (rightTree->balance == EH){
                    node->balance = EH;
                    leftTree->balance = EH;
                }
                else{
                    node->balance = LH;
                    leftTree->balance = LH;
                }
                rightTree->balance = EH;
			    node->pLeft = rotateLeft(leftTree);
			    node = rotateRight(node);
			    taller = false;
        }
        return node;
    }
    Node* removeRec(Node *&node, const T &value, bool &shorter, bool &success)
{
	if (node == NULL) {
		shorter = false;
		success = false;
		return NULL;
	}
	if (value < node->data) {
		node->pLeft = removeRec(node->pLeft, value, shorter, success);
		if (shorter) {
			node = removeRightBalance(node, shorter);
		}
	}
	else if (value > node->data) {
		node->pRight = removeRec(node->pRight, value, shorter, success);
		if (shorter) {
			node = removeLeftBalance(node, shorter);
		}
	}
	else {
		Node* deleteNode = node;
		if (node->pRight == NULL) {
			Node* newNode = node->pLeft;
			success = true;
			shorter = true;
			delete deleteNode;
			return newNode;
		}
		else if (node->pLeft == NULL) {
			Node* newNode = node->pRight;
			success = true;
			shorter = true;
			delete deleteNode;
			return newNode;
		}
		else {
			Node* exchPtr = node->pLeft;
			while (exchPtr->pRight != NULL) {
				exchPtr = exchPtr->pRight;
			}
			node->data = exchPtr->data;
			node->pLeft = removeRec(node->pLeft, exchPtr->data, shorter, success);
			if (shorter) {
				node = removeRightBalance(node, shorter);
			}
		}
	}
	return node;
}
    Node* rightBalance(Node *&node, bool &taller){
	    Node* rightTree = node->pRight;
	    if (rightTree->balance == RH) {
		    node->balance = EH;
		    rightTree->balance = EH;
            node = rotateLeft(node);
		    node->pLeft->balance = EH;
		    taller = false;
	    }
	    else {
		    Node* leftTree = rightTree->pLeft;
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
		    node->pRight = rotateRight(rightTree);
		    node = rotateLeft(node);
		    taller = false;
	    }
	    return node;
    }
    Node* removeRightBalance(Node *&node, bool &shorter){
		if (node->balance == LH) {
			node->balance = EH;
		}
		else if (node->balance == EH) {
			node->balance = RH;
			shorter = false;
		}
		else {
			Node* rightTree = node->pRight;
			if (rightTree->balance == LH) {
				Node* leftTree = rightTree->pLeft;
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
				node->pRight = rotateRight(rightTree);
				node->pRight = rotateRight(rightTree);
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
    Node *removeLeftBalance(Node* &node, bool &shorter){
	if (node->balance == RH) {
		node->balance = EH;
	}
	else if (node->balance == EH) {
		node->balance = LH;
		shorter = false;
	}
	else {
		Node* leftTree = node->pLeft;
		if (leftTree->balance == RH) {
			Node* rightTree = leftTree->pRight;
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
			node->pLeft = rotateLeft(leftTree);
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
    void remove(const T &value){
        bool shorter = false;
	    bool success = false;
	    root = removeRec(root, value, shorter,success);
    }
    void printInRec(Node* node){
        if(node == NULL) return;
        printInRec(node->pLeft);
        cout<<node->data<<" ";
        printInRec(node->pRight);
    }
    void printInorder(){
        printInRec(root);
    }
    bool search(T value, Node * &node){
    	if (node == NULL) return false;
    	else if (value == node->data) return true;
    	else if (value > node->data) return search(value,node->pRight);
    	else return search(value,node->pLeft);
    }
	bool search(const T &value){
    	return search(value,root);
	}
    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};

int main(){
  AVLTree<int> avl;
int arr[] = {10,52,98,32,68,92,40,13,42,63,99,100};
for (int i = 0; i < 12; i++){
	avl.insert(arr[i]);
}
avl.printInorder();
cout << endl;
cout << avl.search(10);
}