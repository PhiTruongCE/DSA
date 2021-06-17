#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
//template<class T>
//template<class K, class V>
class BinarySearchTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {

    }
    void addRec(Node *&node, const T &value){
    if(node == nullptr){
        Node* new_node = new Node(value);
        new_node->pLeft = new_node->pRight = nullptr;
        node = new_node;
        return;
    }
    else{
        if(value >= node->value)
        {
            if(node->pRight != nullptr)
                return addRec(node->pRight, value);
            else{
                Node* new_node = new Node(value);
                new_node->pLeft = new_node->pRight = nullptr;
                node->pRight = new_node;
            }
        }   
        else{
            if(node->pLeft!= nullptr)
                return addRec(node->pLeft, value);
            else{
                Node* new_node = new Node(value);
                new_node->pLeft = new_node->pRight = nullptr;
                node->pLeft = new_node;
            }
        }     
    }
}

void deleteNodeRec(Node *&node, const T &value){
    if(node == nullptr)
        return;
    
    if(value < node->value)
        return deleteNodeRec(node->pLeft, value);
    
    else if(value > node->value)
        return deleteNodeRec(node->pRight, value);
    
    else{
        if(node->pLeft == nullptr){
            Node* temp = node;
            node = node->pRight;
            delete temp;
        }
        else if(node->pRight == nullptr){
            Node* temp = node;
            node = node->pLeft;
            delete temp;
        }
        else{
            Node* temp = node->pRight;
            while(temp->pLeft != nullptr){
                temp = temp->pLeft;
            }
            node->value = temp->value;
            return deleteNodeRec(node->pRight, node->value);
        }
    }
}

void add(T value){
    return addRec(this->root, value);
    
}

void deleteNode(T value){
    return deleteNodeRec(this->root, value);
    
}

    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder(){
        return inOrderRec(this->root);
    }
    
    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;
    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
   /*class Node
    {
    private:
        K key;
        V value;
        Node* pLeft, * pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = (int)posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    int countTwoChildrenRec(Node node)
    {
        if(node == NULL) {
            return 0;
        }
        if(node->pLeft != NULL && node->pRight != NULL) {
            return 1 + countTwoChildrenRec(node.left) + countTwoChildrenRec(node.right);
        }
        return countTwoChildrenRec(node->pLeft) + countTwoChildrenRec(node->pRight);
    }
    //Helping functions
    int countTwoChildrenNode()
    {
        return countTwoChildrenRec(root);
    }
};
/*template<class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if(posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }

    int countTwoChildrenRec(Node* node)
    {
        if(node == NULL) {
            return 0;
        }
        if(node->pLeft != NULL && node->pRight != NULL) {
            return 1 + countTwoChildrenRec(node->pLeft) + countTwoChildrenRec(node->pRight);
        }
        return countTwoChildrenRec(node->pLeft) + countTwoChildrenRec(node->pRight);
    }
    
    int countTwoChildrenNode()
    {
        return countTwoChildrenRec(root);
    }

    bool isBSTRec(Node* node, Node* prev){
        if (node){
            if (!isBSTRec(node->pLeft, prev)) return false;
            if (prev != NULL && node->value <= prev->value) return false;
            prev = node;
            return isBSTRec(node->pRight, prev);
        }
        return true;
    }

    bool isBST() {
    
        return isBSTRec(root,NULL);
    }
    int sumOfLeafsRec(Node* node){
        if(node == NULL) return 0;
        if(node->pLeft == NULL && node->pRight == NULL) return node->value;
        else return sumOfLeafsRec(node->pLeft) + sumOfLeafsRec(node->pRight);
    }
    int sumOfLeafs(){
        return sumOfLeafsRec(root);
    }
    int max(int a,int b){
        return a > b ? a : b;
    }
    int height(Node* node){
        if(node == NULL){
            return 0;
        }
        return 1 + max(height(node->pLeft), height(node->pRight));
    }
    int getHeight() {
        height(root);
    }   
    void preRec(Node* node){
        if (node){
            k.append(to_string(node->value) + " ");
            preRec(node->pLeft);
            preRec(node->pRight);
        }   
    }
    string k = "";
    string preOrder() {
        preRec(root);  
        return k;
    }
    void inRec(Node* node){
        if(node){
            inRec(node->pLeft);
            l.append(to_string(node->value) + " ");
            inRec(node->pRight);
        }
    }
    string l = "";
    string inOrder() {
        inRec(root);
        return l;
    }
    void postRec(Node* node){
        if(node){
            postRec(node->pLeft);
            postRec(node->pRight);
            t.append(to_string(node->value) + " ");
        }
    }
    string t = "";
    string postOrder() {
        postRec(root);
        return t;
    }
};*/
    int isBSTRec(struct Node* node, int min, int max){
        if (node==NULL)
            return 1;
        if (node->value < min || node->value > max)
            return 0;
        return isBSTRec(node->pLeft, min, node->value - 1) && isBSTRec(node->pRight, node->value + 1, max);
    }
    bool isBST() {
        return isBSTUtil(root, INT8_MIN, INT8_MAX);
    }

int main(){
    	BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4); // Add to root
    binaryTree.addNode("L", 3, 6); // Add to root's left node
    binaryTree.addNode("R", 5, 9); // Add to root's right node

    cout << binaryTree.getHeight() << endl;
    cout << binaryTree.preOrder() << endl;
    cout << binaryTree.inOrder() << endl;
    cout << binaryTree.postOrder() << endl;
}