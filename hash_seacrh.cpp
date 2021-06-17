#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    if(right >= left){
        int k = left + (right - left)/2;
        cout << "We traverse on index: " << k << endl;
        if(arr[k] == x) return k;
        else{
            if(arr[k] < x)
                return binarySearch(arr, k + 1, right, x);
            else return binarySearch(arr, left, k - 1, x);
        }
    }
    else return -1;
}

int jumpSearch(int arr[], int x, int n) {
    int step = sqrt(n);
    int index = 0;
    cout<<index<<" ";
    while(index < n && arr[index] < x){
        if (index + step < n){          
            index += step;
            cout << index << " ";
        }
        else
        {
            step = sqrt(step);
            index+=step;
            //cout << index << " ";
        }
    }
    if (arr[index] == x)
    {
        return index;
    }
    else if (index > n -1) return -1;
    index -= step;
    index++;
    while(arr[index] <= x){
        cout<<index << " ";
        if(arr[index] == x) return index;
        index++;
    }
    return -1;
}

int interpolationSearch(int arr[], int left, int right, int x){
    if(left <= right && arr[left] <= x && arr[right] >= x){
        if (right-left == 0)
        {   
            if (arr[left] == x) return left;
            return -1;
        }
        int pos = left + (x - arr[left])*(right - left)/(arr[right] - arr[left]);
        if(pos >=0 && pos <= right){
            if(arr[pos] == x){
            cout << "We traverse on index: " << pos << endl;
            return pos;
        }
        else if(arr[pos] > x) return interpolationSearch(arr, left, pos - 1, x);
        else return interpolationSearch(arr, pos + 1, right, x);
        }
        else return -1;
    }
    return -1;
}

bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
   // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
        map<int, pair<int, int>> Hash;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (Hash.find(sum) == Hash.end()) 
            {
                Hash[sum] = make_pair(i, j);
            }
            else {
                pair<int, int> pp = Hash[sum];
                pair1.first = arr[pp.first];
                pair1.second = arr[pp.second];
                pair2.first = arr[i];
                pair2.second = arr[j];
                return true;
            }
        }
    }
    return false;
}

long int midSquare(long int seed)
{
    seed = pow(seed,2);
    seed/=100;
    return (seed%10000);
}
long int moduloDivision(long int seed, long int mod)
{
    return (seed%mod);
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{
    string str = to_string(seed);
    long int res = 0;
    for(int i = 0; i < size; i ++){
        long int k = str[extractDigits[i]] - 48;
        res = (res + k)*10;
    }
    return res/10;
}

int foldShift(long long key, int addressSize)
{
    int res = 0;
    int n = 1;
    for(int i = 0; i < addressSize; i++){
        n = n*10;
    }
    while(key>0){
        res += key%n;
        key /= n;
    }
    return (res%n);
}

int rotation(long long key, int addressSize)
{
    int n = 0;
    long long key2 = key;
    while(key2>0){
        key2/=10;
        n++;
    }
    int temp = key % 10;
    key /= 10;
    long long res = key + temp*pow(10,n-1);
    return foldShift(res,addressSize);
}

int main(){
    cout << rotation(891902600101, 2);
}
