#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------------------------------
// Function: heapify()
// Purpose : To maintain the max-heap property for a subtree rooted at index i
// Parameters:
//   - arr : the heap/array
//   - n   : current size of the heap
//   - i   : index of the root of the subtree
// -----------------------------------------------------------------------------
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;          // Assume the current node (i) is the largest
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // If the left child exists and is greater than the current largest
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child exists and is greater than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest element is not the parent node
    // Swap it with the larger child and recursively heapify the affected subtree
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// -----------------------------------------------------------------------------
// Function: insertHeap()
// Purpose : Insert a new element into the heap and maintain heap property
// -----------------------------------------------------------------------------
void insertHeap(vector<int>& heap, int value) {
    heap.push_back(value); // Step 1: Insert new element at the end (bottom-most, right-most)
    int i = heap.size() - 1; // Index of the newly inserted element

    // Step 2: "Percolate up" or "bubble up" to restore heap property
    while (i > 0) {
        int parent = (i - 1) / 2; // Find parent index

        // If parent is smaller than the child in a max heap → swap them
        if (heap[parent] < heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent; // Move up to parent's position
        } else break; // Stop when heap property is satisfied
    }
}

// -----------------------------------------------------------------------------
// Function: extractMax()
// Purpose : Remove and return the maximum element (root) from the heap
// -----------------------------------------------------------------------------
int extractMax(vector<int>& heap) {
    if (heap.empty()) { // Handle empty heap
        cout << "Heap is empty!\n";
        return -1;
    }

    int maxVal = heap[0];          // The root is the maximum element
    heap[0] = heap.back();         // Move last element to root
    heap.pop_back();               // Remove the last element
    heapify(heap, heap.size(), 0); // Restore heap property from the root
    return maxVal;
}

// -----------------------------------------------------------------------------
// Function: heapSort()
// Purpose : Sort an array in ascending order using Heap Sort algorithm
// -----------------------------------------------------------------------------
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build a max heap from the input array
    // Start heapifying from the last non-leaf node down to the root

    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one from the heap
    // Move the current root (maximum) to the end, then reduce heap size by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);    // Move current max to the end of array
        heapify(arr, i, 0);      // Re-heapify the remaining heap (excluding sorted part)
    }
}

// -----------------------------------------------------------------------------
// Main function: Demonstrates all heap operations and Heap Sort
// -----------------------------------------------------------------------------
int main() {
    vector<int> heap;

    // -------------------- INSERTION DEMO --------------------
    insertHeap(heap, 10);
    insertHeap(heap, 20);
    insertHeap(heap, 5);
    insertHeap(heap, 30);
    insertHeap(heap, 25);

    cout << "Heap elements after insertion: ";
    for (int x : heap) cout << x << " ";
    cout << "\n";

    // -------------------- EXTRACTION DEMO --------------------
    cout << "Extracted max: " << extractMax(heap) << "\n";

    cout << "Heap after extraction: ";
    for (int x : heap) cout << x << " ";
    cout << "\n";

    // -------------------- HEAP SORT DEMO --------------------
    vector<int> arr = {4, 10, 3, 5, 1};

    cout << "\nOriginal array: ";
    for (int x : arr) cout << x << " ";

    heapSort(arr); // Perform heap sort

    cout << "\nSorted array (Heap Sort): ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}