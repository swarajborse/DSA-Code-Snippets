class Solution {
public:
    int resCount(vector<int>& nums, int goal) {
        if(goal < 0) return 0;
        int n = nums.size();
        int subCount = 0, sum = 0;
        int l=0,r=0;
        while(r<n){
            sum += nums[r];
            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }
            subCount += r - l + 1;
            r++;
        }
        return subCount;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal){
        return resCount(nums,goal) - resCount(nums,goal-1);
    }
};