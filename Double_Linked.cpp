#include <iostream>
#include <string.h>
#include<iterator>
#include <vector>
#include <sstream>
#include <assert.h> 
using namespace std;


template <class T>
class DLinkedList {
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
    void add(const T& e) {
        /* Insert an element into the end of the list. */
        if(this->count == 0){
            Node* tmp = new Node(e);
            head = tmp;
            tail = tmp;
            this->count++;
        }
        else {
            Node* tmp = new Node(e);
            tmp->previous = tail;
            tail->next = tmp;
            tail = tmp;
            this->count++;
        }
    }

    void add(int index, const T& e) {
        /* Insert an element into the list at given index. */ 
        if(index < 0 || index > this->count){ 
            throw std::out_of_range("Index is out of range");
        }
        else if(this->count == 0 || this->count == index){
            add(e);
        }
        else if(index == 0){
            Node* tmp = new Node(e);
            tmp->next = head;
            head->previous = tmp;
            head = tmp;
            this->count++;
        }
        else {
            Node* tmp = new Node(e);
            Node* pre = head;
            for(int i = 0; i < index - 1; i++){
                pre=pre->next;
            }
            Node* pre2 = pre->next;
            tmp->next = pre2;
            pre2->previous = tmp;
            pre->next = tmp;
            tmp->previous = pre;
            this->count++;
        }
    }

    int size() {
        /* Return the length (size) of list */ 
        return this->count;
    }

    T get(int index) {
    /* Give the data of the element at given index in the list. */
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


    void set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
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

    bool empty() {
    /* Check if the list is empty or not. */
        return (this->count == 0);
    }

    int indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
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

    bool contains(const T& item) {
        /* Check if item appears in the list */
        Node *tmp = head;
        for(int i = 0; i < this->count; i++){
            if (tmp->data == item)
            {
                return true;
            }
            else tmp=tmp->next;
        }
        return false;
    }
    
    T removeAt(int index)
    {
    /* Remove element at index and return removed value */
    if (index < 0 || index >= count) {
       throw std :: out_of_range (" Index is out of range ");
       }
        if (index == 0 && count>1) {
            Node *tmp = head;
            head = head->next;
            int temp = tmp->data;
            delete[] tmp;
            this->count--;
            return temp;
        }
        else if (index == 0 && count == 1){
            Node* tmp = head;
            int temp=tmp->data;
            delete[] tmp;
            this->count=0;
            return temp;
        }
        else if (index == count-1) {
            Node* tmp = tail;
            int temp = tail->data;
            tail = tail->previous;
            delete[] tmp;
            this->count--;
            return temp;
        }
        else {
            Node *pre = head;
            for (int i=0; i<index-1; i++) {
                pre = pre->next;
            }
            Node *tmp = pre->next;
            Node *pre2 = tmp->next;
            int temp = tmp->data;
            pre->next = pre2;
            pre2->previous = pre;
            delete[] tmp;
            this->count--;
            return temp;
        }
    }


    bool removeItem(const T& item)
    {
    /* Remove the first apperance of item in list and return true, otherwise return false */
        int i;
        Node *tmp = head;
        for(i = 0;i<this->count; i++){
            if(tmp->data == item){
                removeAt(i);
                return true;
            }
            else tmp = tmp->next;
        }
        return false;
    }

    
    void clear(){
    /* Remove all elements in list */
	    while (this->head != NULL)
	    {
            Node *temp = head;
		    head = head->next;
		    delete temp;
	    }
	    this->count = 0;
    }
    string toString() {
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

public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin){
            this->pList = pList;
            if(begin){
                if(pList!=NULL){
                    index = 0;
                    current = pList->head;
                }
                else{
                    index = -1;
                    current = NULL;
                }
            }
            else{
                current = NULL;
                if(pList!=NULL){
                    index = pList->count;
                }
                else index = 0;
            }
        }
        Iterator &operator=(const Iterator &iterator){
            this->current = iterator.current;
            this->index = iterator.index;
            this->pList = iterator.pList;
        }
        void set(const T &e){
            if (current == NULL) {
                throw std::out_of_range("Segmentation fault!");
            }
            else current->data = e;
        }
        T &operator*(){
            if (current == NULL){
                throw std::out_of_range("Segmentation fault!");
            }
            else return current->data;
        }
        bool operator!=(const Iterator &iterator){
            return (this->current != iterator.current || this->index != iterator.index);
        }
        void remove(){
            if(current == NULL) throw std::out_of_range("Segmentation fault!");
            else{
                if(index == 0){
                    pList->removeAt(index);
                    current = NULL;
                }
                else{
                    pList->removeAt(index);
                    ++*this;
                }
            }
        }
        
        // Prefix ++ overload
        Iterator &operator++(){
            if (current == NULL) throw std::out_of_range("Segmentation fault!");
            current = current->next;
            index++;
            return *this;
        }
        
        // Postfix ++ overload
        Iterator operator++(int){
            if (current == NULL) throw std::out_of_range("Segmentation fault!");
            Iterator temp = *this;
            ++*this;
            return temp;
        }
    };
};

int main(){
   DLinkedList<int> list;
int size = 10;
for(int idx=0; idx < size; idx++){
    list.add(idx);
}
DLinkedList<int>::Iterator it = list.begin();
for(; it != list.end(); it++)
{
    cout << *it << " |";
}
}