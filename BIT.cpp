#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<long long> bit;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // Add value to A[index]
    void update(int index, long long value) {
        while (index <= n) {
            bit[index] += value;
            index += index & (-index);
        }
    }

    // Sum of A[1] + A[2] + ... + A[index]
    long long query(int index) {
        long long sum = 0;

        while (index > 0) {
            sum += bit[index];
            index -= index & (-index);
        }

        return sum;
    }
};

int main() {
    int n = 30;

    FenwickTree ft(n);

    // A = [1, 2, 3, ..., 30]
    for (int i = 1; i <= n; i++) {
        ft.update(i, i);
    }

    // Sum of first 10 elements
    cout << "Sum of first 10 elements = "
         << ft.query(10) << endl;

    return 0;
}