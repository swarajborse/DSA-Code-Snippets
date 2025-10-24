//NEXT GREATER NUMERICALLY BALANCED NUMBER(POTD)

#include <iostream>
#include <vector>    // For using the vector data structure
using namespace std;

class Solution {
public:
    /**
     * A number is beautiful if for every digit 'd' in it,
     * the digit 'd' appears 'd' times.
     * This also means a beautiful number can never contain a '0'.
     */
    bool isBeautiful(int n) {

        vector<int> freq(10, 0); // e.g., [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

        // Loop as long as 'n' has digits left
        while (n > 0) {
            int digit = n % 10; // Get the last digit (e.g., 123 -> 3)
            
            // Increment the count for that specific digit's slot
            freq[digit]++; // e.g., freq[3] becomes 1
            
            n /= 10; // Remove the last digit (e.g., 123 -> 12)
        }

        // Now, check if the counts match the "beautiful" rule
        // Loop through all possible digits, from 0 to 9
        for (int d = 0; d < 10; d++) {
            
            // This 'if' finds any digit that breaks the rule.
            // A rule is broken IF a digit 'd'
            // 1. IS present (freq[d] != 0)
            // 2. AND its count does NOT match its value (freq[d] != d)
            if (freq[d] != 0 && freq[d] != d) {
                return false; // This number is not beautiful
            }
        }
        
        // If we checked all 10 digits and none broke the rule, the number is beautiful.
        return true;
    }

    /**
     * @brief Finds the smallest "beautiful" number strictly greater than n.
     */
    int nextBeautifulNumber(int n) {
        
        // Loop starting from the number right after n.
        // 1224444 is the next beautiful number after 1,000,000,
        // so we can stop the search there (it's a problem constraint).
        for (int i = n + 1; i <= 1224444; i++) { // Use <= to include 1224444
            if (isBeautiful(i)) {
                return i; // 'i' is the first beautiful number we found, return it.
            }
        }
        
        // This is a fallback. If n=1000001, the loop will finish
        // and return the correct answer.
        return 1224444;
    }
};

// Main function to run the code
int main() {
    int n;
    cin >> n; // Get the starting number from the user
    
    Solution obj; // Create an object of the Solution class
    
    // Call the method and print the result
    cout << obj.nextBeautifulNumber(n);
    
    return 0; // Exit program
}