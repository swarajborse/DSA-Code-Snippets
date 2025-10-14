class Solution {
private: 
bool canMakeit(vector<int>&arr , int m , int k , int day){
    int bouquet = 0;
    int flowers = 0;
    for(int a : arr){
        if(a <= day){
            flowers++;
            if(flowers == k) { bouquet++; flowers = 0; }
        }else{
            flowers = 0;
        }
    }
    return bouquet >= m;
}
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m>n/k) return -1; 
        int left = *min_element(bloomDay.begin(),bloomDay.end());
        int right = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(canMakeit(bloomDay,m,k,mid)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};