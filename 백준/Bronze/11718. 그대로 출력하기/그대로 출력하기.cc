#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (1) {
        getline(cin, s);
        cout << s << '\n';
        if (s=="") break;
    }
    return 0;
}