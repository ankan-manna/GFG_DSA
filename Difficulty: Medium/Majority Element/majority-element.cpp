//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {

        // moore,s voting algo
        int ele;
        int c=0;
        for(int i=0;i<arr.size();i++){
            if(c==0){
                ele=arr[i];
            }
            if(arr[i]==ele){
                c++;
            }else{
                c--;
            }
        }
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==ele)
            cnt++;
        }
        if(cnt>arr.size()/2)
         return ele;
         else
         return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends