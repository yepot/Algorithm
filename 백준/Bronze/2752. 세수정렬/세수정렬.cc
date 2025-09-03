#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int x = min({a, b, c});
    int y = max({a, b, c});
    cout << x << " " << a+b+c-x-y << " " << y;
}