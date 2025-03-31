//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>
class Solution {
  public:
    string decodedString(string &s) {
        // code here
      /*  int n=s.length()-1;
        stack<int>st;
        string str="";
        string prev="";
        for(int i=n;i>=0;i--){
            
            if(!isdigit(s[i]) && s[i]!='['){
            st.push(s[i]);
            }
            else if(s[i]=='[')
            {
                while(!st.empty() && st.top()!=']'){
                    str+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(isdigit(s[i])){
               // int x=stoi(s[i]);
                int x = stoi(string(1, s[i]));  // ✅ Convert char to string
                str=str+prev;
                string temp=str;
                while(--x>0){
                    str=str+temp;
                }
                 prev=str;
                    str="";
            }
        }
        return prev;*/
        
        //----------------------------------------------------
        stack<string> st;  // Stores both numbers & substrings
        string curr = "";  // Holds the current string being processed
        string numStr = "";  // Stores the current number as a string

        for (char ch : s) {
            if (isdigit(ch)) {
                numStr += ch;  // Build multi-digit number
            } 
            else if (ch == '[') {
                // Push number & reset it
                st.push(numStr);
                numStr = "";

                // Push current substring & reset it
                st.push(curr);
                curr = "";
            } 
            else if (ch == ']') {
                // Decode the last substring
                string prevStr = st.top();  // Previous part before '['
                st.pop();

                int repeatTimes = stoi(st.top());  // Get the number
                st.pop();

                string temp = curr;
                for (int i = 1; i < repeatTimes; i++) {
                    curr += temp;  // Repeat the substring
                }

                curr = prevStr + curr;  // Append decoded string to previous
            } 
            else {
                curr += ch;  // Append character
            }
        }
        return curr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends