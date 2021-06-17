#include <iostream>
#include <string.h>
using namespace std;
class IntSLinkedList : public IList<int> {
public:
    class Node; // Forward declaration

private:
    Node* head;
    Node* tail;
    int count;

public:
    IntSLinkedList() : head(NULL), tail(NULL), count(0) {};
    virtual void add(int element) {
        if(this->count == 0){
            Node* tmp = new Node(element);
            head = tmp;
            tail = tmp;
            this->count++;
        }
        else{
            Node* tmp = new Node(element);
            tail->next = tmp;//tail is pointer (*tail).next
            tail = tmp;
            this->count++;
        }
    }

    virtual void add(int index, int element) {
        if(index < 0 || index > this->count){ 
            throw std::out_of_range("Index is out of range");
        }
        else if(this->count == 0 || this->count == index){
            add(e);
        }
        else if(index == 0){
            Node* tmp = new Node(element);
            tmp->next = head;
            head = tmp;
            this->count++;
        }
        else {
            Node* tmp = new Node(element);
            Node* pre = head;
            for(int i = 0; i < index - 1; i++){
                pre=pre->next;
            }
            tmp->next = pre->next;
            pre->next = tmp;
            this->count++;
        }  
    }

    virtual int removeAt(int index) {
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
    }

    virtual bool removeItem(int item) {
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
    }

    virtual bool empty() {
        return (this->count == 0);
    }

    virtual int size() {
        return this->count;//done
    }
    
    virtual int get(int index) {
        return -1;
    }

    virtual void set(int index, int element) {

    }

    virtual int indexOf(int item) {
        return -1;
    }

    virtual bool contains(int item) {
        return false;
    }
    
    virtual void clear() {
        Node *temp = new Node();
	    while (this->head != NULL)
	    {
		    temp = this->head;
		    this->head = this->head->next;
		    delete temp;
	    }
	    this->count = 0;
    }
    
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

public:
    class Node {
    public:
        int data;
        Node* next;
    public:
        Node() : next(NULL) {};
        Node(int data) : 
            data(data), next(NULL) {};
    };
};
int main(){
    IntDLinkedList list;
int size = 10;
for(int index = 0; index < size; index++){
    list.add(index);
}

int count = size;
for(int idx = 0; idx < size; idx++) {
    assert(list.removeAt(0) == idx);
    count--;
    assert( list.size() == count );
}

try {
    list.removeAt(0);
}
catch(std::out_of_range e){
    cout << "Out of range";

}