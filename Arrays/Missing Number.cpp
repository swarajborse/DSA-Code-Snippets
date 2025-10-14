class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int c=0,c1=0;
        for(int i=0;i<nums.size();i++){
            c+=nums[i];
            c1+=i;
        }
        c1 += nums.size();
        return abs(c1-c);
    }
};