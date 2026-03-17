#include <iostream>
#include <algorithm>
using namespace std;

vector<int> state(1000001, true);
void slave(int n) {
    state[1] = false;
    for(int i=2; i*i<=n; i++) {
        if(!state[i]) continue;
        for(int j=2*i; j<=n; j+=i) {
            state[j]=false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    slave(n);
    for(int i=m; i<=n; i++) {
        if(state[i]) cout << i << '\n';
    }
}