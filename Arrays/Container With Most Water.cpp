class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0 , right = n-1 , ans = 0;
        while(left<right){
            int h = min(height[left],height[right]);
            ans = max(ans , h*(right-left));
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0 , rp = height.size()-1,ans=0;
        while(lp<rp){
            int w = rp-lp;
            int ht = min(height[lp],height[rp]);
            int currWater = w*ht;
            ans = max(ans,currWater);
            height[lp]<height[rp]?lp++:rp--;
        }
        return ans;
    }
};