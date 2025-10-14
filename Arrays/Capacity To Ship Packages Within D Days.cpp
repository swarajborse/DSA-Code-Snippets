class Solution {
private: 
bool canShip(vector<int>&arr , int days , int k){
    int daysNeeded = 1 , currentWeight = 0;
    for(int i=0;i<arr.size();i++){
        if(currentWeight + arr[i] > k ){
            daysNeeded++;
            currentWeight = 0;
        }
        currentWeight += arr[i];
    }
    return daysNeeded <= days;
}
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int minCapacity = *max_element(arr.begin(),arr.end());
        int maxCapacity = accumulate(arr.begin(),arr.end(),0);
        while(minCapacity <= maxCapacity){
            int mid = minCapacity + (maxCapacity-minCapacity)/2;
            if(canShip(arr,days,mid)){
                maxCapacity = mid;
            }else{
                minCapacity = mid + 1;
            }
        }
        return minCapacity;
    }
};