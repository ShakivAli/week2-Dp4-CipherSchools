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
void IAB(stack<int> &s,int x){
    if(s.size() == 0){
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    IAB(s,x);
    s.push(temp);
    return;
}


void reverseStack(stack<int> &stack) {
    if(stack.empty()) return;
    int x= stack.top();
    stack.pop();
    reverseStack(stack);
    IAB(stack,x);
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
    reverseStack(s);
    cout<<"Stack after Reversing : "<<endl;
    cout<<"Stack Top -> ";
    print(s);
    return 0;
    }