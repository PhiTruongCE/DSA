/*#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    int largeChild;
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;
    if (leftChild <= numberOfElements )
    {
        if (rightChild <= numberOfElements && maxHeap[rightChild] > maxHeap[leftChild])
        {
            largeChild = rightChild;
        }
        else 
        {
            largeChild = leftChild;
        }
        if (maxHeap[largeChild] > maxHeap[index])
        {
            swap(maxHeap[largeChild], maxHeap[index]);
            reheapDown(maxHeap, numberOfElements,largeChild);
        }
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if (index > 0 && index<numberOfElements)
    {
        int parent = (index -1)/2;
        if (maxHeap[index] > maxHeap[parent])
        {
            swap(maxHeap[index],maxHeap[parent]);
            reheapUp(maxHeap,numberOfElements, parent);
        }
    }
}*/
/*
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    int getItem(T item);
    void remove(T item);
    void clear();
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};

template <class T>
void Heap<T>::reheapDown(int position){
    int largeChild;
    int leftChild = position * 2 + 1;
    int rightChild = position * 2 + 2;
    if (leftChild <= count )
    {
        if (rightChild <= count && elements[rightChild] > elements[leftChild])
        {
            largeChild = rightChild;
        }
        else 
        {
            largeChild = leftChild;
        }
        if (elements[largeChild] > elements[position])
        {
            swap(elements[largeChild], elements[position]);
            reheapDown(largeChild);
        }
    }
}
template<class T>
int Heap<T>::getItem(T item) {
    for(int i = 0; i < count; i++){
        if(elements[i] == item) return i;
    }
}

template<class T>
void Heap<T>::remove(T item) {
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            if (elements[i] == item)
            {
                elements[i] = elements[count -1];
                count--;
                reheapDown(0);
            }
        }
    }
}

template<class T>
void Heap<T>::clear() {
    delete[]elements;
    capacity = 0;
    count = 0;
}
template<class T>
void Heap<T>::push(T item){
    if(count == capacity) ensureCapacity(capacity+1);
    elements[count] = item;
    count++;
    reheapUp(count-1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    T *temp = new T[minCapacity];
    for(int i=0; i < count; i++){
        temp[i] = elements[i];
    }
    capacity = minCapacity;
    elements = temp;
}

template<class T>
void Heap<T>::reheapUp(int position){
    if (position > 0 && position < count)
    {
        int parent = (position - 1) / 2;
        if (elements[position] > elements[parent])
        {
            swap(elements[position], elements[parent]);
            reheapUp(parent);
        }
    }
}

template<class T>
int Heap<T>::size(){
    return this->count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return (this->count == 0);
}

template<class T>
T Heap<T>::peek(){
    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for(int i = 0; i < this->count; i++){
        if(elements[i] == item) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if(isEmpty()) return false;
    elements[0] = elements[count-1];
    count--;
    reheapDown(0);
    return true;
}

int main(){
    Heap<int> maxHeap;
int arr[] = { 13, 19, 20, 7, 15, 12, 16, 10, 8, 9, 3, 6, 18, 2, 14, 1, 17, 4, 11, 5 };
for (int i = 0; i < 20; ++i)
    maxHeap.push(arr[i]);
maxHeap.clear();
maxHeap.printHeap();
}*/
/*
#define SEPARATOR "#<ab@17943918#@>#"
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    static void reheapDown(T* start, T* end, int position){
        int count = end - start;
		int largest = position; 
		int l = 2 * position + 1; 
		int r = 2 * position + 2; 

		if (l < count && start[l] > start[largest])
			largest = l;

		if (r < count && start[r] > start[largest])
			largest = r;
	
		if (largest != position) {
			swap(start[position], start[largest]);
			reheapDown(start, end, largest);
		}
    }
    static void heapSort(T* start, T* end){
        int count = end - start;
        for(int i = count/2 - 1; i >= 0; i--) reheapDown(start, end,i);
        for(int i = count - 1; i > 0; i --){
            swap(start[0],start[i]);
            reheapDown(start,start + i, 0);
        }
        Sorting<T>::printArray(start,end);
    }
    
};
#endif

int main(){
    int arr[4]={4,2,9,1};
Sorting<int>::heapSort(&arr[0],&arr[4]);
}*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int minWaitingTime(int n, int arrvalTime[], int completeTime[]) {
    int result = 0;
    vector<int> v1(arrvalTime,arrvalTime+n);
    //vector<int> v2(completeTime,completeTime+n);
    make_heap(v1.begin(),v1.end());
    //make_heap(v2.begin(),v2.end());
    sort_heap(v1.begin(),v1.end());
    //sort_heap(v2.begin(),v2.end());
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            if(arrvalTime[j] == v1.front()){
                result += completeTime[j] - arrvalTime[j];
                pop_heap(v1.begin(),v1.end());
            }
        }
    }
    return result;
}

int main(){
    int n = 2; 
    int arrvalTime[] = { 0, 1 };
    int completeTime[] = { 3, 9};
    cout << minWaitingTime(n, arrvalTime, completeTime);
}