class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        findPermutations(0,nums,ans);
        return ans;
    }
    void findPermutations(int index, vector<int>& arr, vector<vector<int>>& ans){
        if(index == arr.size()){
            ans.push_back(arr);
            return;
        }
        unordered_set<int>used;
        for(int i=index;i<arr.size();i++){
            if (used.count(arr[i])) continue;
            used.insert(arr[i]);
            swap(arr[index],arr[i]);
            findPermutations(index+1,arr,ans);
            swap(arr[index],arr[i]);
        }
    }
};