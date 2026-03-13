#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[100001];
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    int result = 0;
    for(int i=1; i<=n; i++) {
        result = max(result, arr[n-i]*i);
    }
    cout << result;
}