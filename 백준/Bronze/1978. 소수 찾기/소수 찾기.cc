#include <iostream>
using namespace std;

bool isprime(int k) {
    if(k==1) return 0;
    for(int i=2; i*i<=k; i++) {
        if(k%i==0) return 0;
    }
    return 1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int cnt = 0;
    int k;
    for(int i=0; i<n; i++) {
        cin >> k;
        if(isprime(k)) cnt++;
    }

    cout << cnt;
}