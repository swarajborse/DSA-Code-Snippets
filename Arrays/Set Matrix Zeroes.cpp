/*
 * Problem: Set Matrix Zeroes
 * LeetCode #73
 *
 * Problem Statement:
 * Given an m x n matrix. If an element is 0, set its entire row and column to 0.
 * Do it in-place (try to modify the input matrix directly).
 *
 *  Approach:
 * - Step 1: Traverse the matrix and record which rows and columns contain zeros.
 * - Step 2: Using the recorded information, set those rows and columns to zero.
 *
 * Time Complexity: O(n * m)
 * Space Complexity: O(n + m)
 *
 *  Example:
 * Input:
 *  [1, 1, 1]
 *  [1, 0, 1]
 *  [1, 1, 1]
 * Output:
 *  [1, 0, 1]
 *  [0, 0, 0]
 *  [1, 0, 1]
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to set entire row and column to zero if an element is zero
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size();       // number of rows
        int m = arr[0].size();    // number of columns

        // Step 1: Create two helper arrays to mark zero rows and columns
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Step 2: Mark the rows and columns that have a zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Step 3: Update the matrix based on marked rows and columns
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    arr[i][j] = 0;
                }
            }
        }
    }
};
