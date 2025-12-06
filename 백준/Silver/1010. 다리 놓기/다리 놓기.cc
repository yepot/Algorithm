#include <iostream>
using namespace std;

long long comb(int m, int n) {
    if(n>m-n) n = m-n;
    long long result = 1;
    for(int i=0; i<n; i++) {
        result = result*(m-i);
        result = result/(i+1);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    int n, m;
    for(int i=0; i<t; i++) {
        cin >> n >> m;
        cout << comb(m, n) << '\n';
    }

}
