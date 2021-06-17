#include <iostream>
#include <string.h>
#include<iterator>
#include <vector>
using namespace std;



template <class T>
class SLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    SLinkedList() : head(NULL), tail(NULL), count(0){};
    ~SLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;
    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator(SLinkedList<T> *pList, bool begin){
            this->pList = pList;
            if(begin){
                if (head != NULL){
                    this->index = 0;
                    this->current = head;
                }
                else this->index = -1;
            }
            else{
                this->current = NULL;
                if(head != NULL){
                    this->index = pList->size();
                }
                else this->index = 0;
            }

        }
        Iterator &operator=(const Iterator &iterator){
            this->pList = iterator.pList;
            this->index = iterator.index;
            this->current = iterator.current;
        }
        void set(const T &e){
            this->current = e;
        }
        T &operator*();
        bool operator!=(const Iterator &iterator);
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};
template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
    this->pList = pList;
    
    if (begin==true) {
        if (pList != NULL) {
            index = 0;
            current = pList->head;
        }
        else {
        
            index = -1;
            current = NULL;
        }
    }
    else {
        current = NULL;
        if (pList != NULL) {
            index = pList->count;
        }
        else {
            index = 0;
        }
        
    }
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iteratr coorresponelementsding .
    */
    this->current   = iterator.current;
    this->index     = iterator.index;
    this->pList     = iterator.pList;
    return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */

    if (current == NULL){
       throw std::out_of_range("Segmentation fault!");
    }
    if (index == 0) {
        pList->removeAt(0);
        current = NULL;
        index = -1;
    }
    else {
        Node * temp = pList->head;
        while (temp) {
            if (temp->next == current) break;
            temp = temp->next;
        }
        pList->removeAt(index);
        current = temp;
        index -= 1;
    }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (current == NULL) {
      throw std::out_of_range("Segmentation fault!");
    }
    current->data = e;
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (current == NULL){
       throw std::out_of_range("Segmentation fault!");
    }
    else{
        return current->data;
    }
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns true if two iterators points the same node and index
    */
   return !(this->current == iterator.current && this->index == iterator.index);
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to  theend
    */
    if (current == NULL){
        throw std::out_of_range("Segmentation fault!");
    }
    current = current->next;
    index += 1;
    return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (current == NULL){
        throw std::out_of_range("Segmentation fault!");
    }
    Iterator temp = *this;
    ++*this;
    return temp;
}
int main(){
    SLinkedList<int> list;
    
    int size = 10;
    for(int idx=0; idx < size; idx++){
        list.add(idx);
    }
        
    SLinkedList<int>::Iterator it;
    int expvalue = 0;
    for(it = list.begin(); it != list.end(); it++){
        assert(*it == expvalue);
        expvalue += 1;
    }
    return 0;
}