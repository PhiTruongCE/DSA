
#include <string>
#include <iostream>
#include <sstream>
#include <type_traits>
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
    SLinkedList()
    {
      this->head = nullptr;
      this->tail = nullptr;
      this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e)
    {
        Node *pNew = new Node(e);

        if (this->count == 0)
        {
            this->head = this->tail = pNew;
        }
        else
        {
            this->tail->next = pNew;
            this->tail = pNew;
        }

        this->count++;
    }
    int size()
    {
        return this->count;
    }
    void printList()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
    }
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
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    void bubbleSort();
};

template <class T>
void SLinkedList<T>::bubbleSort()
{   
    int i,j;
    for(i = 0; i < this->count - 1; i++){
        Node* tmp = head;
        //int swap = 0;
        for(j = 0; j < this->count - 1; j++){
            Node* p1 = tmp;
            Node* p2 = p1->next;
            if(p1->data > p2->data){
                int temp = p2->data;
                p2->data = p1->data;
                p1->data = temp;
                //swap = 1;
            } 
            tmp = tmp->next;
        }
        //if(swap == 0) break;
        printList();
    }
}


string bubbleSort(string a, int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (int(a[j]) > int(a[j+1])){
                string b = "0";
                b[0] = a[j];
                a[j] = a[j+1];
                a[j+1] = b[0];
            } 
        }   
    }     
    return a;     
} 

bool isPermutation (string a, string b) {
    //TODO
    if(a.length() != b.length()) return false;
    a = bubbleSort(a,a.length());
    b = bubbleSort(b,b.length());
    return a == b;
}

/*template <class T>
class Sorting
{
public:
    
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void oddEvenSort(T *start, T *end);
};*/
/*
template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end);

public:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void insertionSort(T *start, T *end);

    static void hybridQuickSort(T *start, T *end, int min_size);
};

template <class T>
T *Sorting<T>::Partition(T *start, T *end)
{
    T pivot = start[end];
    int i = start - 1;
    for(int j = start; j <= end - 1; j ++){
        if(start[j] <= pivot){
            i++;
            T k = start[i];
            start[i] = start[j];
            start[j] = k;  
        }
    }
    T a = start[i+1];
    start[i+1] = start[end];
    start[end] = a;
    return i + 1; 
}

template <class T>
void Sorting<T>::insertionSort(T *start, T *end)
{
    for(int i = start + 1; i < end + 1; i++){
        T val = start[i];
        int j = i;
        while(j>start && start[j-1]>val){
            start[j] = start[j-1];
            j-=1;
        }
        start[j] = val;
    }
}

template <class T>
void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size)
{
    while(start < end){
        if(end - start + 1 < min_size){
            insertionSort(start,end);
            break;
        }
        else{
            T pivot = Partition(*start,*end);
            if(pivot - start < end - pivot){
                hybridQuickSort(start,pivot - 1, min_size);
                start = pivot + 1;
            }
            else{
                hybridQuickSort(pivot + 1,end,min_size);
                end = pivot - 1;
            }
        }
    }

}*/
/*
template <class T>
class Sorting {
public:
    
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    static void merge(T* left, T* middle, T* right){
        int n1 = middle - left +1;
        int n2 = right - middle;
        T R[n1], L[n2];
        for(int i = 0; i < n1; i++){
            L[i] = left[i+1];
        }
        for(int i = 0 ; i < n2 ; i++){
            R[i] = left[middle+1+i];
        }
        int i = 0;
        int j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                left[k] = L[i];
                i++;
            }
            else {
                left[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            left[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            left[k] = R[j];
            j++;
            k++;
        }
        Sorting::printArray(left, right);
    }
    static void mergeSort(T* start, T* end) {
        int start1 = start;
        int end1 = end;
       if(start >= end){
           return;
       }
       int m = start1 + (end1 - 1)/2;
       mergeSort(start,m);
       mergeSort(m+1,end);
       merge(start1,m,end);
    }
};*/
/*
template <class T>
class Sorting
{
public:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void selectionSort(T *start, T *end);
};

template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int n = end - start;
     int i, j, min_idx;  
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++){
            if (start[j] < start[min_idx]) 
                min_idx = j;
        } 
        T temp = start[min_idx];
        start[min_idx] = start[i];
        start[i] = temp; 
        Sorting::printArray(start,end);
    } 
}
*/
/*
template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
        T *curr = segment_idx + start;
        while(curr < end){
            T temp = *curr;
            T *step = curr - cur_segment_total;
            while(step >= start && temp < *step){
                *(step + cur_segment_total) = *step;
                step = step - cur_segment_total;
            } 
            *(step + cur_segment_total) = temp;
            curr = curr + cur_segment_total;
        }
    }

public:
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases){
        for (int i = num_phases - 1; i >= 0; i--) {
            for (int j = 0; j < num_segment_list[i]; j++) {
                sortSegment(start, end, j, num_segment_list[i]);
            }
            cout << num_segment_list[i] << " segments: ";
        printArray(start, end);
        }
    }
};
*/
template <class T>
class Sorting {
private:
    static T* Partition(T* start, T* end) {
    T* i = start;
    T* j = end;
    int n = j- i;
    T pivot = start[i];
    while (true) {
        do {
            i++;
        } while (start[i] < pivot);
        do {
            j--;
        } while (start[j] > pivot);
        if (i >= j)
            return start;
        T temp = start[i];
        start[i] = start[j];
        start[j] = temp;
    }
    }
public:
    static void QuickSort(T* start, T* end){
        if(start < end){
        T* pi = Partition(start, end);
        QuickSort(start,pi);
        QuickSort(pi,end);
    }
    }
};
/*
template <class T>
class Sorting
{
public:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void oddEvenSort(T *start, T *end);
};

template <class T>
void Sorting<T>::oddEvenSort(T *start, T *end)
{
    int n = end - start;
    bool check = true;
    while(check){
        check = false;
        for(int i = 0 ; i < n - 1; i+=2){
            if(start[i] > start[i+1]){
                T temp = start[i];
                start[i] = start[i+1];
                start[i+1] = temp;
                check = true;
            }
        }
        for(int i = 1; i < n - 1; i+=2){
            if(start[i] > start[i+1]){
                T temp = start[i];
                start[i] = start[i+1];
                start[i+1] = temp;
                check = true;
            }
        }
        printArray(start, end);
    }
}
*/
int main(){
    int num_segment_list[] = {1, 3, 5};
int num_phases = 3;
int array[] = { 10, 9, 8 , 7 , 6, 5, 4, 3, 2, 1 };

Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
    return 0;
}