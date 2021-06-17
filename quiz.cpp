#include <iostream>
#include <string.h>
using namespace std;

/*bool isPalindrome(string str) 
{ 
    int length = str.length();
    if(length<=1) return true;
    if(str[0] != str[length-1]){
        return false;
    }
    string middle = str.substr(1,length - 2);
    return isPalindrome(middle);
}
*/
/*void printHailstone(int number)
{
    if(number==1){
        cout<<1;
    }
    else{
        if(number%2==0){
            cout<<number<<" ";
            printHailstone(number/2);
        }
        else{
            cout<<number<<" ";
            printHailstone(number*3+1);
        }
    }
}*/
/*int findMax(int* arr, int length)
{
    if(length == 1) return arr[0];
    int max = findMax(arr + 1, length -1);
    if(arr[0]> max) return arr[0];
    else return max;
}*/
/*int decimalToBinary(int decimal_number) 
{ 
    if(decimal_number <=1) return decimal_number;
    else return (decimal_number%2) + 10*decimalToBinary(decimal_number/2);
}*/

/*void printArray(int n)
{
    if(n == 0){
        cout<<n;
    }
    else{
        printArray(n-1);
        cout<<", "<<n;
    }
}*/

/*int findGCD(int a, int b)
{
    if(a==0) return b;
    if(b==0) return a;
    else return findGCD(b,a%=b); 
}

int findLCM(int a, int b)
{
    return (a/findGCD(a,b))*b;
}*/

/*int strLen(char* str)     
{ 
    if(*str == '\0') return 0;
    else return 1 + strLen(str + 1);
}*/
/*
bool containsPattern(char* text, char* pattern)
{
    if(*pattern == '\0') return true;
    else{
        if(mbrlen(pattern)>mbrlen(text)) return false;
        else{
            if(pattern[0] != text[0]) return containsPattern(text+1,pattern);
            else return containsPattern(text+1,pattern+1);
        }
    }
}
*/
void printPattern(int n) 
{ 
    int static i = (n % 2) + 1; 
    if(n > 0){
        cout<<n<<" ";
        printPattern(n-5);
    }
    else printPatern(n+5, i); 
}
void printPatern(int n,int i){
    if (i == 0) {
        cout<<n;
    }
    else{
        cout<<n<<" ";
        printPatern(n+5,i-1);
    }
}
int main(){
    printPattern(14);
    return 0;
}