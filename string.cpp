#include <iostream>
#include <string.h>
#include<iterator>
#include <vector>
#include <sstream>
#include <assert.h> 
#include <stack>
#include <stdlib.h>
#include <sstream>
using namespace std;

string removeDuplicates(string S){
    /*TODO*/
    string result;
    stack<string> a;
    for(int i=0; i < (int)S.length() ;i++ ){
        a.push(S.substr(i,1));
    }
    stack<string> b;
    while((int)a.size()!=0){
        if((int)a.size()!=0 && (int)b.size()==0){
            b.push(a.top());
            a.pop();
        }
        else if ((int)a.size()!=0 && (int)b.size()!=0){
            if(a.top() == b.top()){
                a.pop();
                b.pop();
            }
            else{
                b.push(a.top());
                a.pop();
            }
        }
        else break;
    }
    while ((int)b.size()!=0){
        result.append(b.top());
        b.pop();
    }
    return result;     
}
bool isValidParentheses (string s){
    stack<char> a;
    for(int i = 0; s[i]; i++){
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            a.push(s[i]);
        }
        if(a.empty() == 1) return 0;
        switch (s[i])
        {
        case '}':
            {
                if(a.top() == '(' || a.top() == '[') return 0;
                else a.pop();
                break;
            }
        case ')':
            {
                if(a.top() == '{' || a.top() == '[') return 0;
                else a.pop();
                break;
            }
        case ']':
            {
                if(a.top() == '(' || a.top() == '{') return 0;
                else a.pop();
                break;
            }    
        }
    }
    if (a.empty()){
        return 1;
    }
    else return 0;
}

int baseballScore(string ops){
    stack<int> a;
    for(int i=0; ops[i]; i++){
        if(ops[i] == 'C'){
            a.pop();
        }
        else if(ops[i] == 'D'){
            a.push(a.top()*2);
        }
        else if(ops[i] == '+'){
            int t = a.top();
            a.pop();
            int k = a.top() + t;
            a.push(t);
            a.push(k);
        }
        else{
            if(ops[i] == '1'){
                a.push(1);
            }
            else if(ops[i] == '2'){
                a.push(2);
            }
            else if(ops[i] == '3'){
                a.push(3);
            }
            else if(ops[i] == '4'){
                a.push(4);
            }
            else if(ops[i] == '5'){
                a.push(5);
            }
            else if(ops[i] == '6'){
                a.push(6);
            }
            else if(ops[i] == '7'){
                a.push(7);
            }
            else if(ops[i] == '8'){
                a.push(8);
            }
            else if(ops[i] == '9'){
                a.push(9);
            }
        }
    }
    int result = 0;
    while (!a.empty())
    {
        result += a.top();
        a.pop();
    }
    return result;
}
int trap(vector<int>& height) {
    for(int i = 0; i<height.size();i++){
        cout<<height[i]<<endl;
    }
    return 0;
}
int main(){
    vector<int> x;
    x.push_back(1);
    x.push_back(0);
    x.push_back(2);
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    cout << trap(x);
}