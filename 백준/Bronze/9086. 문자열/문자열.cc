#include <iostream>
using namespace std;

int main() {

    int t;
    cin >> t;
    string s;
    for (int i=0; i<t; i++) {
        cin >> s;
        cout << s[0] << s[s.length()-1] << '\n';
    }
}