class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int l = 0 , r = 0 , zeroCount = 0;
        while(r<nums.size()){
            if(nums[r] == 0 ) zeroCount++;
            if(zeroCount > k){
                if(nums[l] == 0) zeroCount--;
                l++;
            }
            if(zeroCount <= k){
                int len = r-l+1;
                maxLen = max(maxLen,len);
            }
            r++;
        }
        return maxLen;
    }
};