#include <bits/stdc++.h>
using namespace std;

void mergeArray(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;

    // Merge the two arrays
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    // Copy remaining elements
    while (i < n1) arr[k++] = a[i++];
    while (j < n2) arr[k++] = b[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        mergeArray(arr, l, mid, r);
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
