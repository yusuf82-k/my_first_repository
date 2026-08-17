#include <iostream>
#include <vector>
#include <algorithm> // For std::max_element

using namespace std;

// Function to perform Counting Sort
void countingSort(vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // 1. Find the maximum element in the input array to determine the range of the counting array
    int max_val = *max_element(arr.begin(), arr.end());

    // 2. Initialize the Counting Array (size max_val + 1)
    // The range of keys is from 0 to max_val
    vector<int> count(max_val + 1, 0);

    // 3. Count the frequency of each element
    for (int x : arr) {
        count[x]++;
    }

    // 4. Modify the Count Array to store the running/cumulative count
    // This step helps determine the actual position of each element in the output array.
    for (int i = 1; i <= max_val; ++i) {
        count[i] += count[i - 1];
    }

    // 5. Create the output array
    // Size should be the same as the input array
    vector<int> output(arr.size());

    // 6. Build the output array from the input array
    // Iterate from the end of the input array (to ensure stability)
    for (int i = arr.size() - 1; i >= 0; --i) {
        int element = arr[i];
        // The correct position is count[element] - 1
        output[count[element] - 1] = element;
        // Decrease the count for the element
        count[element]--;
    }

    // 7. Copy the sorted elements back to the original array
    arr = output;
}

// Helper function to print the array
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {4, 2, 2, 8, 3, 3, 1};
    cout << "Original array: ";
    printArray(data);

    countingSort(data);

    cout << "Sorted array: ";
    printArray(data);

    return 0;
}