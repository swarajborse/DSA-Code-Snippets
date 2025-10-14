#include<bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>res;
        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            if(res.find(diff) != res.end()) return {res[diff],i};
            res[nums[i]] = i;
        }
        return {};
    }
};