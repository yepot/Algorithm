#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
	cin >> n;
	queue<int> Q;
	string st;
	for(int i=0; i<n; i++) {
		cin >> st;
		if(st=="push") {
			int x;
			cin >> x;
			Q.push(x);
		}
		else if(st=="front") {
			if(Q.empty()) cout << -1 << '\n';
			else cout << Q.front() << '\n';
		}
		else if(st=="back") {
			if(Q.empty()) cout << -1 << '\n';
			else cout << Q.back() << '\n';
		}
		else if(st=="pop") {
			if(Q.empty()) cout << -1 << '\n';
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if(st=="size") cout << Q.size() << '\n';
		else if(st=="empty") {
			if(Q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}   