#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int arr[500001];
    
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int m;
    cin >> m;
    for(int i=0; i<m; i++) {
        int tmp;
        cin >> tmp;
        cout << binary_search(arr, arr+n, tmp) << ' ';
    }
}