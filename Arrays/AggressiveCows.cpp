class Solution {
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int low = 0;
        int high = *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());
        int ans = low;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int count = 1;
            int prev = arr[0];
            for(int i=1;i<n;i++)
            {
                if(arr[i] - prev >= mid)
                {
                    count++;
                    prev = arr[i];
                }
            }
            if(count>=k)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
