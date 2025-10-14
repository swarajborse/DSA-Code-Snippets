class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        if(k==0) return 0;
        unordered_map<int,int>freq;
        for(int num : nums){
            freq[num]++;
        }
        int sum = 0;
        for(auto &p : freq){
            if(p.second % k == 0) sum += p.first*p.second;
        }
        return sum;
    }
};