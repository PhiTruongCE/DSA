#ifndef VM_H
#define VM_H

#include "main.h"
enum DataType {NONE , INT , FLOAT, BOOLEN, ADDRESS};

struct GReg {
    int data1;
    float data2;
    bool data3;
    string data4;
    DataType type;
};
struct Instruction {
    string code;
    string op1;
    string op2;
};

class IntSLinkedList{
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
            throw InvalidInstruction(5);
        }
        else if(this->count == 0 || this->count == index){
            add(element);
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

    virtual bool empty() {
        return (this->count == 0);
    }

    virtual int size() {
        return this->count;//done
    }
    
    virtual int get() {
        if(this->count == 0) return 0;
        else if (this->count == 1){
            int t = tail->data;
            tail = NULL;
            head = NULL;
            this->count--;
            return t;
        }
        else{
            int t = tail->data;
            Node* tmp = head;
            for(int i = 0; i < this->count - 1 ; i++){
                tmp=tmp->next;
            }
            tail = tmp;
            this->count--;
            return t;
        }
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

class VM
{
private:
  int IP;
  GReg Reg[15];
  Instruction codeMemory[65536];
  int CodeLoadedIndex;
  IntSLinkedList stack;
public:
  VM() { 
        this->IP = 0;
        for (int i = 0; i < 15; i++) {
            Reg[i].type = NONE;
        }
    }
  void run(string filename);
  void runCode(string second);
  void Control(string instruction, int address);
  void exec();
  //calculate
  void Add(string dest, string src);
  void Minus(string dest, string src);
  void Mul(string dest, string src);
  void Div(string dest, string src);
  //tra ve true false
  void CmpEQ(string dest, string src);  //==
  void CmpNE(string dest, string src);  //!=
  void CmpLT(string dest, string src);  //<
  void CmpLE(string dest, string src);  //<=
  void CmpGT(string dest, string src);  //>
  void CmpGE(string dest, string src);  //>=
  //gan
  void Not(string dest);                //dest != dest
  void And(string dest, string src);    // dest = dest && src
  void Or(string dest, string src);     // dest = dest||src
  //read and write
  void Move(string dest, string src); 
  void Load(string dest, string src);   // dest = *src
  void Store(string dest, string src);  // *dest = src
  void Jump(string src);                // IP = src
  void JumpIf(string dest, string src); // if(dest) IP = src
  void Call(string src);
  void Return();
  void Halt();
  void Input(string dest);
  void Output(string src);

  int Text(string s);  
  int check(string s);
  bool con2bool(string s);
};
#endif