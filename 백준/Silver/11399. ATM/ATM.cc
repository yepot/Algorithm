#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> V(n);
    int sum = 0;

    for(int i=0; i<n; i++) cin >> V[i];
    sort(V.begin(), V.end());

    for(int i=0; i<n; i++) sum += (V[i]*(n-i));
    cout << sum << '\n';
}