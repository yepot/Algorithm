#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> V(3*n);
    for(int i=0; i<3*n; i++) cin >> V[i];
    sort(V.begin(), V.end());

    cout << V[2*n-1]-V[n] << '\n';
}
