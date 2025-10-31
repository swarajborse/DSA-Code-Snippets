class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> freq(121, 0);
        for(int age : ages) freq[age]++;
        
        vector<int> prefix(121, 0);
        for(int i = 1; i <= 120; i++)
            prefix[i] = prefix[i-1] + freq[i];
        
        int ans = 0;
        for(int age = 15; age <= 120; age++) {
            if(freq[age] == 0) continue;
            
            int minAge = 0.5 * age + 7;
            int maxAge = age;
            
            int totalInRange = prefix[maxAge] - prefix[minAge];
            ans += freq[age] * totalInRange - freq[age]; // subtract self
        }
        
        return ans;
    }
};
