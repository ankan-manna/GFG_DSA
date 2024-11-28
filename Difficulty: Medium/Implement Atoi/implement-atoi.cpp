//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
         bool isNegative=false;
    bool firstZero=true;
    string temp;
    while(*s==' '){
        s++;
    }
    if (*s=='-'){
        isNegative=true;
        s++;
    }else if(*s == '+'){
            s++;
    }
    while(*s!='\0'){
        if(*s>='0' && *s<='9'){
            if(firstZero && *s=='0'){
                s++;
            } 
            else{
                firstZero=false;
                temp.push_back(*s);
                s++;
            }
        } 
        else{
           break;
        }
    }
    long long ans=0;
    long long mul=1;
    for (int i=temp.length()-1;i>=0;i--) {
        ans+=(temp[i]-'0')*mul;
        mul*=10;
    
        if (isNegative && -ans < INT_MIN) return INT_MIN;
        if (!isNegative && ans > INT_MAX) return INT_MAX;
    }
    
    if (isNegative) ans= -ans;
    
    if (ans > INT_MAX) return INT_MAX;
    if (ans < INT_MIN) return INT_MIN;
    
    return (int)ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends