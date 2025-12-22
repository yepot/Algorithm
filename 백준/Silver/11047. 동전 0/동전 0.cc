#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    int arr[11] = {0, };
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int cnt = 0;
    int idx = n-1;
    while(k>0) {
        if(arr[idx]<=k) {
            cnt+=(k/arr[idx]);
            k-=(k/arr[idx])*arr[idx];
        }
        idx--;
    }
    cout << cnt << '\n';
}
