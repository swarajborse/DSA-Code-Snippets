// BUBBLE SORT IMPLEMENTATION IN C++

#include <iostream>
#include <vector>  
using namespace std;

// Helper function to swap two integer values
// Uses pass-by-reference (&) to modify the original variables
void swap(int &a, int &b) {
    int temp;    // Create a temporary variable to hold one value
    temp = a;    // Store the value of 'a' in 'temp'
    a = b;       // Assign the value of 'b' to 'a'
    b = temp;    // Assign the original value of 'a' (stored in 'temp') to 'b'
}

// Function to perform Bubble Sort on a vector of integers
// Takes the vector by reference (&) to sort it in place
void bubble(vector<int> &nums) {
    int n = nums.size(); // Get the total number of elements in the vector

    // Outer loop: Controls the number of passes.
    // After 'i' passes, the last 'i' elements are already in their correct sorted position.
    for (int i = 0; i < n - 1; i++) {
        
        // Inner loop: Performs the comparisons and swaps for one pass.
        // It bubbles the largest unsorted element to its correct position.
        for (int j = 0; j < n - 1; j++) {
            
            // Compare the current element with the next element
            if (nums[j] > nums[j + 1]) {
                // If the current element is greater, swap them
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

int main() {
    // Initialize a vector with unsorted integer values
    vector<int> nums = {23, 21, 10, 22, 78, 50, 49};
    
    // Call the bubble sort function to sort the vector
    bubble(nums);
    
    // Use a range-based for loop to print each element in the sorted vector
    for (int val : nums) {
        cout << val << " "; // Print the value followed by a space
    }
    
    return 0; // Indicate successful execution
}