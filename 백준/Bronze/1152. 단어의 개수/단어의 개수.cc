#include <iostream>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);
    istringstream iss(s);

    string word;
    int cnt = 0;
    while (iss >> word) cnt++;
    cout << cnt << '\n';
}