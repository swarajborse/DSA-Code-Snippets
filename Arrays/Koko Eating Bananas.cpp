class Solution {
private: 
bool canFinish(vector<int>&arr , int h , int k){
    long long hours = 0;
    for(int a : arr){
        hours += (a+k-1)/k;
    }
    return hours <= h;
}
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(),piles.end());
        int left = 1;
        while(left<right){
            int mid = left+(right-left)/2;
            if(canFinish(piles,h,mid)) right = mid;
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};