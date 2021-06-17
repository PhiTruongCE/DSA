#include <iostream>
#include <string.h>
#include<iterator>
#include <vector>
using namespace std;

class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term){
        
    }
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};

int main(){
    Polynomial *poly = new Polynomial();
poly->insertTerm(6.0, 2);
poly->insertTerm(4.0, 5);
poly->insertTerm(4.0, 3);
poly->insertTerm(6.0, 5);
poly->insertTerm(-1.0, 0);
poly->insertTerm(-6.0, 6);
poly->insertTerm(6.0, 6);
poly->print();
return 0;
}
template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void    add(T e){
        if(this->count == 0){
            Node* tmp = new Node(e);
            head = tmp;
            tail = tmp;
            this->count++;
        }
        else{
            Node* tmp = new Node(e);
            tail->next = tmp;
            tail = tmp;
            this->count++;
        }
    }
    void    add(int index, T e){
        if(index < 0 || index > this->count){ 
            throw std::out_of_range("Index is out of range");
        }
        else if(this->count == 0 || this->count == index){
            add(e);
        }
        else if(index == 0){
            Node* tmp = new Node(e);
            tmp->next = head;
            head = tmp;
            this->count++;
        }
        else {
            Node* tmp = new Node(e);
            Node* pre = head;
            for(int i = 0; i < index - 1; i++){
                pre=pre->next;
            }
            tmp->next = pre->next;
            pre->next = tmp;
            this->count++;
        } 
    }
    int     size(){
        return this->count;
    }
    void    clear(){
        Node *temp = new Node();
	    while (this->head != NULL)
	    {
		    temp = this->head;
		    this->head = this->head->next;
		    delete temp;
	    }
	    this->count = 0;
    };
    T       removeAt(int index){
        if (index < 0 || index >= count) {
       throw std :: out_of_range (" Index is out of range ");
       //return -1;
       }
        if (index == 0) {
            Node *tmp = head;
            head = head->next;
            int temp = tmp->data;
            delete tmp;
            this->count--;
            return temp;
        }
        else if (index == count-1) {
            Node *pre = head;
            for (int i=0; i<index-1; i++) {
                pre = pre->next;
            }
            Node *tmp = tail;
            int temp = tmp->data;
            tail = pre;
            delete tmp;
            this->count--;
            return temp;
        }
        else {
            Node *pre = head;
            for (int i=0; i<index-1; i++) {
                pre = pre->next;
            }
            Node *tmp = pre->next;
            pre->next = tmp->next;
            int temp = tmp->data;
            delete tmp;
            this->count--;
            return temp;
        }
    };
    bool    removeItem(T item){
        int i;
        Node *tmp = head;
        for(i = 0;i<this->count - 1; i++){
            if(tmp->data == item){
                removeAt(i);
                return true;
            }
            else tmp = tmp->next;
        }
        return false;
    };
    virtual string toString() {
        stringstream ss;
        ss << "[";
        Node* ptr = head;
        while(ptr != tail){
            ss << ptr->data << ",";
            ptr = ptr->next;
        }
        
        if(count > 0)
            ss << ptr->data << "]";
        else 
            ss << "]";
        return ss.str();
    }
    bool    empty(){
        return (this->count == 0);
    }
    T       get(int index){
        if(index < 0 || index > this->count){ 
            throw std::out_of_range("Index is out of range");
        }
        else if(index == 0) return head->data;
        else if(index == this->count - 1) return tail->data;
        else {
            Node *tmp = head;
            for(int i = 0; i <= index ; i++){
                tmp = tmp->next;
            }
            return tmp->data;
        }
    }
    void    set(int index, T e){
        if(index < 0 || index > this->count){ 
            throw std::out_of_range("Index is out of range");
        }
        else if(index == 0) head->data = e;
        else if(index == this->count - 1) tail->data = e;
        else {
            Node *tmp = head;
            for(int i = 0; i <= index ; i++){
                tmp = tmp->next;
            }
            tmp->data = e;
        }
    };
    int     indexOf(T item){
        Node *tmp = head;
        for(int i = 0; i < this->count - 1; i++){
            if (tmp->data == item)
            {
                return i;   
            }
            else tmp=tmp->next;
        }
        return -1;
    }
    bool    contains(T item){
        Node *tmp = head;
        for(int i = 0; i < this->count - 1; i++){
            if (tmp->data == item)
            {
                return true;
            }
            else tmp=tmp->next;
        }
        return false;
    };
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};