#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(float arr[], int n) {
    vector<float> buckets[n];
    for(int i = 0; i < n; i++) {
        int bi = n * arr[i];
        buckets[bi].push_back(arr[i]);
    }
    for(int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    float arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    bucketSort(arr, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
