//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
         int zero=0, one=arr.size()-1;
        while(zero < one)
        {
            if(arr[zero]==0) zero++;
            else if(arr[one]!=0) one--;
            else { arr[one]=arr[zero]; arr[zero]=0;};
        }
        /* Place 1s */
        one = arr.size()-1;
        while(zero < one)
        {
            if(arr[zero]==1) zero++;
            else if(arr[one]!=1) one--;
            else { arr[one]=arr[zero]; arr[zero]=1;};
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends