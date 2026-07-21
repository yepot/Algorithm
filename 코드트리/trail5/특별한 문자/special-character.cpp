#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Please write your code here.
    string str;
    cin >> str;

    unordered_map<char, int> m;

    for(int i=0; i<str.length(); i++) {
        m[str[i]]++;
    }

    for(int i=0; i<str.length(); i++) {
        if(m[str[i]] == 1) {
            cout << str[i];
            return 0;
        }
    }
    cout << "None";
    return 0;
}