#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		Q.push(i+1);
	}
	while(Q.size()!=1) {
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	}
	cout << Q.front() << '\n';
}