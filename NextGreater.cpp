#include<bits/stdc++.h>
using namespace std;


vector<int> solve(int *arr,int n){
    vector<int> ans(n);
    stack<int> s;
    for(int i = n -1;i>=0;i--){
        while(!s.empty() && arr[s.top()] <= arr[i]) s.pop();
        if(s.empty()) ans[i] = -1;
        else ans[i] = arr[s.top()];
        s.push(i);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter N:";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter elemets :";
    for(int i=0 ;i<n;i++) cin>>arr[i];
    vector<int> ans = solve(arr,n);
    for(int i : ans) cout<<i<<" ";
    cout<<endl;
    return 0;
    }