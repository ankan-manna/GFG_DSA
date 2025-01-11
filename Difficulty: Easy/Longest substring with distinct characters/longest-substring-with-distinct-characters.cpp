//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
         int n=s.size();
       int ans=0;
       
       for(int i=0;i<n;i++){
          int j=i;
          unordered_set<int> st;
          while(j<n){
              if(st.find(s[j])!=st.end())
              break;
              st.insert(s[j]);
              int mm=st.size();
              ans=max(ans,mm);
              j++;
          }
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends