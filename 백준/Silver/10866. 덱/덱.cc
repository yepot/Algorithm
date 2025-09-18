#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
	cin >> n;
	deque<int> DQ;
	string st;
	for(int i=0; i<n; i++) {
		cin >> st;
		if(st=="push_front") {
			cin >> x;
			DQ.push_front(x);
		}
		else if(st=="push_back") {
			cin >> x;
			DQ.push_back(x);
		}
		else if(st=="front") {
			if(DQ.empty()) cout << -1 << '\n';
			else cout << DQ.front() << '\n';
		}
		else if(st=="back") {
			if(DQ.empty()) cout << -1 << '\n';
			else cout << DQ.back() << '\n';
		}
		else if(st=="pop_front") {
			if(DQ.empty()) cout << -1 << '\n';
			else {
				cout << DQ.front() << '\n';
				DQ.pop_front();
			}
		}
		else if(st=="pop_back") {
			if(DQ.empty()) cout << -1 << '\n';
			else {
				cout << DQ.back() << '\n';
				DQ.pop_back();
			}
		}
		else if(st=="size") cout << DQ.size() << '\n';
		else if(st=="empty") {
			if(DQ.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}   