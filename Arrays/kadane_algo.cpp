#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubArraySum(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (size_t i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArraySum(arr) << endl;
    return 0;
}
