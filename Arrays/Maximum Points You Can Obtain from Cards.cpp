class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = accumulate(cardPoints.begin(),cardPoints.begin() + k ,0);
        int rsum = 0;
        int maxSum = lsum;
        int rightIndex = cardPoints.size() - 1;
        for(int i = k-1; i >=0 ;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rightIndex];
            rightIndex--;
            maxSum = max(maxSum, lsum + rsum);
        }
        return maxSum;
    }
};