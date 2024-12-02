//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        // code here
         vector<int> indices;
        size_t pos = txt.find(pat); // Start searching for the pattern

        while (pos != string::npos) { // Until no more matches are found
        indices.push_back(pos);        // Store the position
        pos = txt.find(pat, pos + 1);  // Search for the next occurrence
        }

        return indices;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends