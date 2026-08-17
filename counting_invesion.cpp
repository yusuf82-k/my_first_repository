#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index for to be sorted subarray
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // Crucial Step: If arr[i] > arr[j], then there are (mid - i + 1)
            // inversions because all elements from arr[i] to arr[mid] are greater than arr[j].
            inv_count += (mid - i + 1);
        }
    }

    // Copy the remaining elements of left subarray
    while (i <= mid) temp[k++] = arr[i++];

    // Copy the remaining elements of right subarray
    while (j <= right) temp[k++] = arr[j++];

    // Copy back to the original array
    for (i = left; i <= right; i++) arr[i] = temp[i];

    return inv_count;
}

long long mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    vector<int> arr = {8, 4, 2, 1};
    vector<int> temp(arr.size());
    
    long long total_inversions = mergeSortAndCount(arr, temp, 0, arr.size() - 1);
    cout << "Total Inversions: " << total_inversions << "\n"; // Output: 6
    return 0;
}