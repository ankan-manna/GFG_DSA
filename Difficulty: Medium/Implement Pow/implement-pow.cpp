//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    double powerExp(double a,long e){
        if(e==0) return 1;
        if(e%2==0){
            return powerExp(a*a,e/2);
        }else{
            return a*powerExp(a*a,e/2);
            //2^7=>2*2^3*2^3
        }
    }
  public:
    double power(double b, int e) {
        // code here
        double ans=1.0;
        if(e<0){
            long ex=static_cast<long>(e);
            ex=-1*ex;
           ans= powerExp(b,ex);
            return 1.0/ans;
        }else{
           ans= powerExp(b,e);
           return ans;
        }
    }
};


//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends