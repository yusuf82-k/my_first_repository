#include <iostream>
#include <vector>
#include <algorithm> // For std::min_element and std::max_element

using namespace std;

/**
 * Performs Counting Sort using an offset (the minimum element)
 * to reduce the size of the auxiliary count array.
 * This implementation is STABLE.
 */
void countingSortRangeReduced(vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // 1. Find the Minimum and Maximum elements
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());

    // 2. Calculate the Range (k)
    // The range determines the size of the count array.
    int range = max_val - min_val + 1;
    // The offset is min_val.

    // 3. Initialize the Count Array (size 'range')
    // O(k) space complexity
    vector<int> count(range, 0);

    // 4. Count the frequency of each element
    // The index for the count array is (element - min_val)
    for (int x : arr) {
        count[x - min_val]++;
    }

    // 5. Modify the Count Array to store the running/cumulative count (for stability)
    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    // 6. Create the output array (O(n) space complexity)
    vector<int> output(arr.size());

    // 7. Build the output array from the input array (Iterate backward for stability)
    for (int i = arr.size() - 1; i >= 0; --i) {
        int element = arr[i];
        int count_index = element - min_val;

        // The correct position is count[count_index] - 1
        int output_position = count[count_index] - 1;
        
        output[output_position] = element;
        
        // Decrease the count
        count[count_index]--;
    }

    // 8. Copy the sorted elements back to the original array
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
    // Example with large values but a small range (k)
    vector<int> data = {1005, 1002, 1000, 1005, 1003, 1002};
    cout << "Original array: ";
    printArray(data);

    countingSortRangeReduced(data);

    cout << "Sorted array (Range-Reduced): ";
    printArray(data);

    return 0;
}