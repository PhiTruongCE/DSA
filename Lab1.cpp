#include <iostream>
#include <string.h>
using namespace std;
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
        if (index<0 || index > count || count == 0)
        throw std::out_of_range("invalid index");
    /* Remove element at index and return removed value */
    if (index == 0 && count>1)
    {
        Node *tmp = head;
            head = head->next;
            int temp = tmp->data;
            delete tmp;
            this->count--;
            return temp;
    }
    if (index == 0 && count == 1)
    {
        int tmp = head->data;
        this->count=0;
        head=NULL;
        return tmp;
    }
    else if (index == count-1)
    {
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
    }
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
            for(int i = 0; i < index ; i++){
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
            for(int i = 0; i < index ; i++){
                tmp = tmp->next;
            }
            tmp->data = e;
        }
    }
    int     indexOf(T item){
        Node *tmp = head;
        for(int i = 0; i < this->count; i++){
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
        for(int i = 0; i < this->count; i++){
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


int main(){
    SLinkedList<int> list;
    int values[]   = {10, 15, 2,  6,  4,  7,  40,  8};
    int index[]    = {0,  0,  1,  3,  2,  3,  5,   0};
    int expvalues[]= {8,  15, 2,  4,  7, 10,  40,  6}; 

    for (int idx = 0; idx < 8; idx++){
    list.add(index[idx], values[idx]);
    }

    assert( list.size() == 8 );
        
    for (int idx = 0; idx < 8; idx++){
        assert( list.get(idx) == expvalues[idx] );
    }

    cout << list.toString();
}