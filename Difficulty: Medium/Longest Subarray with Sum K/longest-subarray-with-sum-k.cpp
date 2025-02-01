//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<int,int>m;
        int sum=0,len=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k){
                len=max(len,i+1);
            }
            int rem=sum-k;
            if(m.find(rem)!=m.end()){
                int l=i-m[rem];
                len=max(l,len);
            }
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
        }
        return len;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends