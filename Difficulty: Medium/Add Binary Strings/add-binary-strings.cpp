//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
         string ans="";
        int n1=s1.size();
        int n2=s2.size();
        int i=n1-1,j=n2-1;
        int carry=0;
        while(i>=0 || j>=0 || carry){
            int dig1=(i>=0)?s1[i]-'0':0;
            int dig2=(j>=0)?s2[j]-'0':0;
            int dig=dig1+dig2+carry;
            ans=to_string(dig%2)+ans;
            
            carry=dig/2;
            i--,j--;
        }
        if(ans[0]=='0'){
            i=0;
            while(ans[i]=='0')i++;
            ans=ans.substr(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends