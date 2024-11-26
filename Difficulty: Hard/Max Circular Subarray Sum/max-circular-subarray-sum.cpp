//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
         int n = arr.size();
        
        int maxSum = INT_MIN, minSum = INT_MAX;
        int currMaxSum = 0, currMinSum = 0;
        
        int totalSum = 0;
        
        for(int i = 0; i < n; ++i){
            totalSum += arr[i];
            
            currMaxSum += arr[i];
            maxSum = max(maxSum, currMaxSum);
            if(currMaxSum < 0) currMaxSum = 0;
            
            currMinSum += arr[i];
            minSum = min(minSum, currMinSum);
            if(currMinSum > 0) currMinSum = 0;
        }
        
        return max(maxSum, totalSum - minSum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends