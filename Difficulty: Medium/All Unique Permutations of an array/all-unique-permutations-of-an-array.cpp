//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void solve(vector<int>&arr,int n,set<vector<int>>&ans,int st){
      if(st>=n){
          ans.insert(arr);
          return;
      }
      for(int i=st;i<n;i++){
          swap(arr[st],arr[i]);
          solve(arr,n,ans,st+1);
          swap(arr[st],arr[i]);
      }
  }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>>v;
        set<vector<int>>ans;
        solve(arr,n,ans,0);
        for(auto i:ans){
            v.push_back(i);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends