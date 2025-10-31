class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {

        // Hash map to store frequency of each number
        unordered_map<int,int> freq;

        int n = nums.size();  // Size of input array
        vector<int> ans;      // To store numbers that appear more than once

        // Loop through each element in the array
        for(int i = 0; i < n; i++){
            
            freq[nums[i]]++;  // Increase frequency count of current number
            
            // If this number appears more than once, it is sneaky (duplicate)
            if(freq[nums[i]] > 1){
                ans.push_back(nums[i]);
            }
        }

        return ans;  // Return list of sneaky (duplicate) numbers
    }
};
