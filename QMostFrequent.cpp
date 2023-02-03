#include <bits/stdc++.h>
using namespace std;

class comp{
    public:
        bool operator()(const pair<int,int> &a,const pair<int,int> &b){
            return a.second > b.second;
        }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> q;
        for(auto iter = mp.begin();iter!= mp.end();iter++){
            if(q.size() < k) q.push({iter->first,iter->second});
            else{
                if(q.top().second < iter->second){
                    q.pop();
                    q.push({iter->first,iter->second});
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }

int main(){
    int n,k ;
    cout<<"Enter N and K:";
    cin>>n>>k;
    // pair<int,int> *arr = new pair<int,int>[n];
    vector<int> arr(n);
    cout<<"Enter the elements :";
    for(int i =0 ;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans = topKFrequent(arr,k);
    for(int &i : ans) cout<<i<<" ";
    cout<<endl;
    return 0;
}