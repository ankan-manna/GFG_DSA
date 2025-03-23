//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(string &digits,int idx,vector<int>&dp){
        if(idx==digits.size()){
            return 1;
        }
        if(digits[idx]=='0'){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        if(digits[idx]>='3'){
            return dp[idx]=solve(digits,idx+1,dp);
        }
        else{
            int single = solve(digits,idx+1,dp);
            if(idx+1<digits.size()){
                if(digits[idx]=='2' && digits[idx+1]>'6'){
                    return dp[idx]=single;
                }
                else{
                    int two = solve(digits,idx+2,dp);
                    return dp[idx]=single+two;
                }
            }
            return dp[idx]=single;
        }
    }
    int countWays(string &digits) {
        // Code here
        vector<int>dp(digits.size()+1,-1);
        return solve(digits,0,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends