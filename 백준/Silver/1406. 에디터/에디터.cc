#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
	cin >> s;
	list<char> L;
	for(auto i : s) L.push_back(i);
	list<char>::iterator t = L.end();

	int m;
	cin >> m;
	for(int i=0; i<m; i++) {
		char c;
		cin >> c;
		if(c=='L') {
			if(t!=L.begin()) t--;
		}
		else if(c=='D') {
			if(t!=L.end()) t++;
		}
		else if(c=='B') {
			if(t!=L.begin()){
				t--;
				t = L.erase(t);
			}
		}
		else if(c=='P') {
			char add;
			cin >> add;
			L.insert(t, add);
		}
	}
	for(auto i : L) cout << i;
}   