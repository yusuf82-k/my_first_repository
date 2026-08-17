#include<bits\stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        vector<int> a(n);
        for(auto &x : a) 
        cin >> x;

        set<int> prev, total;
        int part_cnt = 1;
         prev.insert(a[0]);
         total=prev;
        for(int i = 1; i < n; i++) {
            total.insert(a[i]);
            if(prev.count(a[i])) {
                prev.erase(a[i]);
            }

            if(prev.size() == 0) {
                part_cnt++;
                prev = total;
            }
        }

        cout << part_cnt << "\n";
    }

    return 0;
}