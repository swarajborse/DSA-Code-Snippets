#include <iostream>
#include <vector>
using namespace std;

// Counting Sort function
vector<int> countsort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Find the maximum element (to decide size of count array)
    int maxval = 0;
    for (int i = 0; i < n; i++)
        maxval = max(maxval, arr[i]);

    // Step 2: Create count array and initialize with 0
    vector<int> cntArr(maxval + 1, 0);

    // Step 3: Count frequency of each element
    for (int i = 0; i < n; i++)
        cntArr[arr[i]]++;

    // Step 4: Convert frequency to prefix sum
    // After this, cntArr[i] will store actual position index of element i in final sorted array
    for (int i = 1; i <= maxval; i++)
        cntArr[i] += cntArr[i - 1];

    // Step 5: Build output array (traverse backwards to make sort stable)
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[cntArr[arr[i]] - 1] = arr[i]; // correct position for arr[i]
        cntArr[arr[i]]--;                 // decrease count (move to next correct index)
    }

    return ans;
}

int main() {
    vector<int> arr = {2,5,3,0,2,3,0,3};

    // Call counting sort
    vector<int> ans = countsort(arr);

    // Print sorted array
    for (int x : ans)
        cout << x << " ";

    return 0;
}
