class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> map;
    for (int num : nums) {
        map[num] = 1; 
    }

    int maxLen = 0;

    for (int num : nums) {
        if (map[num] == 0) continue;
        int currentLen = 1;
        map[num] = 0; 
        int left = num - 1;
        while (map.count(left) && map[left] != 0) {
            map[left] = 0;
            currentLen++;
            left--;
        }
        int right = num + 1;
        while (map.count(right) && map[right] != 0) {
            map[right] = 0;
            currentLen++;
            right++;
        }
        maxLen = max(maxLen, currentLen);
    }
    return maxLen;
    }
};