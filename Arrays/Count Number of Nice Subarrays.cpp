class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums,k)-count(nums,k-1);
    }
    int count(vector<int>&arr , int k){
        if(k < 0) return 0;
        int n = arr.size();
        int l=0,r=0;
        int subCount = 0 , ans = 0;
        while(r<n){
            if(arr[r] % 2 == 1){
                ans++;
            }
            while(ans > k){
                if(arr[l] % 2 == 1) ans--;
                l++;
            }
            subCount += r - l + 1;
            r++;
        }
        return subCount;
    }
};