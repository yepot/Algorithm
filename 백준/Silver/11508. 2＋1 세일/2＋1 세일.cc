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
    for(int i=0; i<n; i++) {
        cin >> V[i];
        sum+=V[i];
    }
        
    sort(V.rbegin(), V.rend());
    int k = V.size()/3;
    
    if(V.size()<3) {
        cout << sum << '\n';
        return 0;
    }
    for(int i=2; i<3*k; i+=3) {
        sum-=V[i];
    }
    cout << sum << '\n';
}
