#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> V(n);
    for(int i=0; i<n; i++) {
        cin >> V[i];
    }
    sort(V.begin(), V.end());

    int m;
    cin >> m;
    int a;
    for(int i=0; i<m; i++) {
        cin >> a;
        if(binary_search(V.begin(), V.end(), a)) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    
}
