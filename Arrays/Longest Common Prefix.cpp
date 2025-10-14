class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = strs[0];
        int len = res.length();
        for(int i=1;i<strs.size();i++){
            string s = strs[i];
            while(len > s.length() || res != s.substr(0,len)){
                len--;
                if(len==0){
                    return "";
                }
                res = res.substr(0,len);
            }
        }
        return res;
    }
};