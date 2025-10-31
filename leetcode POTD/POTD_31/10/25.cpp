class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>1){
             ans.push_back(nums[i]);
            }
        }
        return ans;
        }
};