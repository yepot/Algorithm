#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<int> S;
	string result;
	int k;
	int j = 1;
	for(int i=0; i<n; i++) {
		cin >> k;
		while(j<=k) {
			S.push(j++);
			result += "+\n";
		}
		if(!S.empty() && S.top()==k) {
				S.pop();
				result += "-\n";
		}
		else {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << result << '\n';
}