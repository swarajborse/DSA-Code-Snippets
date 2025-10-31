// C++ program for implementation of Heap Sort
#include <iostream>
#include <vector>
// Include algorithm for std::swap
#include <algorithm> 

using namespace std;

// To heapify a subtree rooted with node i
// n is size of heap
void heapify(vector<int>& arr, int n, int i) {

    // Initialize largest as root
    int largest = i;

    // left index = 2*i + 1
    int l = 2 * i + 1;

    // right index = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        // Swap the root (i) with the largest element
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        // This ensures the max-heap property is maintained
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap (rearrange vector)
    // Start from the last non-leaf node and go up to the root
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {

        // Move current root (max element) to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        // n is now 'i', and we start from the root (0)
        heapify(arr, i, 0);
    }
}

// Driver code
int main() {
    // Initialize the vector to be sorted
    vector<int> arr = { 9, 4, 3, 8, 10, 2, 5 };

    // Perform heap sort
    heapSort(arr);

    // Print the sorted vector
    cout << "Sorted array is \n";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}