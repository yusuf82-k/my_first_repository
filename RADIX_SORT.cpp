#include<bits\stdc++.h>

using namespace std;

void countsort( vector<int>&a,int exp){
    int n=a.size();
    vector<int>output(n);
    int count[10]={0};
    for(auto x:a){
        int digit=(x/exp)%10;
        count[digit]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        int digit=(a[i]/exp)%10;
        output[count[digit]-1]=a[i];
        count[digit]--;
    }
    a=output;
}
void radixsort(vector<int>&a){
    int mx=*max_element(a.begin(),a.end());
    for(int exp=1;mx/exp>0;exp*=10){
        countsort(a,exp);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a)
    cin>>x;
    radixsort(a);
    for(int i=0;i<n;i++)
    cout<<a[i];
    cout<<endl;
    return 0;
}