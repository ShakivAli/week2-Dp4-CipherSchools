#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i =0 ;i<arr.size();i++){
            if(ans.size()==0 || ans.back()[1] < arr[i][0]) ans.push_back(arr[i]);
            else ans.back()[1] = max(ans.back()[1],arr[i][1]); 
        }
        return ans;
    }

int main(){
    int n;
    cout<<"Enter number of intervals : ";
    cin>>n;
    vector<vector<int>> pairs(n);
    cout<<"Enter intervals : ";
    for(int i =0 ;i<n;i++){
        int a,b;
        cin>>a>>b;
        pairs[i] = {a,b};
    }
    pairs = merge(pairs);
    cout<<"Intervals after merging : \n";
    for(auto i : pairs){
        for(auto j : i) cout<<j<<" ";
        cout<<endl;
        }

    return 0;
    }