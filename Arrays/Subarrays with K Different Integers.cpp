class Solution {
public:
    int func(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0 , r = 0 , maxCount = 0;
        unordered_map<int,int>mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            maxCount += r - l + 1;
            r++;
        }
        return maxCount;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k){
        return func(nums,k) - func(nums,k-1);
    }
};