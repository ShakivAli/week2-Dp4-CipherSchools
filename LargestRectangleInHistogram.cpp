#include<bits/stdc++.h>
using namespace std;

vector<int> prev(vector<int> &arr){
        stack<int> s;
        s.push(-1);
        int n = arr.size();
        vector<int> ans(n);
        for(int i =0;i<n;i++){
            while(s.top() != -1 && arr[s.top()] >= arr[i]) s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
vector<int> next(vector<int> &arr){
        stack<int> s;
        s.push(-1);
        int n = arr.size();
        vector<int> ans(n);
        for(int i =n-1;i>=0;i--){
            while(s.top() != -1 && arr[s.top()] >= arr[i]) s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
int largestRectangleArea(vector<int>& heights) {
        vector<int> prevSmaller = prev(heights);   
        vector<int> nextSmaller = next(heights);   
        int ans = 0;
        int n = heights.size();
        for(int i = 0;i<n;i++){
            // int p = prevSmaller[i];
            // int ne = nextSmaller[i];
            if(nextSmaller[i] == -1) nextSmaller[i] = n;
            int breadth = nextSmaller[i] - prevSmaller[i] - 1;
            int length =  heights[i];
            ans = max(ans , length * breadth);
        }
        return ans;
    }


int main(){
    int n;
    cout<<"Enter N:";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter values:";
    for(int i =0  ;i<n;i++) cin>>arr[i];
    cout<<"The largest area of a rectangle in the histogram is : "<<largestRectangleArea(arr);
    return 0;
    }