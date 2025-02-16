//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    if(s.length()%2!=0)
    return -1;
    stack<int>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{')
        st.push(s[i]);
        else{// if "}"
            if(!st.empty() && st.top()=='{')
            st.pop();//to remove balence part
            else
            st.push(s[i]);
        }
    }
    int a=0,b=0;
    while(!st.empty()){
        if(st.top()=='{')
        a++;
        else
        b++;
        st.pop();
    }
    int ans=(a+1)/2+(b+1)/2;
    return ans;
}