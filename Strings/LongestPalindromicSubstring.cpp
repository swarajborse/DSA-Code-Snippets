#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(const string &s) {
    int n = s.size(), start = 0, len = 1;

    // Expand around every possible center
    for (int i = 0; i < n; i++) {
        // Odd-length palindrome (center at i)
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > len) start = l, len = r - l + 1;
            l--; r++;
        }

        // Even-length palindrome (center between i and i+1)
        l = i; r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > len) start = l, len = r - l + 1;
            l--; r++;
        }
    }

    // Return the longest found substring
    return s.substr(start, len);
}
