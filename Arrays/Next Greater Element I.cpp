class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>store;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop(); // pop karte raho jab tak bada nhi mil jaata :)
            }
            store[nums2[i]] = st.empty() ? -1 : st.top(); // update the pointers :)
            st.push(nums2[i]);
        }
        vector<int>res;
        for(int num : nums1){
            res.push_back(store[num]); // waapis array mein bhar do
        }
        return res;
    }
};