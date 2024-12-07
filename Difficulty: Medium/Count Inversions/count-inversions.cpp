//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
   int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int count = 0;

    // Sizes of two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    vector<int> leftArr(n1), rightArr(n2);
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

    // Merge the two arrays and count inversions
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            count += (n1 - i); // All remaining elements in leftArr are inversions
        }
    }

    // Copy remaining elements
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];

    return count;
}

int mergeSortAndCount(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int count = 0;

    count += mergeSortAndCount(arr, left, mid);
    count += mergeSortAndCount(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);

    return count;
}

int inversionCount(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends