//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(int idx,string &s,set<string>&ans){
      if(idx==s.length()){
          ans.insert(s);
          return;
      }
      for(int i=idx;i<s.length();i++){
          swap(s[idx],s[i]);
          solve(idx+1,s,ans);
          swap(s[idx],s[i]);
      }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string>ans;
        solve(0,s,ans);
        vector<string>v;
        for(auto x:ans) v.push_back(x);
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends