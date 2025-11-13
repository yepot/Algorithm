#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> V(n*n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> V[i*n+j];
        }
    }
    sort(V.begin(), V.end(), greater<>());
    cout << V[n-1] << '\n';
}