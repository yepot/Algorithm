#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int a[500001];
    int b[500001];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+m);

    vector<int> result;
    for(int i=0; i<n; i++) {
        if(binary_search(b, b+m, a[i])) continue;
        result.push_back(a[i]);
    }

    cout << result.size() << '\n';
    for(int i=0; i<result.size(); i++) cout << result[i] << ' ';
}