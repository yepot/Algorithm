#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[1000001] = {0};
    int a[1000001];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(x-a[i]>0 && arr[x-a[i]]) cnt++;
        arr[a[i]] = 1;
    }
    cout << cnt << '\n';
}   