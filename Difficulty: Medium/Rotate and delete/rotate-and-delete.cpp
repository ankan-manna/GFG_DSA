//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
      int rotateDelete(vector<int> &arr) {
        // Your code here
        int k = 1;
        int n = arr.size();
        while(k < n){
            
            arr.insert(arr.begin(),arr[n-1]);
            arr.erase(arr.begin() + (n));
            arr.erase(arr.begin() + (n - k));
            k++;
            n--;
            
        }
        
        while(n > 1){
            arr.erase(arr.begin() + (n-1));
            n--;
        }
        return arr[0];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends