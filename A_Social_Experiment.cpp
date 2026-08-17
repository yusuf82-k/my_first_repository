#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << n << endl;
    } 
    else {
        if (n % 2 == 0) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}