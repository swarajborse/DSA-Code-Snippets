class Solution {
private:
bool isPossible(vector<int>&arr , int mid , int k){
    int countSubarray = 1;
    int currentSum = 0;
    for(int a : arr){
        if(currentSum + a > mid){
            countSubarray++;
            currentSum = a;
        }else{
            currentSum += a;
        }
    }
    return countSubarray <= k;
}
public:
    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(arr,mid,k)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};