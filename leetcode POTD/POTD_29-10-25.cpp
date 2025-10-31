class Solution {
public:
    int smallestNumber(int n) {

        int count = 0;
        // Count how many times we can divide n by 2
        // (This basically finds the number of bits needed to represent n)
        while(n > 0){
            n = n / 2;
            count++;
        }

        int ans = 1;
        int i = 1;

        // Calculate 2^count
        while(i <= count){
            ans = ans * 2;
            i++;
        }

        // Subtract 1 to get the smallest number with 'count' bits all set to 1
        // Example: if count = 3 -> 2^3 = 8; 8 - 1 = 7 (binary 111)
        ans = ans - 1;

        return ans;
    }
};
