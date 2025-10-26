#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------------------
// 🔹 Recursive Binary Search Function (Named: binarysearch)
// -----------------------------------------------------------
// Searches for 'target' in a sorted array 'arr' between indices 'left' and 'right'.
// Returns the index of 'target' if found, otherwise returns -1.
int binarysearch(vector<int>& arr, int left, int right, int target) {
    // Base case: target not found
    if (left > right)
        return -1;

    // Calculate middle index
    int mid = left + (right - left) / 2;

    // If the element is found at mid
    if (arr[mid] == target)
        return mid;

    // If target is greater, ignore left half
    if (arr[mid] < target)
        return binarysearch(arr, mid + 1, right, target);

    // If target is smaller, ignore right half
    return binarysearch(arr, left, mid - 1, target);
}

// -----------------------------------------------------------
// 🔹 Main function to test the binarysearch function
// -----------------------------------------------------------
int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;

    int result = binarysearch(nums, 0, nums.size() - 1, target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
