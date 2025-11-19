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
    for(int i=0; i<n; i++) cin >> V[i];

    sort(V.begin(), V.end(), greater<int>());
    for(int i=0; i<n; i++) {
        V[i]+=(i+1);
    }
    cout << *max_element(V.begin(), V.end())+1 << '\n';
}
