#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    int comb[1001][1001];
    for(int i=1; i<=1000; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int j=1; j<i; j++) {
            comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%10007;
        }
    }
    cout << comb[n][k];
}