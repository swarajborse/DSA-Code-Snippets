class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        backtrack(0,nums,ans);
        return ans;
    }
    void backtrack(int index,vector<int>& arr, vector<vector<int>>& ans){
        if(index == arr.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=index;i<arr.size();i++){
            swap(arr[index],arr[i]);
            backtrack(index+1,arr,ans);
            swap(arr[index],arr[i]);
        }
    }
};