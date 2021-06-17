#include <iostream>
#include <string.h>
#include<iterator>
#include <vector>
#include <sstream>
#include <assert.h> 
using namespace std;

#ifndef STACK_H
#define STACK_H
#include "DLinkedList.h"
template<class T>
class Stack {
protected:
    DLinkedList<T> list;
public:
    void push(T item) {
    // TODO: Push new element into the top of the stack
    list.add(item);
}

T pop() {
    // TODO: Remove an element on top of the stack
        int size = list.size();
        return list.removeAt ( size - 1);
}

T top() {
    // TODO: Get value of the element on top of the stack
        int size = list.size ();
        return list.get( size - 1);
        
}

bool empty() {
    // TODO: Determine if the stack is empty
    return  list.empty();
}

int size() {
    // TODO: Get the size of the stack
    return  list.size();
}

void clear() {
    // TODO: Clear all elements of the stack
    list.clear();
}
};

#endif
int main(){
    Stack<int> stack;
    cout << stack.empty() << " " << stack.size();
}