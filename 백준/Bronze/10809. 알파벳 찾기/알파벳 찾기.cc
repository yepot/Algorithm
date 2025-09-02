#include <iostream>
using namespace std;

int main() {

    string s;
    cin >> s;
    int arr[26];
    for (int i=0; i<26; i++) {
        arr[i] = -1;
    }
    for (int i=s.length()-1; i>=0; i--) {
        arr[(int)s[i]-97] = i;
    }
    for (int i=0; i<26; i++) {
        cout << arr[i] << " ";
    }
}