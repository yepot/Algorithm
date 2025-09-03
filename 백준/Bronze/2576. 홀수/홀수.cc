#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    int min = 100;
    int sum = 0;

    for(int i=0; i<7; i++) {
        cin >> a;
        if(a%2 == 1) {
            sum += a;
            if(a < min) min = a;
        }
    }
    if(sum == 0) {
        cout << -1 << '\n';
        return 0;
    }
    cout << sum << '\n' << min << '\n';
}