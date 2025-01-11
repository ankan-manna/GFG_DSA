//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
         int n=arr.size();
        int left=0,right=0;
        unordered_map<int,int>mp;
        vector<int>ans;
        while(right<n){
            mp[arr[right]]++;
            if(right-left+1==k){
                ans.push_back(mp.size());
                mp[arr[left]]--;
                if(mp[arr[left]]==0){
                    mp.erase(arr[left]);
                }
                left++;
                right++;
            }else{
                right++;
            }
        }
        return ans;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends