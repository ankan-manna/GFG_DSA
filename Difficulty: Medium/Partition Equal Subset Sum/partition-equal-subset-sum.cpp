//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  bool solve(int i,int sum,vector<int>&arr,vector<vector<int>>&dp){
      if(i<0) return sum==0?true:false;
      if(sum==0) return true;
      
      if(dp[i][sum]!=-1) return dp[i][sum];
      
   int notTake=solve(i-1,sum,arr,dp);
      
      int take=false;
      if(sum>=arr[i])
      take=solve(i-1,sum-arr[i],arr,dp);
      
      return dp[i][sum]= take||notTake;
  }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=0;
        for(auto x:arr){
            sum+=x;
        }
        if(sum%2!=0) return false;
        int n=arr.size();
     int k=sum/2;
     vector<vector<int>>dp(n,vector<int>(k+1,-1));
      return  solve(n-1,sum/2,arr,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends