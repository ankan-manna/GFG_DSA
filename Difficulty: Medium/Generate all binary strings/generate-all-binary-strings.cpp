//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
void solve(int n,string str,vector<string>&ans){
    if(n<0){
        ans.push_back(str);
        return;
    }
    str[n]='0';
    solve(n-1,str,ans);
    str[n]='1';
    solve(n-2,str,ans);
    
}
    vector<string> generateBinaryStrings(int num){
        //Write your code
       string str="";
       int n=num;
       while(n--){
           str+='0';
       }
      // cout<<"my"<<str;
        vector<string>ans;
        solve(num-1,str,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends