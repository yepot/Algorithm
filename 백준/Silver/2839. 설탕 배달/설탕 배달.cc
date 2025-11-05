#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int a=n/5; a>=0; a--) {
        for(int b=n/3; b>=0; b--) {
            if(3*b+5*a==n) {
                cout << a+b << '\n';
                return 0;
            }
        }        
    }
    cout << -1 << '\n';
}