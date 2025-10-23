// Insertion sort

#include <iostream> // For input (cin) and output (cout) operations
#include <vector>   // For using the std::vector container
using namespace std;

// Function to perform insertion sort on a vector
// The vector is passed by reference (&) so the original vector is modified (sorted)
void insertion(vector<int>& arr) {
    int n = arr.size(); // Get the number of elements in the vector

    // Start the loop from the second element (index 1)
    // The first element (index 0) is treated as the "sorted" portion
    for (int i = 1; i < n; i++) {
        
        // 'key' is the current element we want to insert into the sorted portion
        int key = arr[i]; 
        
        // 'j' is the index of the last element in the sorted portion
        int j = i - 1; 

        // The 'while' loop finds the correct position for 'key' in the sorted part [0...i-1]
        // It shifts all elements greater than 'key' one position to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift the larger element to the right
            j--; // Move 'j' to the left to check the next element
        }
        
        // After the loop, 'j+1' is the correct position for 'key'
        // 'j' is either -1 or points to an element <= 'key'
        arr[j + 1] = key; 
    }
}

int main() {
    // Create an unsorted vector of integers
    vector<int> nums = {23, 21, 10, 22, 78, 50, 49};
    
    // Call the insertion sort function to sort the vector
    insertion(nums);
    
    // Print the sorted vector
    // This is a range-based for loop, a modern C++ way to iterate over a container
    for (int val : nums) {
        cout << val << " ";
    }
    
    return 0; // Indicate successful execution
}