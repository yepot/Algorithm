#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> V(n);
    for(int i=0; i<n; i++) cin >> V[i];
    
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    for(int i=0; i<V.size(); i++) cout << V[i] << " ";
}
