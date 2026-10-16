#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        vector<int>a;
        cin>>n>>s;
     //   s=s+'A';
        int counter=1;
        for(int i=1;i<=n;i++){
            if(s[i]!=s[i-1])
            {
                if(counter==1){
                    a.push_back(i-1);
                }
                counter=1;

            }
            else
            counter++;
        }


    }

    return 0;
}