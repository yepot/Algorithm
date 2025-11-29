#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> V;
    
    int a,b;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        V.push_back({a,b});
    }
    sort(V.begin(), V.end());
    
    for(int i=0; i<n; i++) {
        cout << V[i].first << " " << V[i].second << "\n";
    }
}
