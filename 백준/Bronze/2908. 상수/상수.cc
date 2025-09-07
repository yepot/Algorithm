#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a ,b;
    cin >> a >> b;

    int tmp = a[0];
    a[0] = a[2];
    a[2] = tmp;
    tmp = b[0];
    b[0] = b[2];
    b[2] = tmp;
    
    if (a<b) cout << b;
    else cout << a;
}