#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop(); 
    }
    cout<<endl;
    return;
}

void insertSorted(stack<int> &s,int ele){
    if(s.size() == 0 || s.top() <= ele) {s.push(ele);return;}
    int temp = s.top();
    s.pop();
    insertSorted(s,ele);
    s.push(temp);
}

void sortStack(stack<int> &s){
    if(s.size() == 0 || s.size() == 1) return ;
    int x = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s,x);
    return;
}

int main(){
    stack<int> s;
    int n;
    cout<<"Enter N:";
    cin>>n;
    for(int i =0 ;i<n;i++) {
        int x;cin>>x;
        s.push(x); 
    }
    cout<<"Stack Top -> ";
    print(s);
    sortStack(s);
    cout<<"Stack after Sorting : "<<endl;
    cout<<"Stack Top -> ";
    print(s);
    return 0;
    }