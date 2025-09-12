#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
	cin >> s;
	int n = s.size();
	for(int i=0; i<n/2; i++) {
    	if(s[i] != s[n-1-i]) {
			 cout << 0 << '\n';
             return 0; 
		}
	}
	cout << 1 << '\n';
}   