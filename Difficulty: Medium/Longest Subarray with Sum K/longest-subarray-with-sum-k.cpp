class Solution {
  public:
    int longestSubarray(vector<int>& arr, int K) {
        // code here
        unordered_map<long long, int> prefixSumIndex;
    prefixSumIndex[0] = -1;  // Handle subarrays starting from index 0

    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];

        // Check if there's a subarray (ending at i) with sum K
        if (prefixSumIndex.find(sum - K) != prefixSumIndex.end()) {
            int len = i - prefixSumIndex[sum - K];
            maxLen = max(maxLen, len);
        }

        // Store the first occurrence of the prefix sum
        if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
            prefixSumIndex[sum] = i;
        }
    }

    return maxLen;
    }
};