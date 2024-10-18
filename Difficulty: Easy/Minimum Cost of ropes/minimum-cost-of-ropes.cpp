//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        int s=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<s;i++){
            pq.push(arr[i]);
        }
        long long sum=0;
        while(pq.size()>1){
            int fst=pq.top();
            pq.pop();
            int snd=pq.top();
            pq.pop();
            sum+=fst+snd;
           // pq.push(sum); -->carefully
           pq.push(fst+snd);
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends