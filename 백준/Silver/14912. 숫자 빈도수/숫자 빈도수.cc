#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, d;
    int cnt = 0;
    cin >> n >> d;

    for (int i=0; i<n; i++) {
        int tmp = i+1;
        while (tmp > 0) {
            if (tmp % 10 == d) cnt++;
            tmp /= 10;
        }
    }
    cout << cnt << '\n';

}
