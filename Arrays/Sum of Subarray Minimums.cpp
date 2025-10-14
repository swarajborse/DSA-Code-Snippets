class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> NSE(vector<int>&arr){
        int n = arr.size();
        vector<int>res(n);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()] > arr[i]) s.pop();
            res[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return res;
    }

    vector<int> PSEE(vector<int>&arr){
        int n = arr.size();
        vector<int>res(n);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            res[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = NSE(arr);
        vector<int> psee = PSEE(arr);

        long long total = 0 ; // overflow kar sakta hai asfaik
        for(int i=0;i<n;i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;

            total = (total + (left * right % MOD) * arr[i]) % MOD;
        }
        return (int)total;
    }
};