#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a[100001];
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    int m;
    cin >> m;
    while(m--) {
        int t;
        cin >> t;
        cout << binary_search(a, a+n, t) << '\n';
    }
}