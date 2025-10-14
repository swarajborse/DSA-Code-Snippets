class Solution {
public:
    vector<int> NSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            res[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return res;
    }

    vector<int> PSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            res[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return res;
    }

    long long subMin(vector<int>& arr) {
        long long total = 0;
        int n = arr.size();
        vector<int> nse = NSE(arr);
        vector<int> psee = PSEE(arr);
        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total += left * right * 1LL * arr[i];
        }
        return total;
    }

    vector<int> NGE(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] < arr[i]) s.pop();
            res[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return res;
    }

    vector<int> PGEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();
            res[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return res;
    }

    long long subMax(vector<int>& arr) {
        long long total = 0;
        int n = arr.size();
        vector<int> nge = NGE(arr);
        vector<int> pgee = PGEE(arr);
        for (int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            total += left * right * 1LL * arr[i];
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long minSum = subMin(nums);
        long long maxSum = subMax(nums);
        return maxSum - minSum;
    }
};
