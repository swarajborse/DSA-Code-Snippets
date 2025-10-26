#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------
// 🔹 Function to perform Selection Sort
// -----------------------------------------------------------
// It repeatedly finds the minimum element from the unsorted
// portion of the array and places it at the beginning.
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // Move the boundary of the unsorted subarray
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the current element is the smallest

        // Find the index of the minimum element in the remaining array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }
}

// -----------------------------------------------------------
// 🔹 Main function to test selectionSort
// -----------------------------------------------------------
int main() {
    vector<int> nums = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    selectionSort(nums);

    cout << "Sorted array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
