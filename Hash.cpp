#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;
class ChainingHash {
private:
    int (*hash)(int);
    list<int> *data;
    int size;
    
public:
    ChainingHash() {
        throw "Cannot create a hash with no hash function!";
    }
    
    ChainingHash(int size, int (*hash)(int)) {
        this->hash = hash;
        this->size = size;
        this->data = new list<int>[size];
    }
    
    void insert(int key) {
        int k = key % size;
        data[k].push_back(key);
    }

    void remove(int key) {
        int k = key % size;
        data[k].remove(key);
    }

    bool search(int key) {
        int k = key % size;
        int t = data[k].size();
        if(size == 0) return false;
        else{
            for(int i = 0; i < t; i++){
                if(key == data[k].front()){
                    return true;
                }
                else{
                    int temp = data[k].front();
                    data[k].pop_front();
                    data[k].push_back(temp);
                }
            }
            return false;
        }
    }
    
    int count() {
        int total = 0;
        for (int i = 0; i < this->size; i++) {
            total += this->data[i].size();
        }
        return total;
    }
    
    void dump() {
        for (int i = 0; i < this->size; i++) {
            cout << "Slot " << i << ": " << this->data[i].size() << " element(s)" << endl;
        }
    }
};

int hashWith11(int key) {
    return key % 11;
}
int hashWith15(int key) {
    return key % 15;
}
int hashWith17(int key) {
    return key % 17;
}

enum STATUS_TYPE {NIL, NON_EMPTY, DELETED};
class OpenHash {
private:
    int (*hp)(int, int);
    STATUS_TYPE* status;
    int* data;
    int size;
    
public:
    OpenHash() {
        throw "Cannot create a hash with no hash function!";
    }
    
    OpenHash(int size, int (*hp)(int, int)) {
        this->hp = hp;
        this->size = size;
        this->data = new int[size];
        this->status = new STATUS_TYPE[size];
        for (int i = 0; i < size; i++) {
            this->status[i] = NIL;
        }
    }
    
    int insert(int key) {
        int k = key % size;
        if(status[k] == NIL || status[k] == DELETED){
            data[k] = key;
            status[k] = NON_EMPTY;
            return k;
        }
        else{
            for(int i = 0; i < size; i++){
                if(status[hp(key,i)] == NIL || status[hp(key,i)] == DELETED){
                    data[hp(key,i)] = key;
                    status[hp(key,i)] = NON_EMPTY;
                    return hp(key,i);
                }
            }
            throw "Overflow!";
        }
    }

    void remove(int key) {
        bool check = true;
        int k = key % size;
        if(status[k] == NON_EMPTY){
            status[k] = DELETED;
            check = false;
        }
        else{
            for(int i = 0; i < size; i++){
                if(status[hp(key,i)] == NON_EMPTY){
                    status[k] = DELETED;
                    check = false;
                }
            }
        }
        if(check) throw "Not found!";
    }

    int search(int key) {
        int k = key % size;
        if(data[k] == key) return k;
        else{
            for(int i = 0; i < size; i++){
                if(data[hp(key,i)] == key){
                    return hp(key,i);
                }
            }
            return -1;
        }
    }  
    
    void dump() {
        for (int i = 0; i < this->size; i++) {
            if (this->status[i] != NON_EMPTY)
                cout << "Slot " << i << ": Empty" << endl;
            else cout << "Slot " << i << ": " << this->data[i] << endl;
        }
    }
};

int linearProbing(int key, int i) {
    return ((key % 11) + i) % 11;
}

int quadraticProbing(int key, int i) {
    return ((key % 11) + i + 3 * i * i) % 11;
}

int doubleHashing(int key, int i) {
    int h1 = key % 11;
    int h2 = 1 + (key % 10);
    return (h1 + i * h2) % 11;
}

int main(){
    OpenHash* hashTable = new OpenHash(11, quadraticProbing);
int data[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
int size = sizeof(data) / sizeof(int);

for (int i = 0; i < size; i++) {
    hashTable->insert(data[i]);
}

hashTable->dump();
}