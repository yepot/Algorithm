#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> V;
    int k;
    for(int i=0; i<n; i++) {
        cin >> k;
        V.push_back(k);
    }
    for(int i=0; i<m; i++) {
        cin >> k;
        V.push_back(k);
    }
    sort(V.begin(), V.end());
    for(int i=0; i<V.size(); i++) cout << V[i] << ' ';

}