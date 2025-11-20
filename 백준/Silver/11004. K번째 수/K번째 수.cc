#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> V(n);
    for(int i=0; i<n; i++) cin >> V[i];
    sort(V.begin(), V.end());
    cout << V[k-1] << '\n';
}
