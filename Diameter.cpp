#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
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
    
    int max(int a,int b){
        return a > b ? a : b;
    }
    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(height(root->pLeft), height(root->pRight));
    }
    int Diameter(Node* root){
        if(root == NULL){
            return 0;
        }
        int lheight = height(root->pLeft);
        int rheight = height(root->pRight);
        int lDiameter = Diameter(root->pLeft);
        int rDiameter = Diameter(root->pRight);
        return max(lheight + rheight + 1, max(lDiameter, rDiameter));
    }
    int getDiameter(){
        return Diameter(this->root);
    }
    void printGivenLevel(Node* node, int level){
        if (node == NULL) return;
        if (level == 1) cout << node->value << " ";
        else if (level > 1){
            printGivenLevel(node->pLeft, level-1);
            printGivenLevel(node->pRight, level-1);
        }
    }
    void BFSRec(Node* node){
        int h = height(node);
        int i;
        for(i = 1; i <= h; i++){
            printGivenLevel(node,i);
        }
    }
    void BFS(){
        BFSRec(root);
    }
};

int main()
{
BinaryTree<int, int> binaryTree;
binaryTree.addNode("",2, 4); // Add to root
binaryTree.addNode("L",3, 6); // Add to root's left node
binaryTree.addNode("R",5, 9); // Add to root's right node
binaryTree.BFS();
}