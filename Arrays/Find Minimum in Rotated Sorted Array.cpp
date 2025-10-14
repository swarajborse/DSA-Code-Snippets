class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int ans = INT_MAX;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[right]) {
                ans = min(ans, nums[left]);
                break;
            }
            ans = min(ans, nums[mid]);
            if (nums[left] <= nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};