#include <bits\stdc++.h>
using namespace std;
int partition(vector<int> &a, int l, int r)
 
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}
void Quicksort(vector<int> &a, int l, int r)
{
    if (l < r)
    {
        int p = partition(a, l, r);
        Quicksort(a, l, p - 1);
        Quicksort(a, p + 1, r);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    for (int x : a)
        cout << x << " ";
    cout << endl;
    Quicksort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
