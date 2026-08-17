#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
private:
    int n;
    vector<long long> bit;

public:
    FenwickTree(int size) {
        this->n = size;
        bit.assign(n + 1, 0);
    }

    // Method 1: Build BIT in O(N) linear time from a 1-indexed vector
    void build(const vector<long long>& arr) {
        n = arr.size() - 1; // Assuming arr is 1-indexed
        bit.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            bit[i] += arr[i];
            int p = i + (i & -i); // Immediate parent in BIT
            if (p <= n) {
                bit[p] += bit[i]; // Propagate sum directly to parent
            }
        }
    }

    // Method 2: Point update in O(log N)
    void update(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    // Prefix sum query [1 ... idx] in O(log N)
    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    // Range sum query [l ... r] in O(log N)
    long long query_range(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    // 1-indexed array of 10 elements
    vector<long long> arr = {0, 3, 2, 5, 1, 4, 6, 7, 8, 2, 9};
    int n = arr.size() - 1;

    FenwickTree ft(n);
    ft.build(arr); // Linear O(N) build

    cout << "Prefix sum up to index 8: " << ft.query(8) << "\n";     // Output: 36
    cout << "Range sum from index 3 to 7: " << ft.query_range(3, 7) << "\n"; // Output: 23

    // Update index 5: add 10 to arr[5]
    ft.update(5, 10);
    cout << "New range sum [3..7] after update: " << ft.query_range(3, 7) << "\n"; // Output: 33

    return 0;
}