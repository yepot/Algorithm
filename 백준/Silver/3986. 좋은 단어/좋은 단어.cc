#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int cnt = 0;
	for(int i=0; i<n; i++) {
		stack<char> st;
		string s;
		cin >> s;
		for(auto a : s) {
			if(!st.empty() && a==st.top()) st.pop();
			else st.push(a);
		}
		if(st.empty()) cnt++;
	}
    cout << cnt << '\n';
}