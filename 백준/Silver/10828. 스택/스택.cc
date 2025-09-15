#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
	cin >> n;
	stack<int> S;
	string st;
	for(int i=0; i<n; i++) {
		cin >> st;
		if(st=="push") {
			int x;
			cin >> x;
			S.push(x);
		}
		else if(st=="top") {
			if(S.empty()) cout << -1 << '\n';
			else cout << S.top() << '\n';
		}
		else if(st=="pop") {
			if(S.empty()) cout << -1 << '\n';
			else {
				cout << S.top() << '\n';
				S.pop();
			}
		}
		else if(st=="size") cout << S.size() << '\n';
		else if(st=="empty") {
			if(S.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}   