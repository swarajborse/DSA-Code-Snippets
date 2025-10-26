#include <bits/stdc++.h>
using namespace std;

/*
Problem: Maximum Sum Subarray of size K
Pattern: Sliding Window
Description: Find the contiguous subarray of size K with the maximum sum.
Time Complexity: O(n)
Space Complexity: O(1)
Edge Cases: Handles empty array or k > array size
Visualization: https://visualgo.net/en/ssw
*/

int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0 || k > n) return 0; // Edge case handling

    int sum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];

    int maxSum = sum;
    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    cout << "Max sum of subarray of size " << k << " is " << maxSumSubarray(arr, k) << endl;

    // Edge case tests
    vector<int> emptyArr;
    cout << "Empty array test: " << maxSumSubarray(emptyArr, 2) << endl;

    vector<int> smallArr = {1};
    cout << "k > size test: " << maxSumSubarray(smallArr, 5) << endl;

    return 0;
}
