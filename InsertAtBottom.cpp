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
    cout<<"Enter the element to insert at bottom: ";
    int key ;
    cin>>key;
    IAB(s,key);
    print(s);
    return 0;
    }